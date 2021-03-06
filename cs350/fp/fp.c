// CS 350, Spring 2019
//
// Final Project
// Done accordingly to Instructions version on 4/28;
//
// Illinois Institute of Technology, Pedro H. Dias
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	};
};
typedef struct instruction Instruction;

int  num_of_instr(FILE *fp); //Returns number of Instructions in data.txt
void set_register(char* string, byte num); //Set value of string to corresponding name of register
void build_instr(unsigned int bitstring, Instruction *instr); //Start building general instruction; decides instruction format
void build_R_format(unsigned int bitstring, struct R_Format *instr); //Build R format
void build_I_format(unsigned int bitstring, struct I_Format *instr); //Build I format
void build_J_format(unsigned int bitstring, struct J_Format *instr); //Build J format
void print_instr(Instruction *instr, unsigned int address); //Decides the instruction format
void print_R_format(struct R_Format *instr); //Prints R format
void print_I_format(byte opcode, struct I_Format *instr, unsigned int address); //Prints I format
void print_J_format(byte opcode, struct J_Format *instr); //Prints J format

int main(){
	printf("Spring 2019 - CS 350 Final Project for %s\n\n", "Pedro H Dias");

	//Opens file with the instructions
	char *datafile_name = "data.txt";
	FILE *datafile = fopen(datafile_name, "r");
	printf("Loading %s\n", datafile_name);
	if (!datafile){
		printf("; open failed; program ends\n");
		exit(EXIT_FAILURE);
	}

	//Declare variables
	int n;
	unsigned int initial_address;
	unsigned int bitstring;
	Instruction* instr_list;
	
	//Calculates size of instr_list and allocates memory to it
	n = num_of_instr(datafile);
	instr_list = malloc(n * sizeof(Instruction));
	printf("Read %d lines of data\n", n);

	//Read datafile for instructions
	for (int p = 0; p < n; ++p)
	{
		fscanf(datafile, "%X\n", &bitstring);
		//Build instruction
		build_instr(bitstring, &instr_list[p]);
	}

	///Prompt user for inital address
	printf("Enter program counter (hex digits):\n");
	scanf("%x", &initial_address);

	printf("Initial program counter = x%08X\n\n", initial_address);

	//Print output
	printf("Location    Instruction\n");
	for (int i = 0; i < n; ++i)
	{
		printf("x%08X", initial_address);
		//Call print_instr function
		print_instr(&instr_list[i], initial_address);
		printf("\n");
		initial_address += 4;
	}

	//Close files and ends program
	printf("\nProgram ending\n");
	fclose(datafile);
	return 0;
}

int num_of_instr(FILE *fp){
	int n = 0;
	char c;

	c = getc(fp);
	while(!feof(fp)){
		if (c == '\n')
			n++;
		c = getc(fp);
	}

	fseek(fp, 0, SEEK_SET);
	return n;
}

void set_register(char* string, byte num){
	char register_list[32][4] = {
		"$0",
		"$at",
		"$v0",
		"$v1",
		"$a0",
		"$a1",
		"$a2",
		"$a3",
		"$t0",
		"$t1",
		"$t2",
		"$t3",
		"$t4",
		"$t5",
		"$t6",
		"$t7",
		"$s0",
		"$s1",
		"$s2",
		"$s3",
		"$s4",
		"$s5",
		"$s6",
		"$s7",
		"$t8",
		"$t9",
		"$k0",
		"$k1",
		"$gp",
		"$sp",
		"$fp",
		"$ra"
	};
	strcpy(string, register_list[num]);
}

void build_instr(unsigned int bitstring, Instruction *instr){
	
	//11111100000000000000000000000000 = 4227858432
	instr -> opcode = (bitstring & 4227858432) >> 26;
	
	switch(instr -> opcode){
		case 0:
			build_R_format(bitstring, &(instr -> r_fmt));
			break;
		case 2:
			build_J_format(bitstring, &(instr -> j_fmt));
			break;
		case 3:
			build_J_format(bitstring, &(instr -> j_fmt));
			break;
		default:
			build_I_format(bitstring, &(instr -> i_fmt));
	}
	
}

