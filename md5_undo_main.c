#include <stdlib.h>
#include <stdio.h>

#include "cyber_func.h"

static unsigned char get_hex(unsigned char hex_char)
{
	if (hex_char >= '0') {
		return hex_char - '0';
	} else if (hex_char >= 'A') {
		return hex_char - 'A' + 0xA;
	} else {
		return hex_char - 'a' + 0xa;
	}
}


/**
 * This function converts a hex string to a binary string.
 * @param
 */
static void hex_to_bin(unsigned char *bin, size_t *bin_len, const char *hex)
{
	int high_bits = 1;
	*bin_len = 0;
	while (*hex) {
		if (high_bits) {
			bin[*bin_len] = get_hex(*hex) << 4;
		} else {
			bin[*bin_len] |= get_hex(*hex);
			++(*bin_len);
		}
		high_bits = !high_bits;
		++hex;
	}

	if (!high_bits) {
		++(*bin_len);
	}
}

int main(int argc, char *argv[])
{
	unsigned char buffer[100];
	size_t len;
	if (argc >= 2) {
		hex_to_bin(buffer, &len, argv[1]);
		printf("%lu\n", len);
	}
	return EXIT_SUCCESS;
}
