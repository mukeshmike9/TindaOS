#include "../include/kernel/terminal.h"

void _kmain()
{
	terminalInit();
	terminalWriteString("TINDA OS");
	while (1)
	{
		;
	}
}
