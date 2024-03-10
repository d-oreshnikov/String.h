#ifndef SRC_my_SPRINTF_UTILS_H_
#define SRC_my_SPRINTF_UTILS_H_

#include <math.h>

#include "../my_string.h"
#include "my_sprintf.h"
#include "my_sprintf_options.h"

// conversions
int my_atoi(const char **str);
char my_digit_to_char(int digit, int text_case);
char *my_unsigned_to_str(unsigned long int num, unsigned int notation,
                          int text_case);
char *my_mantissa_to_str(long double num, int *next_digit, opt options);
char *my_float_to_str(long double num);
void my_WchInStr(char *str, wchar_t *wstr, int len);
void my_invert_str(char *origin, char *inverted);

// obtainig values
void my_split_float(long double double_var, long double *ones,
                     long double *tens);
long double my_get_double_variable(opt options, va_list var_arg);
long unsigned my_get_unsigned_variable(opt options, va_list var_arg,
                                        int *is_negative);
unsigned my_get_exponent(long double *mantissa);
void my_get_char_sign(int is_negative, char *sign, opt options);
void my_precision_CS(int *wlen, opt options);

// output formatting
void my_apply_num_precision(char **buf, int precision);
void my_add_notation(char **buf, opt options);
void my_add_sign(char **buf, char sign);
void my_apply_width(char **buf, opt options, var *variables);
void my_delete_trailing_zeros(char **num_string, opt options);
void my_math_rounding(char **num_string, int next_digit, char *exp_sign,
                       unsigned *u_exp);

// others
size_t my_wstrlen(wchar_t *wstr);
int my_recording(char **str, var *variables);
char *my_nan_inf(long double variable, char *sign, specifi format_spec);
char *my_sum_and_free_strings(char *string1, char *string2);
int my_is_spec_int(specifi spec);
int my_is_spec_float(specifi spec);

#endif  // SRC_my_SPRINTF_UTILS_H_