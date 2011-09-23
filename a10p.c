#include <stdio.h>

#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

#define NO_INVERSE -1
#define ERROR -2

#define A 19
#define B 4
#define ALPHABET_SIZE 26

#define ASCII_OFFSET 97
#define BUFFER_SIZE 1000

// Prototypes
char numToLetter(int);
int letterToNum(char);
int EncryptString(char*, int, int, int);
int DecryptString(char*, int, int, int);
int ModularInverse(int, int);
int IsPrime(int);
int CoprimeTest(int, int);


int main()
{
	char cleanString[BUFFER_SIZE] = "thequickbrownfoxjumpedoverthelazydogs";


	printf("Before encryption, the string contains:\n");
	puts(cleanString);
	printf("\n");


	EncryptString(cleanString, A, B, ALPHABET_SIZE);


	printf("After encryption, the string contains:\n");
	puts(cleanString);
	printf("\n");


	DecryptString(cleanString, A, B, ALPHABET_SIZE);


	printf("After decryption, the string contains:\n");
	puts(cleanString);
	printf("\n");

	
	return 0;
}

// Function implementations
char numToLetter(int number) {
	char letter = number + 97;
	return letter;
}

int letterToNum(char letter) {
	int number = letter - 97;
	return number;
}

int EncryptString(char* encryptMe, int a, int b, int n) {
	if (!CoprimeTest(a, b)) {
		return FALSE;
	}
	int i;
	for (i = 0; encryptMe[i] >= 97 && encryptMe[i] < 123; i++) {
		int number = letterToNum(encryptMe[i]);
		number = ((number*a) + b) % n;
		while(number<0) number = (number + n) % n; // not really necessary
												   // here, but makes function
												   // easier to re-use
		encryptMe[i] = numToLetter(number);
	}
	if (encryptMe[i]==0) { // Checking that next character is string
						   // terminator
		return TRUE;
	}
	else {
		return FALSE;
	}
}


int DecryptString(char* decryptMe, int a, int b, int n) {
	if (!CoprimeTest(a, b)) {
		return FALSE;
	}
	int i;
	int a_inv = ModularInverse(a, n);
	for (i = 0; decryptMe[i] >= 97 && decryptMe[i] < 123; i++) {
		int number = letterToNum(decryptMe[i]);
		number = (a_inv * (number-b)) % n;
		while(number<0) number = (number + n) % n; // not really necessary
												   // here, but makes function
												   // easier to re-use
		decryptMe[i] = numToLetter(number);
	}
	if (decryptMe[i]==0) { // Checking that next character is string
						   // terminator
		return TRUE;
	}
	else {
		return FALSE;
	}
}


int ModularInverse(int target, int mod) {
	int remainder[3];		// Started based on wikipedia pseudocode
	int auxiliary[3] = { 0, 1 };
	return target;
}


int IsPrime(int amIPrime) {
	return TRUE;
}


int CoprimeTest(int numOne, int numTwo) {
	return TRUE;
}
