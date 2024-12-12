#include <limits.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void print_help(char* program_name);

typedef struct {
		char input_file[PATH_MAX];
		char output_file[PATH_MAX];
	}params;


extern params input_params;

int parse_options(int argc, char** argv);
