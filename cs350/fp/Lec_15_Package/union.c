// CS 350, Spring 2019
//
// union.c: Illustrate the difference between unions and structs
//
// Illinois Institute of Technology, (c) 2019, James Sasaki

#include <stdio.h>

// Declare struct i_then_f to be a structure with an int
// and float field.  Declare union i_or_f to be a union
// with an int or float field.
//
struct i_then_f {
	int i;
	float f;
};  // <-- note semicolon here

union i_or_f {
	int i;
	float f;
};  // <-- note semicolon here

// Show how struct and union field addresses differ:
// struct fields are laid out one after another;
// union fields are laid out on top of each other.
//
int main(void) {
	struct i_then_f x;
	union  i_or_f y;

    printf("addresses of x: %p, x.i: %p, x.f: %p\n", &x, &x.i, &x.f);
    printf("addresses of y: %p, y.i: %p, y.f: %p\n", &y, &y.i, &y.f);

    y.i = 123446;
    y.f = 0.0;    // overwrites the bits for y.i
    
    printf("values of y.i: %d, y.f: %f\n", y.i, y.f);
    printf("y.i == 123456?: %d\n", y.i == 123456);
	return 0;
}

/*
OUTPUT:
addresses of x: 0x7fff5793d900, x.i: 0x7fff5793d900, x.f: 0x7fff5793d904
addresses of y: 0x7fff5793d8f8, y.i: 0x7fff5793d8f8, y.f: 0x7fff5793d8f8
values of y.i: 0, y.f: 0.000000
y.i == 123456?: 0

 */