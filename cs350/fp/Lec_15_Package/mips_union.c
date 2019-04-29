// CS 350, Spring 2019
//
// mips_union.c: Use union for different kinds of instruction formats.
//
// Illinois Institute of Technology, (c) 2019, James Sasaki

#include <stdio.h>

typedef unsigned char byte; // declare "byte" to mean "unsigned char"

struct R_Format { byte rs, rt, rd, shamt, funct; };
struct I_Format { byte rs, rt; short immediate; };
struct J_Format { unsigned int address; };

struct instruction {
    byte opcode;
    union {
        struct R_Format r_fmt;
        struct I_Format i_fmt;
        struct J_Format j_fmt;
    };
};

int main(void) {
    struct instruction instr;
    printf("Address of instr.opcode:          %p\n", &instr.opcode);
    printf("Address of instr.r_fmt:           %p\n", &instr.r_fmt);
    printf("Address of instr.i_fmt:           %p\n", &instr.i_fmt);
    printf("Address of instr.j_fmt:           %p\n", &instr.j_fmt);
    printf("\n");
    printf("Address of instr.r_fmt.rs:        %p\n", &instr.r_fmt.rs);
    printf("Address of instr.r_fmt.rt:        %p\n", &instr.r_fmt.rt);
    printf("Address of instr.r_fmt.rd:        %p\n", &instr.r_fmt.rd);
    printf("Address of instr.r_fmt.shamt:     %p\n", &instr.r_fmt.shamt);
    printf("Address of instr.r_fmt.funct:     %p\n", &instr.r_fmt.funct);
    printf("\n");
    printf("Address of instr.i_fmt.rs:        %p\n", &instr.i_fmt.rs);
    printf("Address of instr.i_fmt.rt:        %p\n", &instr.i_fmt.rt);
    printf("Address of instr.i_fmt.immediate: %p\n", &instr.i_fmt.immediate);
    printf("\n");
    printf("Address of instr.j_fmt.address:   %p\n", &instr.j_fmt.address);
    return 0;
}

/* OUTPUT:
Address of instr.opcode:          0x7fff5893b910
Address of instr.r_fmt:           0x7fff5893b914
Address of instr.i_fmt:           0x7fff5893b914
Address of instr.j_fmt:           0x7fff5893b914

Address of instr.r_fmt.rs:        0x7fff5893b914
Address of instr.r_fmt.rt:        0x7fff5893b915
Address of instr.r_fmt.rd:        0x7fff5893b916
Address of instr.r_fmt.shamt:     0x7fff5893b917
Address of instr.r_fmt.funct:     0x7fff5893b918

Address of instr.i_fmt.rs:        0x7fff5893b914
Address of instr.i_fmt.rt:        0x7fff5893b915
Address of instr.i_fmt.immediate: 0x7fff5893b916

Address of instr.j_fmt.address:   0x7fff5893b914
*/
