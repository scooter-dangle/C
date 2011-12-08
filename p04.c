#include <stdlib.h>
#include <stdio.h>
#include "p04_preprocessor.h"
#include "p04_cipher.c"
#include "p04_file_io.c"
#include "p04_user_io.c"




int main()
{
	int run = NUM_RUNS;
	int user_input;

	while (run > 0)
	{
		print_menu();

		scanf("%i", &user_input);
		flush();
		print_line();

		switch(user_input) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				run = 0;
				print_exit();
				break;
			default:
				run--;
				print_invalid_input();
		}
	}

	return 0;
}


