#include "cyber_func.h"

#define LETTERS 26

static char encode(char offset, char ch)
{
	if (ch >= 'A' && ch <= 'Z') {
		ch -= 'A';
		ch += offset;
		ch %= LETTERS;
		ch += 'A';
	} else if (ch >= 'a' && ch <= 'z') {
		ch -= 'a';
		ch += offset;
		ch %= LETTERS;
		ch += 'a';
	}

	return ch;
}

void ceaser(char encode_or_decode, int offset, char *string)
{
	if (encode_or_decode == 'd') {
		offset = -offset;
	}

	offset %= LETTERS;
	if (offset < 0) {
		offset += LETTERS;
	}

	while (*string) {
		*string = encode(offset, *string);
		++string;
	}
}
