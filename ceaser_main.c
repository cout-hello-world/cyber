#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cyber_func.h"

static void print_help(void)
{
	puts("Usage... to be completed");
}

int main(int argc, char *argv[])
{
	char encode = 'e';
	int offset = 0;
	char *string = NULL;
	int i;

	for (i = 0; i + 1 < argc; ++i) {
		if (!strcmp(argv[i], "--code")) {
			if (!strcmp(argv[++i], "d")) {
				encode = 'd';
			}
		} else if (!strcmp(argv[i], "--offset")) {
			offset = atoi(argv[++i]);
		} else if (!strcmp(argv[i], "--string")) {
			string = argv[++i];
		}
	}

	if (!string) {
		print_help();
		return EXIT_FAILURE;
	}

	/* printf("encode = %c, offset = %d, string = %s\n", encode, offset, string);
	 */
	
	ceaser(encode, offset, string);
	printf("%s\n", string);

	return EXIT_SUCCESS;
}
