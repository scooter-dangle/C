#include <stdio.h>
 
int main() {
 int i = 0;
 
 // POINTER MANIPULATION WITH A SINGLE INTEGER
 // make an int and an int* variable
 int someInteger = 10;
 int* pSomeInteger = NULL; // memory address 0
 
 // display the contents of the int and int* variables
 printf("The value in someInteger is: %d\n", someInteger);
 printf("The value in pSomeInteger is: %d\n\n", pSomeInteger);
 
 // point the pointer to the integer
 pSomeInteger = &someInteger;
 
 // display the memory address of the integer and the value in the pointer
 printf("The memory address of someInteger is: %x\n", &someInteger);
 printf("The value in the pointer is: %x\n\n", pSomeInteger);
 
 // display the contents of the int through the pointer
 printf("The value in someInteger is: %d\n\n", *pSomeInteger);
 
 // change the value in someInteger through the pointer
 *pSomeInteger = 20;
 
 // display the contents of the int and the dereference of the pointer
 printf("The value in someInteger is: %d\n", someInteger);
 printf("The value of the dereferenced pSomeInteger is: %d\n\n", *pSomeInteger);
 
 // POINTER MANIPULATION WITH AN ARRAY OF INTEGERS
 // make an array of integers
 int someIntArray[5] = {10, 20, 30, 40, 50};
 
 // display the contents of the array
 printf("The array contains: ");
 for(i = 0; i < 5; i++) {
 printf("%d ", someIntArray[i]);
 }
 printf("\n\n");
 
 // point the pointer at the array
 pSomeInteger = someIntArray;
 
 // display the contents of the array through the pointer (pointer syntax)
 printf("The array contains: ");
 for(i = 0; i < 5; i++) {
 printf("%d ", *pSomeInteger);
 pSomeInteger++;
 }
 printf("\n\n");
 
 // reinitialize the pointer
 pSomeInteger = someIntArray;
 
 // display the contents of the array through the pointer (array syntax)
 printf("The array contains: ");
 for(i = 0; i < 5; i++) {
 printf("%d ", pSomeInteger[i]);
 }
 printf("\n\n");
 
 // note that we do not need to reinitialize the pointer
 
 // double the size of each element in the array through the pointer
 for(i = 0; i < 5; i++) {
 *pSomeInteger *= 2;
 pSomeInteger++;
 }
 
 // reinitialize the pointer
 pSomeInteger = someIntArray;
 
 // display the contents of the array one final time
 // display the contents of the array through the pointer (array syntax)
 printf("The array contains: ");
 for(i = 0; i < 5; i++) {
 printf("%d ", pSomeInteger[i]);
 }
 printf("\n\n");
 
 return 0;
}

