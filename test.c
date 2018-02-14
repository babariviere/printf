/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:34:27 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 18:22:17 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "printf.h"
#include "stdio.h"
#include "string.h"
#include "limits.h"
#include "stdint.h"

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
	//TEST("%s %s", "test1", "test2");
	//TEST("%.10s", "hello");
	//TEST("%.10s", "hello wonderful world");
	//TEST("%.0s", "hello wonderful world");
	//TEST("%40s", "hello wonderful world");
	//TEST("%S", L"bonjour ❤️ 😎 🤗");
	////TEST("%.11S", L"bonjour ❤️ 😎 🤗");
	////TEST("%.12S", L"bonjour ❤️ 😎 🤗");
	////TEST("%.13S", L"bonjour ❤️ 😎 🤗");
	////TEST("%.14S", L"bonjour ❤️ 😎 🤗");
	////TEST("%5U", 124098);
	////TEST("%10U", 124098);
	////TEST("%6U", 124098);
	////TEST("%7U", 124098);
	////TEST("%010U", 124098);
	////TEST("%-10U", 124098);
	////TEST("%0.10U", 124098);
	////TEST("%-.10U", 124098);
	////TEST("%-.*U", 10, 124098);
	//TEST("%d", INT_MIN);
	//TEST("%d", INT_MAX);
	//TEST("%+d", INT_MAX);
	//TEST("% d", INT_MAX);
	//TEST("% .*d", 10, -10);
	//TEST("%+.*d", 10, 10);
	//TEST("%.*U", 10, 124098);
	//TEST("%#X", 0xdeadbeef);
	//TEST("%#.*X", 15, 0xdeadbeef);
	//TEST("%#15X", 0xdeadbeef);
	//TEST("%10X", 0xdeadbeef);
	//TEST("%#015X", 0xdeadbeef);
	//TEST("%#x", 0xcafebabe);
	//TEST("%#o", 0777);
	//TEST("%d", 10);
	//TEST("%U", 908080909);
	//TEST("%*.*x", 100, 100, 0xcafebaba);
	////TEST("%jd", INTMAX_MAX);
	//TEST("\n");
	//TEST("%%\n");
	//TEST("%hhd\n", (char)-42);
	//TEST("%hd\n", (short)-42);
	//TEST("%d\n", -42);
	//TEST("%d%d\n", 42, 41);
	//TEST("%d%d%d\n", 42, 43, 44);
	//TEST("%ld\n", l);
	//TEST("%lld\n", ll);
	//TEST("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
	//TEST("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
	//TEST("%jd %zd %u %o %#08x\n", im, (size_t)i, i, 40, 42);
	//TEST("%x %#X %S %s%s\n", 1000, 1000, L"ݗݜशব", "test", "test2");
	//TEST("%s%s%s\n", "test", "test", "test");
	//TEST("%C\n", 15000);
	//TEST("%x\n", -42);
	//TEST("%X\n", -42);
	//TEST("%hhx\n", (unsigned long)4294967296);
	//TEST("%X\n", (unsigned long)4294967296);
	//TEST("%hhd\n", -129);

	TEST("{%05.s}", 0);
	ft_printf("Bonus:\n");
	ft_printf("0b11110000 == %b\n", 0b11110000);
	return (0);
}
