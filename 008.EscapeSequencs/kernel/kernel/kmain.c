#include "../include/kernel/terminal.h"

void _kmain()
{
	terminalInit();
	terminalWriteString("TINDA OS\nIs the\tBestO\b OS");
	while (1)
	{
	}
}
