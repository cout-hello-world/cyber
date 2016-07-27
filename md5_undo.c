#include <string.h>
#include <openssl/md5.h>

#include "cyber_func.h"

int md5_undo(char *out_buffer, const unsigned char *md5_hash)
{
	static const unsigned max_len = MD5_OUT_STR_MIN_LENGTH - 1;

	unsigned char md5_buffer[MD5_DIGEST_LENGTH];

	int length;
	int i;
	
	for (length = 0; length <= max_len; ++i) {
		for (i = 0; i != length; ++i) {
			out_buffer[i] = '0';
		}
		
		MD5(out_buffer, length, md5_buffer)
		if (!memcmp(md5_buffer, out_buffer, length)) {
			out_buffer[length] = '\0';
			return EXIT_SUCCESS;
		}
	}

	return EXIT_FAILURE;
}
