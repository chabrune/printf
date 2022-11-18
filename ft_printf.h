#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	printchar(char c, int *len);
char	*printstr(char *str, int *len);
int		printnbr(long nb, int *len);
int		printunbr(unsigned long nb, int *len);
void	printnbrbase(int nbr, char *base, int *len);
void	printaddr(int nbr, char *base, int *len);

#endif