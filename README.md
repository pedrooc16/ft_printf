# ft_printf - Recoding printf() /42 Lisboa/

## What is it about?

* As my second project as a cadet at 42 Lisboa, I was in charge of `recoding` the `libc's printf function`, for it to have some of the `same features as the original one`. 

* That being said, my 'ft_printf' function is a custom implementation of the 'printf' function in C, that provides a similar interface for printing formatted output. It allows you to specify a `format string` and a `list of arguments`, and it generates output based on the format string.

In order to make it work, I had to work with the concept of `variadic functions`, which can somehow bring more `flexibility` to the programs that are built based on the C language.

## How does it work?

* The format string consists of text and format specifiers, which are special codes that specify how the corresponding argument should be formatted. `Format specifiers` start with a `percent sign (%)` and are `followed by a letter` that determines the type of the argument and the format of the output. For example, %d specifies that the corresponding argument is an integer and should be formatted as a decimal number.

* Then, the function processes the format string character by character and performs the following actions:

    * if a character is `not` a `format specifier`, it is simply written to the output; or
    * if a character is a `format specifier`, the function retrieves the next argument from the argument list, formats it according to the specified format, and writes the result to the output.

* On my implementation, the function processed the following type specifiers:

    * ``%c`` - single character

    * ``%s`` - string of characters

    * ``%p`` - pointer to void (in hexadecimal)

    * ``%d`` - decimal number

    * ``%i`` - integer number

    * ``%u`` - unsigned decimal number

    * ``%x`` - number in hexadecimal (lowercase)

    * ``%X`` - number in hexadecimal (uppercase)

    * ``%%`` - percent character


* Once the function has processed the entire format string, it `returns` the `number of characters` written. 

* Note that 'ft_printf' is similar to 'printf', but `not exactly the same`. 'ft_printf' might have some differences in the way it handles format specifiers, escape sequences, and errors compared to printf.
