#include "../include/kernel/terminal.h"

void _kmain()
{
	terminalInit();
	terminalWriteString("TINDA OS");
	int i = 0;
	int timer = 1000000 / 24;
	unsigned int j = 0;
	while (1)
	{
		if ((i > 0x40 && i <= 0x5A) || (i >= 0x30 && i <= 0x39))
		{
			terminalWriteChar(i);
			for (int i = 0; i < timer; i++)
				;
		}

		i++;

		if (i > 0x5A)
		{
			i = 0x30;
			j++;
		}

		if (j == 60)
		{
			timer = timer * 32;
			j++;
		}

		if (j == 65)
		{
			terminalClear();
			timer = timer / 32;
			j = 0;
		}
	}
}
