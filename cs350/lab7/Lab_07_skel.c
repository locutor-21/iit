// CS 350, Spring 2019
//
// Lab 7 -- Structures, Pointers, and I/O
//
// Illinois Institute of Technology, (c) 2019, James Sasaki
//

#include <stdio.h>
#include <stdlib.h> 

struct Lab7_data 
{
	int x;
	float y;
	int z;
};
typedef struct Lab7_data Lab7_data;

int num_of_lines(FILE *datafile);

void read_data (int len, Lab7_data *data, FILE *datafile);

void print_data_reverse (int len, Lab7_data *data);

int main () 
{	
	printf("CS 350 Lab 7 for %s\n\n", "Pedro H Dias");

	char *datafile_name = "Lab7.txt";
	FILE *datafile = fopen(datafile_name, "r");
	if (!datafile)
	{
		printf("; open failed; program ends\n");
		exit(EXIT_FAILURE);
	}

	Lab7_data *data;
	int n = num_of_lines(datafile);
	data = malloc(n * sizeof(Lab7_data));
	
	read_data(n, data, datafile);
	
	print_data_reverse(n, data);

	fclose(datafile);
	return 1;
}

int num_of_lines(FILE *fp)
{
	char c;
	int n = 0;

	c = getc(fp);
	while(!feof(fp)){
		if (c == '\n')
			n++;
		c = getc(fp);
	}

	fseek(fp, 0, SEEK_SET);
	return n+1;
}

void read_data (int len, Lab7_data *data, FILE *datafile) 
{
	for (int i = 0; i < len; ++i)
	{
		fscanf(datafile, "%d %f 0x%x", &data[i].x, &data[i].y, &data[i].z );
		//printf("x=%3d\ty=%.2f\tz=0x%3x\n", data[i].x, data[i].y, data[i].z);
	}
}

void print_data_reverse (int len, Lab7_data *data) 
{
	printf("\n%s\n", "Reverse data:");
	for (int i = len-1; i >= 0; --i)
	{
		printf("x=%3d\ty=%.2f\tz=0x%3x\n", data[i].x, data[i].y, data[i].z);
	}
}
