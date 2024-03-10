#ifndef SRC_my_SSCANF_H_
#define SRC_my_SSCANF_H_

#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE_SYM " \n\r\t\v\f"
#define FORMAT_WITWOUT_C "dieEfgGosuxXpn%%"

typedef long double ldouble;
typedef short int shint;
typedef long int loint;
typedef long long int loloint;
typedef unsigned short int ushint;
typedef unsigned long int uloint;
typedef unsigned long long int uloloint;
typedef int integer;
typedef unsigned int uinteger;

typedef struct sscanf_flags {
  int no_assign;
  int widht;
  char length;
  char spec;
} specifier;

int my_sscanf(const char *str, const char *format, ...);
const char *my_reading_the_specifier(const char *format, specifier *flags,
                                      bool *work_func);
bool my_process_and_assign_str_val(const char *start, const char **str,
                                    specifier *flag, va_list *input,
                                    bool *work_func);
void my_delete_spaces(const char **string);

bool my_read_char(const char **str, specifier *flag, va_list *input,
                   bool *work_func);
bool my_read_string(const char **str, specifier *flag, va_list *input);

void print_spec(specifier *sp);

int my_ctoi(char c);
char is_digit(char c);
bool my_get_sign(int *widht, const char **str);
int my_get_base(const char *str);

bool my_checknan(int widht, const char **str);
bool my_checkinf(int widht, const char **str);

#endif  //  SRC_my_SSCANF_H_