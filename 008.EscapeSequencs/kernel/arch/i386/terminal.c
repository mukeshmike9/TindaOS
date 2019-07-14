#include "vga.h"
#include "../../libc/include/io.h"
#include "../../libc/include/string.h"

static const ssize_t VGA_WIDTH = 80;
static const ssize_t VGA_HEIGHT = 25;
static const uint16_t FRAME_BUFFER_PORT_COMMAND = 0x03D4;
static const uint16_t FRAME_BUFFER_PORT_DATA = 0x03D5;

//14 tells the framebuffer to expect the highest 8 bits of the position
static const uint8_t FRAME_BUFFER_HIGHER_8_BITS_POSITION = 14;

//15 tells the framebuffer to expect the lowest 8 bits of the position
static const uint8_t FRAME_BUFFER_LOWER_8_BITS_POSITION = 15;

static uint16_t *const VGA_MEMORY = (uint16_t *)0x0B8000;

static ssize_t terminalRow;
static ssize_t terminalColoumn;
static uint8_t terminalColor;
static uint16_t *terminalBuffer;

void terminalWriteString(char *string);

static void setCursor()
{
    size_t index = (terminalColoumn * VGA_WIDTH) + terminalRow;
    outb(FRAME_BUFFER_PORT_COMMAND, FRAME_BUFFER_HIGHER_8_BITS_POSITION);
    outb(FRAME_BUFFER_PORT_DATA, index >> 8);
    outb(FRAME_BUFFER_PORT_COMMAND, FRAME_BUFFER_LOWER_8_BITS_POSITION);
    outb(FRAME_BUFFER_PORT_DATA, index);
}

void terminalClear()
{
    for (ssize_t y = 0; y < VGA_HEIGHT; y++)
    {
        for (ssize_t x = 0; x < VGA_WIDTH; x++)
        {
            const size_t index = (y * VGA_WIDTH) + x;
            terminalBuffer[index] = vga_entry(' ', terminalColor);
        }
    }

    terminalRow = 0;
    terminalColoumn = 0;
}

void scroll()
{
    memcpy(terminalBuffer, &terminalBuffer[VGA_WIDTH], (VGA_WIDTH * (VGA_HEIGHT - 1)) * 2);
    terminalColoumn--;
    memset(&terminalBuffer[terminalColoumn * VGA_WIDTH], 0, VGA_WIDTH * 2);
}

void terminalInit(void)
{
    terminalRow = 0;
    terminalColoumn = 0;

    terminalColor = vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
    terminalBuffer = VGA_MEMORY;

    terminalClear();
    setCursor();
}

void terminalWriteChar(char c)
{
    size_t index = (terminalColoumn * VGA_WIDTH) + terminalRow;

    switch (c)
    {
    case '\n':
        terminalRow = -1;
        terminalColoumn++;
        break;
    case '\t':
        terminalWriteString("    ");
        break;
    case '\b':
        terminalBuffer[index--] = vga_entry(' ', terminalColor);
        terminalRow -= 2;
        if (terminalRow == -2)
        {
            terminalRow = -1;
        }
        break;
    default:
        terminalBuffer[index] = vga_entry(c, terminalColor);
    }

    if (++terminalRow == VGA_WIDTH)
    {
        terminalRow = 0;
        if (++terminalColoumn == VGA_HEIGHT)
        {
            scroll();
        }
    }
    setCursor();
}

void terminalWriteString(char *string)
{
    for (size_t i = 0; string[i] != '\0'; i++)
    {
        terminalWriteChar(string[i]);
    }
}