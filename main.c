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
setlocale(LC_ALL, "");
int		i;
i = 0;
// >>>> 52_min_width_flag_zero.spec.c  printf("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B")
// >>>> 62_flag_space.spec.c -------- [FAIL] ............SF. [SEGV] SNullString_spaceFlag -> (null)
// >>>> 72_precision_for_sS.spec.c --  printf("%4.s", "42")
// >>>> 79_precision_mixed_with_flags  printf("%.p, %.0p", 0, 0)


	// printf("U#07\n");
	// i = ft_printf("%S\n", L"米");
	// printf("i = %i\n", i);
	// i = printf("%S\n", L"米");
	// printf("i = %i\n", i);
	// printf("U#17\n");
	// i = ft_printf("%C\n", L'猫');
	// printf("i = %i\n", i);
	// i = printf("%C\n", L'猫');
	// printf("i = %i\n", i);
	// printf("U#18\n");
	// ft_printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	// printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	// printf("U#40\n");
	// ft_printf("%lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
	// printf("%lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
	// printf("U#43\n");
	// ft_printf("%hhC, %hhC\n", 0, L'Á±≥');
	// printf("%hhC, %hhC\n", 0, L'Á±≥');
	// printf("#50\n");
	// ft_printf("{%5p}\n", 0);
	// printf("{%5p}\n", 0);
	// printf("U#52\n");
	// ft_printf("{%030S}\n", L"我是一只猫。");
	// printf("{%030S}\n", L"我是一只猫。");
	// printf("#72\n");
	// ft_printf("%.4S\n", L"我是一只猫。");
	// printf("%.4S\n", L"我是一只猫。");
	// printf("#79\n");
	// i = ft_printf("{%05.S}\n", L"42 c est cool");
	// printf("i = %i\n", i);
	// i = printf("{%05.S}\n", L"42 c est cool");
	// printf("i = %i\n", i);

//	ft_printf("printf ret = %d\n", ft_printf("%d Kashim a %d histoires à raconter Il fait au moins %d %d %d %d", 0000042, 35, 35));
//	printf("printf ret = %d\n", printf("%d Kashim a %d histoires à raconter Il fait au moins %d %d %d %d", 0000042, 35, 35));
	// ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	// printf("%%04.2i 42 == |%04.2i|\n", 42);

	// ft_printf("%15.4d\n", 424242);
	// printf("%15.4d\n", 424242);


	ft_printf("%s\n", "abc");
	ft_printf("@moulitest: %s\n", NULL);
	printf("@moulitest: %s\n", NULL);
	ft_printf("%s %s\n", NULL, "string");
	printf("%s %s\n", NULL, "string");
	// printf("%s\n", "test_C");
	// ft_printf("f%C", L'a');
	// ft_printf("f%C", L'b');
//	printf("p%C", L'a');
//	printf("p%C\n", L'b');
	// printf("%s\n", "test_S");
	// ft_printf("%ls\n", L"abc");
	// printf("%ls\n", L"abc");
	// printf("%s\n", "test_mix2");
//	ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c\n", );


	system("leaks -quiet a.out");
	return (0);
}
