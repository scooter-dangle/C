#include <stdio.h>

#define MIN_INPUT -1000
#define MAX_INPUT 1000

// Prototypes
void flush();
int calculate(int, int, char*, float*, int);

int main()
{
	// Variable declarations - qjq
	// Input
	printf("NOTE: You must enter integer operands between %i and ", MIN_INPUT );
	printf("%i\n\n",                                                MAX_INPUT );

	printf("Please enter the first operand: "                                 );
	int operand1; //qjq
	scanf ("%i",                                                    &operand1 );
	flush ();

	printf("Please enter the second operand: "                                );
	int operand2; //qjq
	scanf ("%i",                                                    &operand2 );
	flush ();

		// Input validation

		// Input operator
	printf("\n\n"                                                             );
	printf("Please select an operation to place in the blank space:\n"        );
	printf("%i _ %i =\n\n",                                operand1, operand2 );

	printf("A - Addition      \n"                                             );
	printf("S - Subtraction   \n"                                             );
	printf("M - Multiplication\n"                                             );
	printf("D - Division      \n"                                             );
	printf("O - Modulus       \n"                                             );
	printf(":"                                                                );
	char operator; //qjq
	scanf ("%c",                                                    &operator );
	flush ();

	// Calcurlashins
	float result; //qjq
	calculate( operand1, operand2, &operator, &result, 3 );
	printf("%f", result);


	// Output
	printf(""                                                                 );
	printf(""                                                                 );

	
	return 0;
}

// This function flushes stdin (especially for use following scanf())
void flush()
{
	char extraChar;
	do {
		scanf("%c", &extraChar);
	} while ( extraChar != '\n' && extraChar != EOF );
}

int calculate(int operand1, int operand2, char* operator, float* result, int tries_left)
{
	if (tries_left <= 0) {
		printf("Program exiting without calculation\n"                        );
		return 0;
	}
	switch(*operator) {
		case 'a':
		case '+':
			printf("You used a non-standard input. The program will attempt\n");
			printf("to match it to the correct operation, but in the future\n");
			printf("you should should use one of the listed inputs.\n"        );
		case 'A':
			printf("A - Addition      \n"                                     );
			*result = ((float) operand1) + ((float) operand2);
			break;
		case 's':
		case '-':
			printf("You used a non-standard input. The program will attempt\n");
			printf("to match it to the correct operation, but in the future\n");
			printf("you should should use one of the listed inputs.\n"        );
		case 'S':
			printf("S - Subtraction   \n"                                     );
			break;
		case 'm':
		case '*':
		case 'x':
			printf("You used a non-standard input. The program will attempt\n");
			printf("to match it to the correct operation, but in the future\n");
			printf("you should should use one of the listed inputs.\n"        );
		case 'M':
			printf("M - Multiplication\n"                                     );
			break;
		case 'd':
		case '/':
			printf("You used a non-standard input. The program will attempt\n");
			printf("to match it to the correct operation, but in the future\n");
			printf("you should should use one of the listed inputs.\n"        );
		case 'D':
			printf("D - Division      \n"                                     );
			break;
		case 'o':
		case '%':
			printf("You used a non-standard input. The program will attempt\n");
			printf("to match it to the correct operation, but in the future\n");
			printf("you should should use one of the listed inputs.\n"        );
		case 'O':
			printf("O - Modulus       \n"                                     );
			break;
		default:
			printf("The program could not match your input to a supported "   );
			printf("operation.\n"                                             );
			printf("Please enter a valid input: "                             );
			scanf ("%c",                                            operator  );
			flush ();
			calculate(operand1, operand2, operator, result, tries_left-1);
	}
}
