/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:36:23 by evlasov           #+#    #+#             */
/*   Updated: 2018/09/29 19:36:24 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main()
{
//	char	*str;



	ft_printf("%04i\n", 42);
	ft_printf("%05i\n", 42);
	ft_printf("%0i\n", 42);
	ft_printf("%0d\n", 0000042);

	//05i 42 == |00000|
	//%0i 42 == ||
	//%0d 0000042 == ||
//	char		*tmp = "Test";
	// ft_printf("%5.2s is a string\n", "");
	// printf("%5.2s is a string\n", "");
	// ft_printf("@moulitest: %s", NULL);
	// printf("@moulitest: %s", NULL);

	// ft_printf("%.2c\n", NULL);
	// printf("%.2c\n", NULL);
	// ft_printf("@moulitest: %c\n", 0);
	// printf("@moulitest: %c\n", 0);
	// ft_printf("%2c\n", 0);
	// printf("%2c\n", 0);
	// ft_printf("null %c and text\n", 0);
	// printf("null %c and text\n", 0);
	// ft_printf("% c\n", 0);
	// printf("% c\n", 0);


	// ft_printf("string: |%s|\n", "salut");
	// printf("string: |%s|\n", "salut");
	// ft_printf("string + preci: |%.4s|\n", "salut");
	// printf("string + preci: |%.4s|\n", "salut");
	// ft_printf("integer: |%d|\n", 12);
	// printf("integer: |%d|\n", 12);
	// ft_printf("negative integer: |%d|\n", -12);
	// printf("negative integer: |%d|\n", -12);
	// ft_printf("negative integer + preci: |%.4d|\n", -12);
	// printf("negative integer + preci: |%.4d|\n", -12);


	


// //	ft_printf("%5%");
// 	printf("%5%\n");
// //	ft_printf("%-5%");
// 	printf("%-5%\n");
// //	ft_printf("%.0%");
// 	printf("%.0%\n");
// //	ft_printf("%   %", "test");
// 	printf("%   %\n", "test");
// 	ft_printf("%jx\n", -4294967296);
// 	printf("%jx\n", -4294967296);
	//ft_printf("@moulitest: %#05.u %.0U\n", 42, 0);
	//printf("@moulitest: %#05.u %.0U\n", 42, 0);
	// ft_printf("%jx\n", -4294967297);
	// printf("%jx\n", -4294967297);
	// ft_printf("%010x\n", 542);
	// printf("%010x\n", 542);
	// ft_printf("%#x\n", 42);
	// printf("%#x\n", 42);
	// ft_printf("%#llx\n", 9223372036854775807);
	// printf("%#llx\n", 9223372036854775807);
	// ft_printf("%#x\n", 42);
	// printf("%#x\n", 42);
	// ft_printf("%#X", 42);
	// ft_printf("%#08x", 42);
	// ft_printf("%#-08x", 42);
	// ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	// ft_printf("@moulitest: %.x %.0x", 0, 0);
	// ft_printf("@moulitest: %5.x %5.0x", 0, 0);
	// ft_printf("%5.2s is a string", "");
	// ft_printf("@moulitest: %s", NULL);
	// ft_printf("%.2c", NULL);
	// ft_printf("%s %s", NULL, string);
	// ft_printf("@moulitest: %c", 0);
	// ft_printf("%2c", 0);
	// ft_printf("null %c and text", 0);
	// ft_printf("% c", 0);
	// ft_printf("%05o", 42);
	// ft_printf("%-#6o", 2500);
	// ft_printf("@moulitest: %.o %.0o", 0, 0);
	// ft_printf("@moulitest: %5.o %5.0o", 0, 0);
	// ft_printf("@moulitest: %.10o", 42);
	// ft_printf("% d", 42);
	// ft_printf("%+d", 42);
	// ft_printf("%+d", 0);
	// ft_printf("% +d", 42);
	// ft_printf("%+ d", 42);
	// ft_printf("%  +d", 42);
	// ft_printf("%+  d", 42);
	// ft_printf("% ++d", 42);
	// ft_printf("%++ d", 42);
	// ft_printf("%05d", 42);
	// ft_printf("%0+5d", 42);
	// ft_printf("%05d", -42);
	// ft_printf("%0+5d", -42);
	// ft_printf("%4.15d", 42);
	// ft_printf("%.10d", 4242);
	// ft_printf("%10.5d", 4242);
	// ft_printf("%-10.5d", 4242);
	// ft_printf("% 10.5d", 4242);
	// ft_printf("%+10.5d", 4242);
	// ft_printf("%-+10.5d", 4242);
	// ft_printf("%03.2d", -1);
	// ft_printf("@moulitest: %.10d", -42);
	// ft_printf("@moulitest: %.d %.0d", 0, 0);
	// ft_printf("@moulitest: %5.d %5.0d", 0, 0);
	// ft_printf("%015u", 4294967295);
	// ft_printf("%lu", -42);
	// ft_printf("%hU", 4294967296);
	// ft_printf("%U", 4294967296);
	// ft_printf("@moulitest: %.5u", 42);


	// int		j = 45;
	// ft_printf("hello (ft_p)!!!:%012.1i:\n", j);
	// printf("hello (pr_f)!!!:%012.1i:\n", j);
	// ft_printf("hello (ft_p)!!!:%012.5i:\n", j);
	// printf("hello (pr_f)!!!:%012.5i:\n", j);
	// ft_printf("hello (ft_p)!!!:%012.1i:\n", j);
	// printf("hello (pr_f)!!!:%012.1i:\n", j);
	// ft_printf("hello (ft_p)!!!:%012.5i:\n", j);
	// printf("hello (pr_f)!!!:%012.5i:\n", j);

	// char	*k = "Test";
	// ft_printf("hello (ft_p)!!!:%+12.1s:\n", k);
	// printf("hello (pr_f)!!!:%+12.1s:\n", k);
	// ft_printf("hello (ft_p)!!!:%- 12.5s:\n", k);
	// printf("hello (pr_f)!!!:%- 12.5s:\n", k);
	// ft_printf("hello (ft_p)!!!:% 12.1s:\n", k);
	// printf("hello (pr_f)!!!:% 12.1s:\n", k);
	// ft_printf("hello (ft_p)!!!:%012.5s:\n", k);
	// printf("hello (pr_f)!!!:%012.5s:\n", k);


	// int	i = 42;
	// ft_printf("hello (ft_p)!!!:%+12.1X:\n", i);
	// printf("hello (pr_f)!!!:%+12.1X:\n", i);
	// ft_printf("hello (ft_p)!!!:%-#12.5X:\n", i);
	// printf("hello (pr_f)!!!:%-#12.5X:\n", i);

	// ft_printf("hello (ft_p)!!!:%-#12.4X:\n", i);
	// printf("hello (pr_f)!!!:%-#12.4X:\n", i);
	// ft_printf("hello (ft_p)!!!:%-#12.8X:\n", i);
	// printf("hello (pr_f)!!!:%-#12.8X:\n", i);


	// ft_printf("hello (ft_p)!!!:%012.1X:\n", i);
	// printf("hello (pr_f)!!!:%012.1X:\n", i);
	// ft_printf("hello (ft_p)!!!:%#12.5X:\n", i);
	// printf("hello (pr_f)!!!:%#12.5X:\n", i);



	// ft_printf("ooooo (ft_p)!!!:%+12.1o:\n", i);
	// printf("ooooo (pr_f)!!!:%+12.1o:\n", i);
	// ft_printf("hello (ft_p)!!!:%-#12.5o:\n", i);
	// printf("hello (pr_f)!!!:%-#12.5o:\n", i);

	// ft_printf("hello (ft_p)!!!:%-#12.4o:\n", i);
	// printf("hello (pr_f)!!!:%-#12.4o:\n", i);
	// ft_printf("hello (ft_p)!!!:%-#12.8o:\n", i);
	// printf("hello (pr_f)!!!:%-#12.8o:\n", i);


	// ft_printf("hello (ft_p)!!!:%012.1o:\n", i);
	// printf("hello (pr_f)!!!:%012.1o:\n", i);
	// ft_printf("hello (ft_p)!!!:%#12.5o:\n", i);
	// printf("hello (pr_f)!!!:%#12.5o:\n", i);




	// ft_printf("uuuuu (ft_p)!!!:%+12.1u:\n", i);
	// printf("uuuuu (pr_f)!!!:%+12.1u:\n", i);
	// ft_printf("uuuuu (ft_p)!!!:%+12u:\n", i);
	// printf("uuuuu (pr_f)!!!:%+12u:\n", i);
	// ft_printf("hello (ft_p)!!!:%-#12.5u:\n", i);
	// printf("hello (pr_f)!!!:%-#12.5u:\n", i);

	// ft_printf("hello (ft_p)!!!:%-#12.4u:\n", i);
	// printf("hello (pr_f)!!!:%-#12.4u:\n", i);
	// ft_printf("hello (ft_p)!!!:%-#12.8u:\n", i);
	// printf("hello (pr_f)!!!:%-#12.8u:\n", i);


	// ft_printf("hello (ft_p)!!!:%012.1u:\n", i);
	// printf("hello (pr_f)!!!:%012.1u:\n", i);
	// ft_printf("hello (ft_p)!!!:%#12.5u:\n", i);
	// printf("hello (pr_f)!!!:%#12.5u:\n", i);



	// char	c = 'c';
	// ft_printf("ccccc (ft_p)!!!:%+12.1c:\n", c);
	// printf("ccccc (pr_f)!!!:%+12.1c:\n", c);
	// ft_printf("ccccc (ft_p)!!!:%+12c:\n", c);
	// printf("ccccc (pr_f)!!!:%+12c:\n", c);
	// ft_printf("hello (ft_p)!!!:%-#12.5c:\n", c);
	// printf("hello (pr_f)!!!:%-#12.5c:\n", c);

	// ft_printf("hello (ft_p)!!!:%-#12.4c:\n", c);
	// printf("hello (pr_f)!!!:%-#12.4c:\n", c);
	// ft_printf("hello (ft_p)!!!:%-#12.8c:\n", c);
	// printf("hello (pr_f)!!!:%-#12.8c:\n", c);


	// ft_printf("hello (ft_p)!!!:%012.1c:\n", c);
	// printf("hello (pr_f)!!!:%012.1c:\n", c);
	// ft_printf("hello (ft_p)!!!:%#12.5c:\n", c);
	// printf("hello (pr_f)!!!:%#12.5c:\n", c);


	// ft_printf("hello (ft_p)!!!:%+12.1p:\n", k);
	// printf("hello (pr_f)!!!:%+12.1p:\n", k);
	// ft_printf("hello (ft_p)!!!:%- 12.5p:\n", k);
	// printf("hello (pr_f)!!!:%- 12.5p:\n", k);
	// ft_printf("hello (ft_p)!!!:% 12.1p:\n", k);
	// printf("hello (pr_f)!!!:% 12.1p:\n", k);
	// ft_printf("hello (ft_p)!!!:%012.5p:\n", k);
	// printf("hello (pr_f)!!!:%012.5p:\n", k);

	// ft_printf("hello world!!!%li  %lli\n", 123456789011, 9223372036854775807, 345);
	// printf("prf = hello world!!!%li  %lli\n", 123456789011, 9223372036854775807, 345);


//	printf("hello world!!!%S %s\n", s, a);
	//system("leaks -quiet a.out");
	return (0);
}
