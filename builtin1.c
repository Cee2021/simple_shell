#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
    print_history(info->history);
    return 0;
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
    char *alias_name, *equal_sign;
    int ret;

    equal_sign = strchr(str, '=');
    if (!equal_sign)
        return 1;

    *equal_sign = '\0';
    alias_name = str;

    ret = delete_alias(info->alias, alias_name);

    *equal_sign = '=';
    return ret;
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
    char *alias_name, *equal_sign;

    equal_sign = strchr(str, '=');
    if (!equal_sign)
        return 1;

    *equal_sign = '\0';
    alias_name = str;

    unset_alias(info, alias_name);

    *equal_sign = '=';
    return add_alias(info->alias, str);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
    char *alias_name, *alias_value;

    if (node)
    {
        alias_name = node->str;
        alias_value = strchr(node->str, '=');

        printf("%.*s'%s'\n", (int)(alias_value - alias_name), alias_name, alias_value + 1);
        return 0;
    }
    return 1;
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
    int i;
    char *equal_sign;

    if (info->argc == 1)
    {
        print_all_aliases(info->alias);
        return 0;
    }

    for (i = 1; info->argv[i]; i++)
    {
        equal_sign = strchr(info->argv[i], '=');
        if (equal_sign)
            set_alias(info, info->argv[i]);
        else
            print_matching_aliases(info->alias, info->argv[i]);
    }

    return 0;
}

