#include <stdio.h>
#include <getopt.h>
#include "parse.h"

int main(int argc, char** argv)
{
	int ret = 0;

	ret = parse_options(argc, argv);
		
	return ret;
}




