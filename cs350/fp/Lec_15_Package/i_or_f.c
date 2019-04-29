// CS 350, Spring 2019
//
// i_or_f.c: Example of union
//
// Illinois Institute of Technology, (c) 2019, James Sasaki

#include <stdio.h>
#include <stdio.h>

// An i_or_f union has either an
// i field or a f field but we
// shouldn't treat it has having
// both
union i_or_f { int i ; float f ; };

// Access i_or_f value as an int then
// do bad thing of accessing it as a
// float?  Which float?  Dpends on
// what bits are sitting there in
// memory: 0x00000011 is a very small
// floating-point number
//
int main(void) {
	union i_or_f x;
	x.i = 17;
	printf("x.i as hex: %x\n", x.i);
	printf("x.i = %d\n", x.i);
	printf("x.f = %e\n", x.f);
	return 0;
}