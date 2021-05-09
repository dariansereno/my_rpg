/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** itoa
*/

void reverse_str(char str[], int len)
{
    int start, end;
    char temp;

    for (start=0, end = len - 1; start < end; start++, end--) {
        temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
    }
}

char* itoa(int nb, char* str, int base)
{
    int i = 0;
    int is_neg = nb < 0 && base == 10 ? 1 : 0;

    if (nb == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return (str);
    }
    while (nb != 0) {
        int rem = nb % base;
        str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
        nb = nb/base;
    }
    if (is_neg)
        str[i++] = '-';
    str[i] = '\0';
    reverse_str(str, i);
    return (str);
}