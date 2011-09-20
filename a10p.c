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
int EncryptString(char* encryptMe, int a, int b, int n) {
}


int DecryptString(char* decryptMe, int a, int b, int n) {
}


int ModularInverse(int target, int mod) {
}


int IsPrime(int amIPrime) {
}


int CoprimeTest(int numOne, int numTwo) {
}
