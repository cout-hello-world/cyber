#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>

#include "cyber_func.h"

int md5_undo(unsigned char *buffer, const unsigned char *md5_hash)
{
	static const unsigned max_len = MD5_OUT_BUFFER_MIN_LENGTH - 1;

	unsigned char md5_buffer[MD5_DIGEST_LENGTH];

	unsigned length;
	unsigned i;

	for (length = 1; length <= max_len; ++length) {
		for (i = 0; i != length; ++i) {
			buffer[i] = '0';
		}

		while (1) {
			MD5(buffer, length, md5_buffer);
			if (!memcmp(md5_buffer, md5_hash, MD5_DIGEST_LENGTH)) {
				buffer[length] = '\0';
				return EXIT_SUCCESS;
			}

			for (i = 0; i != length; ++i) {
				if (buffer[i] == '9') {
					buffer[i] = 'a';
					break;
				} else if (buffer[i] == 'z') {
					if (i + 1 == length) {
						goto outer;
					} else {
						buffer[i] = '0';
					}
				} else {
					++buffer[i];
					break;
				}
			}
		}
	outer:
		;
	}

	return EXIT_FAILURE;
}
