#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t *const VGA_MEMORY = (uint16_t *)0x0B8000;

static size_t terminalRow;
static size_t terminalColoumn;
static uint8_t terminalColor;
static uint16_t *terminalBuffer;

void terminalInit(void)
{
    terminalRow = 0;
    terminalColoumn = 0;

    terminalColor = vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
    terminalBuffer = VGA_MEMORY;

    for (size_t y = 0; y < VGA_HEIGHT; y++)
    {
        for (size_t x = 0; x < VGA_WIDTH; x++)
        {
            const size_t index = (y * VGA_WIDTH) + x;
            terminalBuffer[index] = vga_entry(' ', terminalColor);
        }
    }
}

void terminalWriteChar(char c)
{
    const size_t index = (terminalColoumn * VGA_WIDTH) + terminalRow;
    terminalBuffer[index] = vga_entry(c, terminalColor);

    if (++terminalRow == VGA_WIDTH)
    {
        terminalRow = 0;
        if (++terminalColoumn == VGA_HEIGHT)
        {
            terminalColoumn = 0;
        }
    }
}

void terminalWriteString(char *string)
{
    for (size_t i = 0; string[i] != '\0'; i++)
    {
        terminalWriteChar(string[i]);
    }
}