void build_R_format(unsigned int bitstring, struct R_Format *instr){

	//00000011111000000000000000000000 = 65011712
	//00000000000111110000000000000000 = 2031616
	//00000000000000001111100000000000 = 63488
	//00000000000000000000011111000000 = 1984
	//00000000000000000000000000111111 = 63

	instr -> rs = (bitstring & 65011712) >> 21;	
	instr -> rt = (bitstring & 2031616) >> 16;
	instr -> rd = (bitstring & 63488) >> 11;
	instr -> shamt = (bitstring & 1984) >> 6;
	instr -> funct = (bitstring & 63);
}

void build_I_format(unsigned int bitstring, struct I_Format *instr){

	//00000011111000000000000000000000 = 65011712
	//00000000000111110000000000000000 = 2031616
	//00000000000000001111111111111111 = 65535

	instr -> rs = (bitstring & 65011712) >> 21;
	instr -> rt = (bitstring & 2031616) >> 16;	
	instr -> immediate = (bitstring & 65535);
}

void build_J_format(unsigned int bitstring, struct J_Format *instr){

	//00000011111111111111111111111111 = 67108863

	instr -> address = (bitstring & 67108863);
}

void print_instr(Instruction *instr, unsigned int address){
	printf("   ");
	switch(instr -> opcode){
		case 0:
			print_R_format(&(instr -> r_fmt));
			break;
		case 2:
			print_J_format(instr->opcode, &(instr -> j_fmt));
			break;
		case 3:
			print_J_format(instr->opcode, &(instr -> j_fmt));
			break;
		default:
			print_I_format(instr->opcode, &(instr -> i_fmt), address);
	}
}

void print_R_format(struct R_Format *instr){
	//Print mnemonic based on funct and opcode
	switch(instr->funct){
		case 32:
			printf("%-4s", "add");
			break;
		case 36:
			printf("%-4s", "and");
			break;
		case 26:
			printf("%-4s", "div");
			break;
		case 8:
			printf("%-4s", "jr");
			break;
		case 24:
			printf("%-4s", "mul");
			break;
		case 0:
			(instr->shamt == 0) ? (printf("%-4s", "nop")) : (printf("%-4s", "sll"));
			break;
		case 39:
			printf("%-4s", "nor");
			break;
		case 37:
			printf("%-4s", "or");
			break;
		case 42:
			printf("%-4s", "slt");
			break;
		case 34:
			printf("%-4s", "sub");
			break;
		case 40:
			printf("%-4s", "xor");
			break;
		default:
			printf("funct=%d", instr->funct);
			break;
	}

	char rd[4], rs[4], rt[4];
	
	set_register(rd, instr->rd);
	set_register(rs, instr->rs);
	set_register(rt, instr->rt);

	if(instr->funct == 0 && instr->shamt != 0){
		printf(" %3s, %3s, %3d", rd, rt, instr->shamt);
		printf("   (rd/f:x%02X, x%02X = dec %2d, %2d)", instr->rd, instr->funct, instr->rd, instr->funct);
	}
	else{
		printf(" %3s, %3s, %3s", rd, rs, rt);
		printf("   (s/f: x%02X, x%02X = dec %2d, %2d)", instr->shamt, instr->funct, instr->shamt, instr->funct);
	}
	
}

void print_I_format(byte opcode, struct I_Format *instr, unsigned int address){
	//Print mnemonic based on opcode
	switch(opcode){
		case 8:
			printf("%-4s", "addi");
			break;
		case 12:
			printf("%-4s", "andi");
			break;
		case 4:
			printf("%-4s", "beq");
			break;
		case 5:
			printf("%-4s", "bne");
			break;
		case 15:
			printf("%-4s", "lui");
			break;
		case 35:
			printf("%-4s", "lw");
			break;
		case 13:
			printf("%-4s", "ori");
			break;
		case 10:
			printf("%-4s", "slti");
			break;
		case 43:
			printf("%-4s", "sw");
			break;
		case 14:
			printf("%-4s", "xori");
			break;
		default:
			printf("opcode=%d", opcode);
			break;
	}

	char rs[4], rt[4];
	
	set_register(rs, instr->rs);
	set_register(rt, instr->rt);

	printf(" %3s, %3s, x%04x  : dec %-6d", rs, rt, (instr->immediate & 0xffff), instr->immediate);
	if(opcode == 4 || opcode == 5)
		printf("  target = x%08X", address + 4*(instr->immediate+1));
}

void print_J_format(byte opcode, struct J_Format *instr){
	switch(opcode){
		case 2:
			printf("%-4s", "j");
			break;
		case 3:
			printf("%-4s", "jal");
			break;
		default:
			break;
	}

	printf(" x%07x", instr->address);
}
