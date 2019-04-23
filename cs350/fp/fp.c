// CS 350, Spring 2019
//
// Final Project
//
// Illinois Institute of Technology, (c) 2019, James Sasaki
//

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

struct R_Format { byte rs, rt, rd, shamt, funct; };
struct I_Format { byte rs, rt; short immediate; };
struct J_Format { unsigned int address; };

struct instruction{
	byte opcode;
	union {
		struct R_Format r_fmt;
		struct I_Format i_fmt;
		struct J_Format j_fmt;
	}
};
typedef struct instruction Instruction;

void num_of_instruc(FILE *fp);
void build_R_format(unsigned int bitstring, struct R_Format *instr);
void build_I_format(unsigned int bitstring, struct I_Format *instr);
void build_J_format(unsigned int bitstring, struct J_Format *instr);
void print_R_format(struct R_Format *instr);
void print_I_format(struct I_Format *instr);
void print_J_format(struct J_Format *instr);

int main(){
	printf("Spring 2019 - CS 350 Final Project for %s\n\n", "Pedro H Dias");

	///Opens file with the instructions
	char *datafile_name = "data.txt";
	FILE *datafile = fopen(datafile_name, "r");
	printf("Loading %s\n", datafile_name);
	if (!datafile){
		printf("; open failed; program ends\n");
		exit(EXIT_FAILURE);
	}

	///Opens file that will receive the output
	char *outputfile_name = "output.txt";
	FILE *output = fopen(outputfile_name, "w");

	///Declare variables
	int n, pos;
	unsigned int initial_address;
	unsigned int instr;
	Instruction* instr_list;
	
	//Calculates size of instr_list and allocates memory to it
	n = num_of_instruc(datafile);
	instr_list = malloc(n * sizeof(Instruction));
	printf("Read %d lines of data\n", n);

	///Read datafile for instructions
	pos = 0;
	while(fscanf(datafile)){
		fscanf(datafile, "%p\n", &instr);
		//set instr_list[pos]
		pos++;
	}

	///Prompt user for inital address
	printf("Enter program counter (hex digits):\n");
	scanf("%x", &initial_address);

	printf("Initial program counter = %p", initial_address);

	fclose(datafile);
	fclose(output);
	return 0;
}

void num_of_instruc(FILE *fp){
	int n = 0;
	char c;

	c = getc(fp);
	while(!feof(fp)){
		if (c == '\n')
			n++;
		c = getc(fp);
	}

	fseek(fp, 0, SEEK_SET);
	return n+1;
}

void build_R_format(unsigned int bitstring, struct R_Format *instr){

	unsigned int opcode = (bitstring & 11111100000000000000000000000000) >> 26;
	unsigned int rs =     (bitstring & 00000011111000000000000000000000) >> 21;
	unsigned int rt =     (bitstring & 00000000000111110000000000000000) >> 16;
	unsigned int rd =     (bitstring & 00000000000000001111100000000000) >> 11;
	unsigned int shamt =  (bitstring & 00000000000000000000011111000000) >> 6;
	unsigned int funct =  (bitstring & 00000000000000000000000000111111);

	instr -> opcode = ;
	instr -> rs = ;
	instr -> rt = ;
	instr -> rd = ;
	instr -> shamt = ;
	instr -> funct = ;
}

void build_I_format(unsigned int bitstring, struct I_Format *instr){

	unsigned int opcode = (bitstring & 11111100000000000000000000000000) >> 26;
	unsigned int rs =     (bitstring & 00000011111000000000000000000000) >> 21;
	unsigned int rt =     (bitstring & 00000000000111110000000000000000) >> 16;
	unsigned int immedi = (bitstring & 00000000000000001111111111111111);

	instr -> opcode = ;
	instr -> rs = ;
	instr -> rt = ;
	instr -> immediate = ;
}

void build_J_format(unsigned int bitstring, struct J_Format *instr){

	unsigned int opcode =  (bitstring & 11111100000000000000000000000000) >> 26;
	unsigned int address = (bitstring & 00000011111111111111111111111111);

	instr -> opcode = ;
	instr -> address = ;
}

void print_R_format(struct R_Format *instr){
	printf("%p   %4s %3s, %3s, %3s   %s\n", instr.opcode, )
}

void print_I_format(struct I_Format *instr){

}

void print_J_format(struct J_Format *instr){

}

