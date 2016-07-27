#ifndef CYBER_FUNC_H
#define CYBER_FUNC_H

#define MD5_HASH_LENGTH 16
#define MD5_OUT_STR_MIN_LENGTH 7


char *ceaser(char encode_or_decode, int offset, char *string);

int md5_undo(char *out_str, const unsigned char *md5_hash);
#endif
