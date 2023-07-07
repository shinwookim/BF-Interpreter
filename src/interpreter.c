#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#define TAPESIZE 30000

extern EMSCRIPTEN_KEEPALIVE void brainfuck(char *instr_ptr, char *input)
{
	/* Temporary Buffer to Hold Output (For Cleaner Output) */
	char buf[TAPESIZE];
	long buf_index = 0;
	memset(buf, '\0', TAPESIZE);

	/* Initialize Tape */
	uint8_t tape[TAPESIZE];
	memset(tape, 0, TAPESIZE);
	uint8_t *dataptr = &tape[0];

	int sem_bracket;
	char instr;

	while ((instr = *instr_ptr) != '\0')
	{
		switch (instr)
		{
		case '>': // Increment the data pointer by one
			dataptr++;
			break;
		case '<': // Decrement the data pointer by one
			dataptr--;
			break;
		case '+': // Increment the byte at the data pointer by one
			(*dataptr)++;
			break;
		case '-': // Decrement the byte at the data pointer by one
			(*dataptr)--;
			break;
		case '.': // Output the byte at the data pointer
			// printf("%c", *dataptr, buf);
			buf[buf_index] = *dataptr;
			buf_index++;
			break;
		case ',': // Accept one byte of input, storing its value in the byte at the data pointer
			printf("User Input Needed. Please Enter Character: \t");
			*dataptr = getchar();
			break;
		case '[':
			if (!*dataptr) // If the byte at the data pointer is zero,
			{			   // jump forward to the instruction after the matching ] instruction.
				instr_ptr++;
				while (true)
				{
					if (*instr_ptr == ']')
					{
						if (sem_bracket)
							sem_bracket--;
						else
							break;
					}
					else if (*instr_ptr == '[')
						sem_bracket++;
					instr_ptr++;
				}
			}
			break;
		case ']':
			if (*dataptr) // If the byte at the data pointer is nonzero,
			{			  // jump back to the instruction after the matching [ instruction.
				instr_ptr--;
				while (true)
				{
					if (*instr_ptr == '[')
					{
						if (sem_bracket)
							sem_bracket--;
						else
							break;
					}
					else if (*instr_ptr == ']')
						sem_bracket++;
					instr_ptr--;
				}
			}
			break;
		}
		instr_ptr++;
	}
	// printf("\e[1;1H\e[2J"); // Special ANSI escape code to clear terminal
	printf("%s\n", buf);
}
