#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        count++;
        h = h->next;
    }

    return count;
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
    size_t len = list_len(head);
    char **strs = NULL;
    char **temp = NULL;
    size_t i = 0;

    if (head == NULL || len == 0)
        return NULL;

    strs = malloc(sizeof(char *) * (len + 1));
    if (strs == NULL)
        return NULL;

    temp = strs;

    while (head != NULL)
    {
        *temp = strdup(head->str);
        if (*temp == NULL)
        {
            for (i = 0; i < len; i++)
                free(strs[i]);
            free(strs);
            return NULL;
        }

        temp++;
        head = head->next;
    }

    *temp = NULL;

    return strs;
}

/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        _puts(convert_number(h->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        count++;
    }

    return count;
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
    char *p = NULL;

    while (node != NULL)
    {
        p = starts_with(node->str, prefix);
        if (p != NULL && (c == -1 || *p == c))
            return node;
        node = node->next;
    }

    return NULL;
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
    ssize_t index = 0;

    while (head != NULL)
    {
        if (head == node)
            return index;
        head = head->next;
        index++;
    }

    return -1;
}
