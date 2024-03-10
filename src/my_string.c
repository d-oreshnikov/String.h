#include "my_string.h"



my_size_t my_strlen(const char *str) {
  my_size_t len = 0;
  for (; *(str + len); len++)
    ;
  return len;
}

my_size_t my_strspn(const char *str1, const char *str2) {
  my_size_t i = 0;
  while (*str1 && my_strchr(str2, *str1++)) {
    i++;
  }
  return i;
}

my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t i = 0;
  while (*str1 && !my_strchr(str2, *str1++)) i++;
  return i;
}



void *my_to_upper(const char *str) {
  char step = 'A' - 'a';

  if (str == my_NULL) return my_NULL;

  my_size_t len = my_strlen(str);
  // char *res = (char *)malloc(len + 1);
  char *res = (char *)calloc(len + 1, sizeof(char));
  for (my_size_t i = 0; i < len; i++) {
    res[i] = str[i];
    if (res[i] >= 'a' && res[i] <= 'z') res[i] += step;
  }

  return (void *)res;
}

void *my_to_lower(const char *str) {
  char step = 'a' - 'A';

  if (str == my_NULL) return my_NULL;

  my_size_t len = my_strlen(str);
  // char *res = (char *)malloc(len + 1);
  char *res = (char *)calloc(len + 1, sizeof(char));

  for (my_size_t i = 0; i < len; i++) {
    res[i] = str[i];
    if (res[i] >= 'A' && res[i] <= 'Z') res[i] += step;
  }

  return (void *)res;
}

void *my_insert(const char *src, const char *str, my_size_t start_index) {
  my_size_t lensrc = 0;
  my_size_t lenstr = 0;

  if (src != my_NULL)
    lensrc = my_strlen(src);
  else
    lensrc = 0;
  if (str != my_NULL)
    lenstr = my_strlen(str);
  else
    lenstr = 0;

  my_size_t len = lensrc + lenstr;

  if (start_index > lensrc) return my_NULL;

  // char *res = (char *)malloc(len + 1);
  char *res = (char *)calloc(len + 1, sizeof(char));

  if (res) {
    for (my_size_t i = 0; i < len; i++) {
      if (i < start_index)
        res[i] = src[i];
      else if (i < start_index + lenstr)
        res[i] = str[i - start_index];
      else
        res[i] = src[i - lenstr];
    }
  }
  res[lensrc + lenstr] = '\0';
  return (void *)res;
}

int find(int in, char *trim) {
  int count = 0;
  while (*trim != '\0') {
    if (*trim == in) count++;
    trim++;
  }
  int flag = 0;
  if (count >= 1) {
    flag = 1;
  } else {
    flag = 0;
  }
  return flag;
}

void *my_trim(const char *src, const char *trim_chars) {
  my_size_t i = 0;
  if (src == my_NULL) return my_NULL;
  // char *res = (char *)malloc(my_strlen(src) + 1);
  char *res = (char *)calloc(my_strlen(src) + 1, sizeof(char));
  strcpy(res, src);
  if (trim_chars == my_NULL) return (void *)res;
  // char *trim = (char *)malloc(my_strlen(trim_chars) + 1);
  char *trim = (char *)calloc(my_strlen(trim_chars) + 1, sizeof(char));

  if (trim_chars != my_NULL && my_strlen(trim_chars) != 0)
    strcpy(trim, trim_chars);
  else
    strcpy(trim, "\t\n\v\r\f ");

  int index = 0, j, k = 0;
  while (find(res[index], trim)) {
    index++;
  }
  int len = my_strlen(res);
  if (index > 0) {
    for (j = 0, k = index; j <= len - index; j++, k++) {
      res[j] = res[k];
    }
    res[j] = '\0';
  }

  for (i = my_strlen(res) - 1; (find(res[i], trim)); i--)
    ;

  res[i + 1] = '\0';
  free(trim);

  return (void *)res;
}


int my_strcmp(const char *str1, const char *str2) {
  int res = 0;
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  if (!*str1 && !*str2)
    res = 0;
  else
    res = *str1 - *str2;
  return res;
}

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  int i = 0;
  int res = 0;
  for (; *str1 && *str1 == *str2 && i < (int)n - 1; str1++, str2++) {
    i++;
  }
  if ((!*str1 && !*str2) || (n == 0))
    res = 0;
  else
    res = *str1 - *str2;
  return res;
}

