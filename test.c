/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:34:27 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 10:44:49 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "printf.h"
#include "stdio.h"
#include "string.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void	ft_print_test(char *s)
{
	int		len;

	len = 0;
	while (s[len])
	{
		if (s[len] == '\n')
			printf("\\n");
		else
			printf("%c", s[len]);
		len++;
	}
}

#define TEST_PRINT(s, ...) {\
	printf("%sTESTING%s ==> %s", KYEL, KNRM, KMAG);\
	ft_print_test(s);\
	printf("%s <==\n", KNRM);\
}

#define TEST(...) {\
	TEST_PRINT(__VA_ARGS__);\
	printf("   printf: ");\
	int res2 = printf(__VA_ARGS__);\
	printf("\n");\
	ft_printf("ft_printf: ");\
	int res1 = ft_printf(__VA_ARGS__);\
	ft_printf("\n");\
	if (res1 == res2) \
		printf("%sLOOKS OK%s\n", KGRN, KNRM);\
	else\
		printf("%sERROR%s: ft_printf=%d, printf=%d\n", KRED, KNRM, res1, res2);\
}

int		main(void)
{
	int i = 2147483647;
	long l = 2147483647;
	long long ll = 9223372036854775807;
	char c = 0;
	long im = 9223372036854775807;

	setlocale(LC_ALL, "");
	TEST("%s %s", "test1", "test2");
	TEST("%S", L"❤️😎🤗");
	TEST("%.*U", 10, 124098);
	TEST("%#X", 0xdeadbeef);
	TEST("%#x", 0xcafebabe);
	TEST("%#o", 0777);
	TEST("%d", 10);
	TEST("%U", 908080909);
	TEST("%*.*x", 100, 100, 0xcafebaba);
	TEST("\n");
	TEST("%%\n");
	TEST("%d\n", 42);
	TEST("%d%d\n", 42, 41);
	TEST("%d%d%d\n", 42, 43, 44);
	TEST("%ld\n", l);
	TEST("%lld\n", ll);
	TEST("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
	TEST("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
	TEST("%jd %zd %u %o %#08x\n", im, (size_t)i, i, 40, 42);
	TEST("%x %#X %S %s%s\n", 1000, 1000, L"ݗݜशব", "test", "test2");
	TEST("%s%s%s\n", "test", "test", "test");
	TEST("%C\n", 15000);
	return (0);
}
