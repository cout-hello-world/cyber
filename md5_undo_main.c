#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cyber_func.h"

static unsigned char get_hex(unsigned char hex_char)
{
	if (hex_char >= 'a') {
		return hex_char - 'a' + 0xa;
	} else if (hex_char >= 'A') {
		return hex_char - 'A' + 0xA;
	} else {
		return hex_char - '0';
	}
}

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
	unsigned char md5_buffer[16];
	unsigned char result[MD5_OUT_BUFFER_MIN_LENGTH];
	size_t len;
	if (argc >= 2 && strlen(argv[1]) == 32) {
		hex_to_bin(md5_buffer, &len, argv[1]);
		if (!md5_undo(result, md5_buffer)) {
			puts((char *)result);
		} else {
			puts("Could not find password");
			return EXIT_FAILURE;
		}
	} else {
		printf("Usage: %s <md5_hash>\n", argv[0]);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
