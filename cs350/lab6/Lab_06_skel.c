// CS 350, Spring 2019
//
// Lab 6 -- Selecting bitstring fields (Solution)
//
// Illinois Institute of Technology, (c) 2019, James Sasaki
//

// Here is pseudocode for the program
//
// Print out a message saying this is a program for CS 350 Lab 6,
// and include your name.
//
// Read a hexadecimal integer (as a 32-bit integer).
// (No leading 0x should be allowed.  The user should
// enter a newline afte the integer.)  Below, say the
// integer is called val.
//
// while the integer val is nonzero
//	   Prompt for and read two integers specifying low
//		    and high endpoints within 32-bit string.
//     Select bits high..low of val
//          (bit 31 is at left end, bit 0 at right)
//     Print out val (in hex), high and low (as integers),
//        and the selected bitstring (in hex).
//	   Prompt the user for another value for val and read it in
//         (again, in hex).
//
// After the loop, print a message saying that the program
// is ending


// General instructions (for the skeleton):
// Replace all STUB code and comments with actual code.  
//
#include <stdio.h>
#include <strings.h>   // if you need string library

int main () {
	printf("CS 350 Lab 6 for %s\n\n", "*** Solution ***");

	// Prompt for and read in the first hex integer value to process.
	//
	unsigned int val = 0;
    printf("Enter a value in hex (0 to quit): ");
	scanf("%x", &val);

	// Loop until the value to inxpect is zero.
	//
	while (val != 0) {
		int right_end, left_end;  // desired endpoints of substring
		char type;

		// Read the endpoints and selection type.  We initialize
		// to bad values in case the fscanf fails.
		//
		//*** STUB *** prompt for and read in the two endpoints

		// If the endpoints are bad, complain and go on to the next value
		//
		if // *** STUB *** check that the left endpoint is to the left
		   // of the right endpoint and both endpoints are in the range 0..31
		}

		// Otherwise process this input
		else {
		    int selection_length; // *** STUB *** set to distance between endpints
		    unsigned int mask; // *** STUB *** (2^selection length) - 1, shifted left
		                       // to the correct position.

		    unsigned int selection = val & mask;
		    // *** STUB *** shift selection to right end of string

			// Print val, the endpoints, and the selected bitstring
			printf("%x[%d:%d] = %x\n", val, left_end, right_end, selection);
		}

		// Prompt for and read in the next hex integer.
		//
		// *** STUB ****
	}
	printf("Quitting.\n");
	return 1;
}
