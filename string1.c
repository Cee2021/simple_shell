#include <stdio.h>
#include <stdlib.h>

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, const char *src)
{
    char *dest_ptr = dest;

    while (*src)
    {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
    }
    *dest_ptr = '\0';

    return dest;
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
    char *dup;
    int length = 0;

    if (str == NULL)
        return NULL;

    while (str[length])
        length++;

    dup = malloc(sizeof(char) * (length + 1));
    if (dup == NULL)
        return NULL;

    _strcpy(dup, str);

    return dup;
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(const char *str)
{
    while (*str)
    {
        putchar(*str);
        str++;
    }
    putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return putchar(c);
}

