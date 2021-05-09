/*
** EPITECH PROJECT, 2021
** header
** File description:
** strings.h
*/

#ifndef STRINGS_H_
#define STRINGS_H_

typedef struct garbage_collector_s my_garbage_t;
struct garbage_collector_s
{
    void *mal;
    my_garbage_t *next;
};

void my_putchar(char c);
void my_putchar_error(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int is_separator(char c, const char *separator);
int word_size(const char *str, const char *separator);
char *my_strncpy(char *dest, const char *src, int n);
int get_nb_words(const char *str, const char *separator);
char **my_str_to_word_array(const char *str, const char *separator);
my_garbage_t **current_garbage(void);
void call_after_main(void) __attribute__((destructor));
my_garbage_t *add_ptr_to_garbage \
(my_garbage_t *garbage, void *mal);
void destroy_ptr_to_garbage(my_garbage_t *garbage);
void *my_malloc(int size_of);
char *itoa(int nb, char *str, int base);

#endif /* !STRINGS_H_ */
