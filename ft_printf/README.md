# ft_printf

`ft_printf` is a custom implementation of the `printf()` function from the C standard library. This project involves recreating a simplified version of `printf()` that handles specific format conversions. It is built as a static library (`libftprintf.a`) without using `libtool`, as required by the 42 curriculum.

## Supported Conversions
- `%c` – Single character
- `%s` – String
- `%p` – Pointer address (hexadecimal)
- `%d` – Signed decimal
- `%i` – Integer (base 10)
- `%u` – Unsigned decimal
- `%x` – Lowercase hexadecimal
- `%X` – Uppercase hexadecimal
- `%%` – Percent sign

## Compilation
To compile the library, use `make` in the root directory. The static library `libftprintf.a` will be created.

## Usage
Link the `libftprintf.a` library in your C programs to use the `ft_printf` function for formatted output.
