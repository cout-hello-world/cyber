#ifndef CYBER_FUNC_H
#define CYBER_FUNC_H

#define MD5_HASH_LENGTH 16
#define MD5_OUT_BUFFER_MIN_LENGTH 8

char *ceaser(char encode_or_decode, int offset, char *string);

int md5_undo(unsigned char *buffer, const unsigned char *md5_hash);
#endif
