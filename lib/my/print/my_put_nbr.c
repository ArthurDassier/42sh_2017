/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** print number
*/
#include "my.h"

static void put_limit(void)
{
	my_putchar('-');
	my_putchar('2');
	my_putchar('1');
	my_putchar('4');
	my_putchar('7');
	my_putchar('4');
	my_putchar('8');
	my_putchar('3');
	my_putchar('6');
	my_putchar('4');
	my_putchar('8');
}

int my_put_nbr(int nb)
{
	if (nb == -2147483648)
		put_limit();
	if (nb <= 2147483647 && nb != -2147483648) {
		if (nb < 0) {
			my_putchar('-');
			nb *= -1;
		}
		if (nb > 9) {
			my_put_nbr(nb / 10);
			my_put_nbr(nb % 10);
		}
		if (nb >= 0 && nb <= 9)
			my_putchar(nb + 48);
	}
	return (0);
}