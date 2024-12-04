#include "parse.h"


params input_params;

int parse_options(int argc, char** argv)
{
	int opt;
	int option_index;
	
	memset(&input_params, 0, sizeof(input_params));

	/* Define options */
	const struct option long_options[] = {
		{"input", required_argument, NULL, 'i'},
		{"output", required_argument, NULL, 'o'},
		{"help", no_argument, NULL, 'h'},
		{0, 0, 0, 0}
	};

	return 0;
}


//
//	while (opt = getopt_long(argc, argv, "i:o::h", long_options, &option_index)){
//
//		if(opt == -1)
//			break;
//
//		switch(opt) {
//			case 'i':
//				printf("Option %s with value %s\n", 
//					long_options[option_index].name, optarg);
//				break;
//			case 'o':	
//				printf("Option %s with value %s\n", 
//					long_options[option_index].name, optarg);
//				break;
//			case 'h':
//				printf("Option %s with value %s\n", 
//					long_options[option_index].name, optarg);
//				break;
//			case '?':
//				break;
//			default:
//				printf("No option provided\n");
//		}
//		
//	}