int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  int k = 0;
  for (int i = 0; i < (int)n; i++) {
    if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i]) {
      k = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
      break;
    }
  }
  return k;
}

// Searches for the first occurrence of the character 'c'
char *my_strchr(const char *str, int c) {
  char *new = my_NULL;
  while (*str != c && *str != '\0') str++;
  if (*str == c) {
    new = (char *)str;
  }
  return new;
}

// Finds the first character in the string str1 that
// matches any character specified in str2
char *my_strpbrk(const char *str1, const char *str2) {
  char *new = my_NULL;
  while (!my_strchr(str2, *str1) && *str1 != '\0') str1++;
  if (my_strchr(str2, *str1) && *str1 != '\0') new = (char *)str1;

  return new;
}

// Searches for the last occurrence of the character 'c'
char *my_strrchr(const char *str, int c) {
  char *res = my_NULL;
  my_size_t len = my_strlen(str);

  for (int i = len; i >= 0; i--) {
    if (str[i] == c) {
      res = ((char *)str) + i;
      break;
    }
  }

  return res;
}

// Finds the first occurrence of the entire string needle
// which appears in the string haystack
char *my_strstr(const char *haystack, const char *needle) {
  char *strForReturn = my_NULL;
  if (!my_strcmp(needle, ""))
    strForReturn = (char *)haystack;
  else {
    my_size_t length = my_strlen(needle);
    while (*haystack != '\0') {
      if (my_memcmp(haystack, needle, length) == 0) {
        strForReturn = (char *)haystack;
        break;
      }
      haystack++;
    }
  }
  return strForReturn;
}

// Searches for the first occurrence of the character 'c'
// in the first n bytes of the string
void *my_memchr(const void *str, int c, my_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  while (n > 0) {
    if (*ptr == c) {
      return (void *)ptr;
    } else {
      ptr++;
      n--;
    }
  }
  return my_NULL;
}


void *my_memcpy(void *restrict dest, const void *restrict src, my_size_t n) {
  my_size_t i = 0;
  unsigned char *c_dest = (unsigned char *)dest;
  unsigned char *c_src = (unsigned char *)src;
  while (i < n) {
    c_dest[i] = c_src[i];
    i++;
  }
  return dest;
}

void *my_memmove(void *dest, const void *src, my_size_t n) {
  const char *s;
  const char *lasts;
  char *d;
  char *lastd;

  d = dest;
  s = src;
  if (d < s) {
    while (n--) *d++ = *s++;
  } else {
    lasts = s + (n - 1);
    lastd = d + (n - 1);
    while (n--) *lastd-- = *lasts--;
  }

  return (dest);
}

void *my_memset(void *str, int c, my_size_t n) {
  unsigned char *c_str = (unsigned char *)str;
  my_size_t i = 0;

  while (i < n) {
    c_str[i] = c;
    i++;
  }

  return str;
}

char *my_strcpy(char *restrict dest, const char *restrict src) {
  char *start = dest;

  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }

  *dest = '\0';

  return start;
}

char *my_strncpy(char *restrict dest, const char *restrict src, my_size_t n) {
  char *start = dest;
  my_size_t src_len = my_strlen(src);
  for (my_size_t i = 0; i < n; i++) {
    if (i >= src_len) {
      dest[i] = '\0';
    } else {
      dest[i] = src[i];
    }
  }
  return start;
}


char *my_strcat(char *restrict dest, const char *restrict src) {
  char *start = dest;

  while (*dest != '\0') {
    dest++;
  }

  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }

  *dest = '\0';
  return start;
}

char *my_strncat(char *restrict dest, const char *restrict src, my_size_t n) {
  char *tmp = dest;
  while (*tmp != '\0') tmp++;
  for (my_size_t i = 0; i < n; i++) *tmp++ = src[i];
  return dest;
}

