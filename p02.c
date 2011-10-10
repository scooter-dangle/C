#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_INPUT -1000
#define MAX_INPUT 1000

// Prototypes
void flush();
int exit_prog();
int operandInput(int*, int*);
int operandCheck(int*, int);
int operatorInput(int,int,char*);
char operatorCheck(char,int);
void nonStandardInput();
int calculate(float, float, char, float*);
void calculateCheck(char*);
int formatting_length(int,int,char,float);
float zero_catch(float);
int print_result(int,int,char,float);
int run_again();

int main()
{
	// Variable declarations - qjq
	int operand1; //qjq
	int operand2; //qjq
	char operator; //qjq
	float result; //qjq
	int status;
	// The following 2 lines are necessary so that the operands
	// do not accidentally start out with values that would pass the
	// validation tests.
	operand1 = MAX_INPUT + 1;
	operand2 = MAX_INPUT + 1;
	// End of variable declarations - qjq
	// Input (validations handled by input functions)
	status = 0;
	status = operandInput(&operand1, &operand2);
	if (status == 0) {
		status = operatorInput(operand1, operand2, &operator);
	}

	// Calcurlashins
	if (status == 0) {
		status = calculate( (float) operand1, (float) operand2, operator, &result );
	}

	// Output
	if (status == 0) {
		print_result( operand1, operand2, operator, result );
	} else {
		print_result( operand1, operand2, '0', result );
	}

	// Option to run program again
	status = run_again();
	if (status != 0) { return exit_prog(); }

	main();
}

// This function flushes stdin (especially for use following scanf())
void flush()
{
	char extraChar;
	do {
		scanf("%c", &extraChar);
	} while ( extraChar != '\n' && extraChar != EOF );
}

int exit_prog()
{
	printf("Program exiting.\n"                                               );
	return 0;
}

int operandInput(int* operand1, int* operand2)
{
	printf("NOTE: You must enter integer operands between %i and ", MIN_INPUT );
	printf("%i\n",                                                  MAX_INPUT );
	printf("\n"                                                               );

	printf("Please enter the first operand: "                                 );
	scanf ("%i", operand1);
	flush ();
	if (operandCheck(operand1, 2) != 0) { return 1; }

	printf("Please enter the second operand: "                                );
	scanf ("%i", operand2);
	flush ();
	if (operandCheck(operand2, 2) != 0) { return 1; }

	return 0;
}

int operandCheck(int* operand, int tries_left)
{
	if (*operand <= MAX_INPUT && *operand >= MIN_INPUT) {
		return 0;
	} else {
		printf("\n"                                                           );
		printf("Operand entered was not an integer in the acceptable range.\n");
		if (tries_left<=0) {
			printf("\n"                                                       );
			return 1;
		}
		printf("Please re-enter operand: "                                    );
		scanf ("%i", operand);
		flush ();
		printf("\n"                                                           );
		return operandCheck(operand, tries_left-1);
	}
}

int operatorInput(int operand1, int operand2, char* operator)
{
	printf("\n"                                                               );
	printf("\n"                                                               );
	printf("Please select an operation to place in the blank space:\n"        );
	printf("%i _ %i =\n",                                  operand1, operand2 );
	printf("\n"                                                               );
	printf("A - Addition      \n"                                             );
	printf("S - Subtraction   \n"                                             );
	printf("M - Multiplication\n"                                             );
	printf("D - Division      \n"                                             );
	printf("O - Modulus       \n"                                             );
	printf(":"                                                                );
	scanf ("%c", operator);
	flush ();
	*operator = operatorCheck(*operator, 2);
	if (*operator == 1) {
		return 1;
	}
	return 0;
}

char operatorCheck(char operator, int tries_left)
{
	switch(operator) {
		case 'A':
		case 'S':
		case 'M':
		case 'D':
		case 'O':
			return operator;

		case 'a':
		case '+':
			nonStandardInput();
			return 'A';

		case 's':
		case '-':
			nonStandardInput();
			return 'S';

		case 'm':
		case '*':
		case 'x':
			nonStandardInput();
			return 'M';

		case 'd':
		case '/':
			nonStandardInput();
			return 'D';

		case 'o':
		case '%':
			nonStandardInput();
			return 'O';

		default:
			printf("The program could not match your input to a supported "   );
			printf("operation.\n"                                             );
			printf("\n"                                                       );
			if (tries_left <= 0) {
				return 1;
			}
			printf("Please enter a valid input: "                             );
			scanf ("%c", &operator);
			flush ();
			return operatorCheck(operator, tries_left-1);
	}
}

