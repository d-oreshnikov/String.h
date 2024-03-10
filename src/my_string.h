#ifndef SRC_my_STRING_H_
#define SRC_my_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long unsigned my_size_t;
#define my_NULL (void *)0
#define my_void

// calculation functions 
my_size_t my_strlen(const char *str);
my_size_t my_strspn(const char *str1, const char *str2);
my_size_t my_strcspn(const char *str1, const char *str2);

// C# functions 
void *my_to_upper(const char *str);
void *my_to_lower(const char *str);
void *my_insert(const char *src, const char *str, my_size_t start_index);
int find(int in, char *trim);
void *my_trim(const char *src, const char *trim_chars);

// comparison functions 
int my_strcmp(const char *str1, const char *str2);
int my_strncmp(const char *str1, const char *str2, my_size_t n);
int my_memcmp(const void *str1, const void *str2, my_size_t n);

// search functions 
char *my_strchr(const char *str, int c);
char *my_strpbrk(const char *str1, const char *str2);
char *my_strrchr(const char *str, int c);
char *my_strstr(const char *haystack, const char *needle);
void *my_memchr(const void *str, int c, my_size_t n);

// copy functions 
/* Copy N bytes of SRC to DEST.  */
void *my_memcpy(void *restrict dest, const void *restrict src, my_size_t n);

/* Copy N bytes of SRC to DEST, guaranteeing
   correct behavior for overlapping strings.  */
void *my_memmove(void *dest, const void *src, size_t n);

/* Set N bytes of S to C.  */
void *my_memset(void *str, int c, my_size_t n);

/* Copy SRC to DEST.  */
char *my_strcpy(char *restrict dest, const char *restrict src);

/* Copy no more than N characters of SRC to DEST.  */
char *my_strncpy(char *restrict dest, const char *restrict src, my_size_t n);

// help functions 
/**
 * Devided SRC into tokens separated in characters in DELIM.
 */
char *my_strtok(char *restrict str, const char *restrict delim);

/**
 * Retrun a string describe the meaning of thr "errno" code in ERRNUM
 */
char *my_strerror(int errnum);

/**
 * Append SRC onto DEST.
 */
char *my_strcat(char *restrict dest, const char *restrict src);

/**
 * Append no more than N characters from SRC onto DEST
 */
char *my_strncat(char *restrict dest, const char *restrict src, my_size_t n);

int my_sprintf(char *str, const char *format, ...);

#endif  //  SRC_my_STRINGS_H_