char *my_strtok(char *restrict str, const char *restrict delim) {
  static char *last;
  register int ch;

  if (str == 0) {
    str = last;
  }
  do {
    if ((ch = *str++) == '\0') {
      return 0;
    }
  } while (my_strchr(delim, ch));
  --str;
  last = str + my_strcspn(str, delim);
  if (*last != 0) {
    *last++ = 0;
  }
  return str;
}

#if defined(__APPLE__)
#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "

const char *arr_error[] = {"Undefined error: 0",
                           "Operation not permitted",
                           "No such file or directory",
                           "No such process",
                           "Interrupted system call",
                           "Input/output error",
                           "Device not configured",
                           "Argument list too long",
                           "Exec format error",
                           "Bad file descriptor",
                           "No child processes",
                           "Resource deadlock avoided",
                           "Cannot allocate memory",
                           "Permission denied",
                           "Bad address",
                           "Block device required",
                           "Resource busy",
                           "File exists",
                           "Cross-device link",
                           "Operation not supported by device",
                           "Not a directory",
                           "Is a directory",
                           "Invalid argument",
                           "Too many open files in system",
                           "Too many open files",
                           "Inappropriate ioctl for device",
                           "Text file busy",
                           "File too large",
                           "No space left on device",
                           "Illegal seek",
                           "Read-only file system",
                           "Too many links",
                           "Broken pipe",
                           "Numerical argument out of domain",
                           "Result too large",
                           "Resource temporarily unavailable",
                           "Operation now in progress",
                           "Operation already in progress",
                           "Socket operation on non-socket",
                           "Destination address required",
                           "Message too long",
                           "Protocol wrong type for socket",
                           "Protocol not available",
                           "Protocol not supported",
                           "Socket type not supported",
                           "Operation not supported",
                           "Protocol family not supported",
                           "Address family not supported by protocol family",
                           "Address already in use",
                           "Can't assign requested address",
                           "Network is down",
                           "Network is unreachable",
                           "Network dropped connection on reset",
                           "Software caused connection abort",
                           "Connection reset by peer",
                           "No buffer space available",
                           "Socket is already connected",
                           "Socket is not connected",
                           "Can't send after socket shutdown",
                           "Too many references: can't splice",
                           "Operation timed out",
                           "Connection refused",
                           "Too many levels of symbolic links",
                           "File name too long",
                           "Host is down",
                           "No route to host",
                           "Directory not empty",
                           "Too many processes",
                           "Too many users",
                           "Disc quota exceeded",
                           "Stale NFS file handle",
                           "Too many levels of remote in path",
                           "RPC struct is bad",
                           "RPC version wrong",
                           "RPC prog. not avail",
                           "Program version wrong",
                           "Bad procedure for program",
                           "No locks available",
                           "Function not implemented",
                           "Inappropriate file type or format",
                           "Authentication error",
                           "Need authenticator",
                           "Device power is off",
                           "Device error",
                           "Value too large to be stored in data type",
                           "Bad executable (or shared library)",
                           "Bad CPU type in executable",
                           "Shared library version mismatch",
                           "Malformed Mach-o file",
                           "Operation canceled",
                           "Identifier removed",
                           "No message of desired type",
                           "Illegal byte sequence",
                           "Attribute not found",
                           "Bad message",
                           "EMULTIHOP (Reserved)",
                           "No message available on STREAM",
                           "ENOLINK (Reserved)",
                           "No STREAM resources",
                           "Not a STREAM",
                           "Protocol error",
                           "STREAM ioctl timeout",
                           "Operation not supported on socket",
                           "Policy not found",
                           "State not recoverable",
                           "Previous owner died",
                           "Interface output queue is full"};

#elif defined(__linux__)
#define MAX_ERRLIST 134
#define MIN_ERRLIST -1
#define ERROR "Unknown error "

static const char *arr_error[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};
#endif

char *my_strerror(int errnum) {
  static char *ptr_result = my_NULL;
  if (MIN_ERRLIST < errnum && errnum < MAX_ERRLIST) {
    ptr_result = (char *)arr_error[errnum];
  } else {
    static char message[128] = {'\0'};
    sprintf(message, "%s%d", ERROR, errnum);
    ptr_result = message;
  }
  return ptr_result;
}
