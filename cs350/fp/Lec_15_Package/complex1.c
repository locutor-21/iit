// CS 350, Spring 2019
//
// complex1.c: Functions on complex number structures
//
// Illinois Institute of Technology, (c) 2019, James Sasaki

#include <stdio.h>

// In version 1, we declare and use a structure named
// complex and manipulate its fields using variable.field
// syntax

// Declare struct complex to be a structure
// with real and imaginary fields
//
struct complex {
	double real;
	double imag;
};  // <-- note semicolon here

// Create and manipulate a struct complex value
//
int main(void) {
	struct complex val;
	val.real = 1.1;
	val.imag = 2.2;
	printf("%f + %f i\n", val.real, val.imag);
	return 0;
}
