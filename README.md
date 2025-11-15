# ft_printf
<img width="1024" height="1536" alt="image" src="https://github.com/user-attachments/assets/1fd191a4-dc82-47d9-aba2-2d9eab4bb552" />
Reimplementation of the standard C `printf` function as part of the 42 school curriculum.

The goal is to understand how variadic functions work in C, how format strings are parsed,
and how to handle different data types while always returning the correct number of
printed characters.

---

## ✅ Features

Supported conversion specifiers:

- `%c` – print a single character
- `%s` – print a null-terminated string
- `%p` – print a pointer address in hexadecimal prefixed with `0x`
- `%d` / `%i` – print a signed decimal integer
- `%u` – print an unsigned decimal integer
- `%x` – print an unsigned hexadecimal integer (lowercase)
- `%X` – print an unsigned hexadecimal integer (uppercase)
- `%%` – print a literal `%` character

Return value:

- Just like the original `printf`, `ft_printf` returns the **number of characters printed**.

---

## 🧠 Implementation overview

The project is split into small, focused functions:

- `ft_printf.c`  
  Parses the format string, detects `%` sequences and dispatches each conversion
  to the correct helper function. Handles variadic arguments using `va_list`,
  `va_start`, `va_arg` and `va_end`.

- `print_char.c`  
  Implements `%c` – prints a single character.

- `print_string.c`  
  Implements `%s` – prints a string, handles `NULL` by printing `(null)`.

- `print_int.c`  
  Implements `%d` and `%i` – prints signed integers, including negative values
  (uses `long` internally to safely handle `INT_MIN`).

- `print_unsigned.c`  
  Implements `%u` – prints unsigned decimal integers.

- `print_hex.c`  
  Implements `%x` and `%X` – prints numbers in base 16 using recursion.

- `print_pointer.c`  
  Implements `%p` – prints pointer addresses, always prefixed by `0x`.  
  For a `NULL` pointer, prints `0x0`.

- `ft_utils.c`  
  Minimal helper functions to avoid depending on libft:
  - `ft_putchar_fd`
  - `ft_putstr_fd`
  - `ft_strlen`
  - `ft_strchr`

All files include the single header:

```c
#include "ft_printf.h"