void nonStandardInput()
{
	printf("\n"                                                               );
	printf("You used a non-standard input. The program will attempt\n"        );
	printf("to match it to the correct operation, but in the future\n"        );
	printf("you should should use one of the listed inputs.\n"                );
	printf("\n"                                                               );
}

int calculate(float operand1, float operand2, char operator, float* result)
{
	if (operand2 == 0) { calculateCheck(&operator); }
	switch(operator) {
		case 'A':
			*result = operand1 + operand2;
			break;
		case 'S':
			*result = operand1 - operand2;
			break;
		case 'M':
			*result = operand1 * operand2;
			break;
		case 'D':
			*result = operand1 / operand2;
			break;
		case 'O':
			*result = (int) operand1 % (int) operand2;
			if (*result < 0) {
				*result+= abs((int) operand2);
			}
			break;
		default:
			printf("Invalid input...program continuing without calculation.\n");
			return 1;
	}
	return 0;
}

void calculateCheck(char* operator)
{
	switch(*operator) {
		case 'D':
			printf("Error: Can't divide by 0.\n"                              );
			*operator = 0;
			break;
		case 'O':
			printf("Error: Can't have modulus of 0.\n"                        );
			*operator = 0;
			break;
		default:
			break;
	}
}

int formatting_length(int operand1, int operand2, char operator, float result)
{
	switch(operator) {
		case 'A':
		case 'S':
		case 'M':
		case 'O':
			return 6 + floor(log10(abs(zero_catch((float) operand1))) + 1) + floor(log10(abs(zero_catch((float) operand2))) + 1) + floor(log10(abs(zero_catch(result))) + 1) + ((int) (-copysign(0.5, operand1) + 0.5)) + ((int) (-copysign(0.5, operand2) + 0.5)) + ((int) (-copysign(0.5, result) + 0.5));
		case 'D':
			return 11 + floor(log10(abs(zero_catch((float) operand1))) + 1) + floor(log10(abs(zero_catch((float) operand2))) + 1) + floor(log10(abs(zero_catch(result))) + 1) + ((int) (-copysign(0.5, operand1) + 0.5)) + ((int) (-copysign(0.5, operand2) + 0.5)) + ((int) (-copysign(0.5, result) + 0.5));
	}
}

float zero_catch(float number)
{
	if (number == 0) return 1;
	return number;
}

int print_result(int operand1, int operand2, char operator, float result)
{
	int i;
	int length;
	switch(operator) { // Print fancily formatted line
		case 'A':
		case 'S':
		case 'M':
		case 'D':
		case 'O':
			printf("\n"                                                           );
			length = formatting_length(operand1, operand2, operator, result);
			for (i = 0; i < length; i++) { printf("%c",'-'); }
			printf("\n"                                                           );
	}

	switch(operator) {
		case 'A':
			printf("%i %c %i = %i\n", operand1, '+', operand2, (int) result);
			break;
		case 'S':
			printf("%i %c %i = %i\n", operand1, '-', operand2, (int) result);
			break;
		case 'M':
			printf("%i %c %i = %i\n", operand1, '*', operand2, (int) result);
			break;
		case 'D':
			printf("%i %c %i = %.4f\n", operand1, '/', operand2, result);
			break;
		case 'O':
			printf("%i %c %i = %i\n", operand1, '%', operand2, (int) result);
			break;
		default:
			printf("No result to output.\n"                                   );
			break;
	}
}

int run_again()
{
	char status;
	printf("\n"                                                               );
	printf("Run program again?\n"                                             );
	printf("(To run again, enter Y or y. To quit, enter any other key.)\n"    );
	printf(":"                                                                );
	scanf ("%c", &status);
	flush ();
	if (status == 'Y' || status == 'y') {
		printf("\n\n\n"                                                       );
		return 0;
	}
	return 1;
}


// Assigned Question Number 1:
//      9 %  2 = 1
//     -9 %  2 = 1
//      9 % -2 = 1
//     -9 % -2 = 1
