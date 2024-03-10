#ifndef SRC_my_SPRINTF_H_
#define SRC_my_SPRINTF_H_

#include <float.h>
#include <limits.h>
#include <stdarg.h>

#include "my_sprintf_options.h"

typedef struct variables {
  int errorFlag;
  char *Chbuf;
  char *temp;
  char *tmp_ptr;
} var;

void my_free_at_exit(var *variables);
void my_mem_check(char *str, var *variables);

void my_call_var_arg(char **str, opt options, va_list var_arg, int *n_smb,
                      var *variables);

int my_int_specifiers(char **str, opt options, va_list var_arg,
                       var *variables);
int my_e_specifiers(char **str, opt options, long double double_var,
                     var *variables);
int my_f_specifier(char **str, opt options, long double double_var,
                    var *variables);
int my_g_specifiers(char **str, opt *options, long double double_var,
                     var *variables);
int my_p_specifier(char **str, opt options, va_list var_arg, var *variables);
int my_perc_specifier(char **str, opt options, var *variables);
void my_n_specifier(opt options, va_list var_arg, long int n_smb);
int my_c_specifier(char **str, opt options, va_list var_arg, var *variables);
void my_c_sol_fork(opt options, va_list var_arg, var *variables);
int my_s_specifier(char **str, opt options, va_list var_arg, var *variables);
void my_s_sol_fork(opt options, va_list var_arg, var *variables);

#endif  // SRC_my_SPRINTF_H_
