#ifndef _STRING_H
#define _STRING_H 1
 
#include <sys/cdefs.h>
 
#include <stddef.h>
 
#ifdef __cplusplus
extern "C" {
#endif
 
int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);
size_t strnlen(const char* s, size_t maxlen);

void itoa(unsigned int n, char* s, unsigned int base);

 
#ifdef __cplusplus
}
#endif
 
#endif