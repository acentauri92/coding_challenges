#include "parse.h"


params input_params;

int parse_options(int argc, char** argv)
{
	int opt;
	int option_index;

	if(argc < 2) {
		print_help(argv[0]);
		return -1;
	}

	memset(&input_params, 0, sizeof(input_params));

	/* Define options */
	const struct option long_options[] = {
		{"input", required_argument, NULL, 'i'},
		{"output", required_argument, NULL, 'o'},
		{"help", no_argument, NULL, 'h'},
		{0, 0, 0, 0}
	};

	while (opt = getopt_long(argc, argv, "i:o:h", long_options, &option_index)){

		if(opt == -1)
			break;

		switch(opt) {
			case 'i':
				strncpy(input_params.input_file, optarg, PATH_MAX);
				break;
			case 'o':	
			 	//TODO: TO be updated when output is ready
				strncpy(input_params.output_file, optarg, PATH_MAX);
				break;
			case 'h':
				print_help(argv[0]);
				break;
		}
		
	}

	return 0;
}

void print_help(char* program_name) {
	printf("Usage: %s -i <input_file> [-o <output_file>] [-h]\n\n", 
			program_name);
	printf("Options:\n");
	printf("  -h, --help	Display this help message and exit\n");
	printf("  -i, --input	Specify the input file\n");
	printf("  -o, --output	Specify the output file\n");
}



















