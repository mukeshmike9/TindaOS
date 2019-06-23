
#define BG_BLACK 0x00
#define FG_WHITE 0xF0

void _kmain()
{
	char *video_memory = (char *)0xb8000;

	video_memory[0] = 'T';
	video_memory[1] = BG_BLACK | FG_WHITE;
	video_memory[2] = 'I';
	video_memory[4] = 'N';
	video_memory[6] = 'D';
	video_memory[8] = 'A';
	video_memory[10] = ' ';
	video_memory[12] = 'O';
	video_memory[14] = 'S';
	while (1)
	{
		;
	}
}
