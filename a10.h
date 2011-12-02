#include <stdio.h>

// Prototypes
char numToLetter(int);
int letterToNum(char);
int EncryptString(char*, int, int, int);
int DecryptString(char*, int, int, int);
int ModularInverse(int, int);
int IsPrime(int);
int CoprimeTest(int, int);


// int main()
// {
// 	char cleanString[BUFFER_SIZE] = "thequickbrownfoxjumpedoverthelazydogs";
// 
// 
// 	printf("Before encryption, the string contains:\n");
// 	puts(cleanString);
// 	printf("\n");
// 
// 
// 	EncryptString(cleanString, A, B, ALPHABET_SIZE);
// 
// 
// 	printf("After encryption, the string contains:\n");
// 	puts(cleanString);
// 	printf("\n");
// 
// 
// 	DecryptString(cleanString, A, B, ALPHABET_SIZE);
// 
// 
// 	printf("After decryption, the string contains:\n");
// 	puts(cleanString);
// 	printf("\n");
// 
// 	
// 	return 0;
// }

// Function implementations
char numToLetter(int number) {
	char letter = number + ASCII_OFFSET;
	return letter;
}

int letterToNum(char letter) {
	int number = letter - ASCII_OFFSET;
	return number;
}

int EncryptString(char* encryptMe, int a, int b, int n) {
	if (!CoprimeTest(a, n)) {
		return FALSE;
	}
	int i;
	for (i = 0; encryptMe[i] >= ASCII_OFFSET && encryptMe[i] < ASCII_OFFSET + ALPHABET_SIZE; i++) {
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
	if (!CoprimeTest(a, n)) {
		return FALSE;
	}
	int i;
	int a_inv = ModularInverse(a, n);
	for (i = 0; decryptMe[i] >= ASCII_OFFSET && decryptMe[i] < ASCII_OFFSET + ALPHABET_SIZE; i++) {
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
	int i;
	for (i = 1; i < mod; i++) {
		if (i * target % mod == 1) {
			target = i;
			i = mod;
		}
	}
	return target;
}


int IsPrime(int amIPrime) {
	return TRUE;
}


int CoprimeTest(int numOne, int numTwo) {
	// got the following from en.literateprograms.org
	int em;
	while (numTwo != 0) {
		em = numOne % numTwo;
		numOne = numTwo;
		numTwo = em;
	}
	if (numOne == 1) return TRUE;
	return FALSE;
}
