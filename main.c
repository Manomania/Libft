/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:51:48 by maximart          #+#    #+#             */
/*   Updated: 2024/11/04 13:43:35 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_freecontent(void *content)
{
	free(content);
}
void	ft_print_content(void *content)
{
		printf("content : %s\n", (char *)content);
}
void	*ft_add_content(void *content)
{
	char	*str = (char *)content;
	size_t	len = ft_strlen(str);
	char	*new_str = malloc(len + 2);
	if (new_str)
	{
		strcpy(new_str, str);
		new_str[len] = '!';
		new_str[len +1] = '\0';
	}
	return (new_str);
}
void ft_to_upper_if_odd(unsigned int francis, char *ronald)
{
	if (francis % 2 != 0) {
		*ronald = ft_toupper(*ronald);
	}
}

int main (void)
{
	// isalpha
	printf("\n ---FT_ISALPHA---\n");
	printf("4 is alpha : %d, real : %d\n", ft_isalpha('4'), isalpha('4'));
	printf("a is alpha : %d, real : %d\n", ft_isalpha('a'), isalpha('a'));
	printf("Z is alpha : %d, real : %d\n", ft_isalpha('Z'), isalpha('Z'));
	printf("SPACE is alpha : %d, real : %d\n", ft_isalpha(' '), isalpha(' '));

	// isdigit
	printf("\n ---FT_ISDIGIT---\n");
	printf("4 is digit : %d, real : %d\n", ft_isdigit('4'), isdigit('4'));
	printf("a is digit : %d, real : %d\n", ft_isdigit('a'), isdigit('a'));
	printf("Z is digit : %d, real : %d\n", ft_isdigit('Z'), isdigit('Z'));
	printf("SPACE is digit : %d, real : %d\n", ft_isdigit(' '), isdigit(' '));

	// isalnum
	printf("\n ---FT_ISALNUM---\n");
	printf("4 is alnum : %d, real : %d\n", ft_isalnum('4'), isalnum('4'));
	printf("a is alnum : %d, real : %d\n", ft_isalnum('a'), isalnum('a'));
	printf("Z is alnum : %d, real : %d\n", ft_isalnum('Z'), isalnum('Z'));
	printf("SPACE is alnum : %d, real : %d\n", ft_isalnum(' '), isalnum(' '));

	// isascii
	printf("\n ---FT_ISASCII---\n");
	printf("4 is ascii : %d, real : %d\n", ft_isascii('4'), isascii('4'));
	printf("a is ascii : %d, real : %d\n", ft_isascii('a'), isascii('a'));
	printf("Z is ascii : %d, real : %d\n", ft_isascii('Z'), isascii('Z'));
	printf("SPACE is ascii : %d, real : %d\n", ft_isascii(' '), isascii(' '));
	printf("SYMBOL is ascii : %d, real : %d\n", ft_isascii(0xa2), isascii(0xa2));

	// isprint
	printf("\n ---FT_ISPRINT---\n");
	printf("4 is print : %d, real : %d\n", ft_isprint(31), isprint(31));
	printf("a is print : %d, real : %d\n", ft_isprint('a'), isprint('a'));
	printf("Z is isprint : %d, real : %d\n", ft_isprint('Z'), isprint('Z'));
	printf("SPACE is print : %d, real : %d\n", ft_isprint(' '), isprint(' '));
	printf("SYMBOL is print : %d, real : %d\n", ft_isprint(0xa2), isprint(0xa2));

	// strlen
	printf("\n ---FT_STRLEN---\n");
	printf("\"Hello, World!\" ft_strlen : %ld, real : %ld\n", ft_strlen("Hello, World!"), strlen("Hello, World!"));
	printf("\"42\" ft_strlen : %ld, real : %ld\n", ft_strlen("42"), strlen("42"));
	printf("\"\" ft_strlen : %ld, real : %ld\n", ft_strlen(""), strlen(""));

	// memset
	printf("\n ---FT_MEMSET---\n");
	char	str_real[50] = "Hello, World!";
	memset(str_real, '!', 5);
	char	str_test[50] = "Hello, World!";
	ft_memset(str_test, '!', 5);
	printf("\"Hello 42\" ft_memset('!', 20) : %s, real : %s\n", str_test, str_real);

	// bzero
	printf("\n ---FT_BZERO---\n");
	char	str1_real[50] = "Hello World!";
	ft_memset(str1_real,0, 2);
	char	str1_test[50] = "Hello World!";
	ft_bzero(str1_test, 2);
	printf("\"Hello World!\" ft_bzero(5) : %s, 3th char : %c, real : %s, 3th char : %c\n", str1_real, str1_real[2], str1_test, str1_test[2]);

	// memcpy
	printf("\n ---FT_MEMCPY---\n");
	char	src_real[50] = "Hello,World!";
	char	src_test[50] = "Hello,World!";
	char	dst_real[50] = "42";
	char	dst_test[50] = "42";
	printf("src content : '%s', dst content : '%s'\n", src_real, dst_real);
	memcpy(dst_real, src_real, 5);
	ft_memcpy(dst_test, src_test, 5);
	printf("n = 5\nft_memcpy : '%s'\nmemcpy : '%s'\n", dst_test, dst_real);

	// memmove
	printf("\n ---FT_MEMMOVE---\n");
	char	buffer1[] = "abcdefghijklmnopqrstuvwxyz";
	char	buffer2[] = "BONJOUR";
	printf("	     abcdefghijklmnopqrstuvwxyz\n");
	ft_memmove(buffer1, buffer2, 5);
	printf("(buffer + 5, buffer, 1)\nft_memmove : %s\nmemmove :    %s\n", buffer1, buffer2);

	// strlcpy
	printf("\n ---FT_STRLCPY---\n");
	char	src_realcpy[] = "Hello,World!";
	char	dst_realcpy[50];
	char	dst_testcpy[50];
	int	src_cpy = ft_strlcpy(dst_testcpy, src_realcpy, 5);
	// int	src_cpy2 = strlcpy(dst_realcpy, src_realcpy, 5);
	printf("ft_strlcpy :\nCopied : '%s' into '%s', len : %d\n", src_realcpy, dst_testcpy, src_cpy);
	// printf("strlcpy :\nCopied : '%s' into '%s', len : %d\n", src_realcpy, dst_realcpy, src_cpy2);

	// strlcat
	printf("\n ---FT_STRLCAT---\n");
	char src_realcat[] = "Hello,";
	char dest_realcat[] = "World!";
	char dest_testcat[] = "les copains";
	size_t len1 = ft_strlcat(dest_testcat, src_realcat, 20);
	// size_t len2 = strlcat(dest_realcat, src_realcat, 20);
	printf("ft_strlcat :\nSrc: '%s'\nDest: '%s'\nLength: %zu\n", src_realcat, dest_testcat, len1);
	// printf("strlcat :\nSrc: '%s'\nDest: '%s'\nLength: %zu\n", src_realcat, dest_realcat, len2);

	// toupper
	printf("\n---FT-TOUPPER---\n");
	printf("a to upper : %d, real : %d\n", ft_toupper('a'), toupper('a'));
	printf("b to upper : %d, real : %d\n", ft_toupper('b'), toupper('b'));
	printf("A to upper : %d, real : %d\n", ft_toupper('A'), toupper('A'));
	printf("B to upper : %d, real : %d\n", ft_toupper('B'), toupper('B'));

	// tolower
	printf("\n---FT-TOLOWER---\n");
	printf("a to lower : %d, real : %d\n", ft_tolower('a'), tolower('a'));
	printf("b to lower : %d, real : %d\n", ft_tolower('b'), tolower('b'));
	printf("A to lower : %d, real : %d\n", ft_tolower('A'), tolower('A'));
	printf("B to lower : %d, real : %d\n", ft_tolower('B'), tolower('B'));

	// strchr
	printf("\n---FT-STRCHR---\n");
	char	src_strchr[] = "Kayak";
	printf("src : %s & you have to found the first: 'a'\n", src_strchr);
	printf("ft_strchr : %s\nstrchr : %s\n", ft_strchr(src_strchr, 'a'), strchr(src_strchr, 'a'));

	// strrchr
	printf("\n---FT-STRRCHR---\n");
	char	src_strrchr[] = "Kayak";
	printf("src : %s & you have to found the last: 'a'\n", src_strrchr);
	printf("ft_strrchr : %s\nstrrchr : %s\n", ft_strrchr(src_strrchr, 'a'), strrchr(src_strrchr, 'a'));

	// strncmp
	printf("\n---FT-STRNCMP---\n");
	char	str1_strncmp[6] = "Hello";
	char	str2_strncmp[5] = "Helo";
	printf("ft_strncmp 2: %d\n", (ft_strncmp(str1_strncmp, str2_strncmp, 2)));
	printf("strncmp 2: %d\n", (strncmp(str1_strncmp, str2_strncmp, 2)));
	printf("ft_strncmp 4: %d\n", (ft_strncmp(str1_strncmp, str2_strncmp, 4)));
	printf("strncmp 4: %d\n", (strncmp(str1_strncmp, str2_strncmp, 4)));

	// memchr
	printf("\n---FT-MEMCHR---\n");
	char	str1_memchr[6] = "Hello";
	printf("ft_memchr 2: %p\n", (ft_memchr(str1_memchr, 'l', 2)));
	printf("memchr 2: %p\n", (memchr(str1_memchr, 'l', 2)));
	printf("ft_memchr 4: %p\n", (ft_memchr(str1_memchr, 'l', 4)));
	printf("memchr 4: %p\n", (memchr(str1_memchr, 'l', 4)));

	// memcmp
	printf("\n---FT-MEMCMP---\n");
	char	str1_memcmp[6] = "Hello";
	char	str2_memcmp[5] = "Helo";
	printf("ft_memcmp 2: %d\n", (ft_memcmp(str1_memcmp, str2_memcmp, 2)));
	printf("memcmp 2: %d\n", (memcmp(str1_memcmp, str2_memcmp, 2)));
	printf("ft_memcmp 4: %d\n", (ft_memcmp(str1_memcmp, str2_memcmp, 4)));
	printf("memcmp 4: %d\n", (memcmp(str1_memcmp, str2_memcmp, 4)));

	// strnstr
	printf("\n---FT-STRNSTR---\n");
	printf("ft_strnstr 4 : %s\n", ft_strnstr("hello", "el", 4));
	// printf("strnstr 1 : %s\n", strnstr(str1_strnstr, str2_strnstr, 1));

	// atoi
	printf("\n---FT-ATOI---\n");
	printf("ft_atoi : %d\n", ft_atoi("Hello"));
	printf("atoi : %d\n", atoi("Hello"));
	printf("ft_atoi : %d\n", ft_atoi("-1234abcd"));
	printf("atoi : %d\n", atoi("-1234abcd"));
	printf("ft_atoi : %d\n", ft_atoi("+1234abcd"));
	printf("atoi : %d\n", atoi("+1234abcd"));

	// calloc
	printf("\n---FT-CALLOC---\n");
	char	strcalloc[] = "Hello";
	char	*colloc;
	char	*ft_colloc;
	printf("String : '%s'\n", strcalloc);
	ft_colloc = ft_calloc(ft_strlen(strcalloc) + 1, sizeof(char));
	if (!ft_colloc)
		return (1);
	printf("ft_calloc = '%s'\n", ft_colloc);
	free(ft_colloc);
	colloc = calloc(strlen(strcalloc) + 1, sizeof(char));
	if (!colloc)
		return (1);
	printf("calloc = '%s'\n", colloc);
	free(colloc);
	printf("There is 5 '\\0' but cannot show it on terminal.\n");

	// strdup
	printf("\n---FT-STRDUP---\n");
	printf("ft_strdup : '%s'\n", ft_strdup("Hello"));
	printf("strdup : '%s'\n", strdup("Hello"));

	// substr
	printf("\n---FT-SUBSTR---\n");
	printf("ft_substr 0,5 : '%s'\n", ft_substr("Hello", 0, 5));
	// printf("substr : '%s'\n", substr("Hello", 0, 5));
	printf("ft_substr 2,5 : '%s'\n", ft_substr("Hello", 2, 5));

	// strjoin
	printf("\n---FT-STRJOIN---\n");
	printf("ft_strjoin : '%s'\n", ft_strjoin("Hello,", "World!"));
	// printf("strjoin : '%s'\n", strjoin("Hello,", "World!"));
	printf("ft_strjoin : '%s'\n", ft_strjoin("s1", "s2"));
	// printf("strjoin : '%s'\n", strjoin("s1", "s2"));

	// strtrim
	printf("\n---FT_STRTRIM----\n");
	printf("ft_strtrim : '%s'\n", ft_strtrim("    Hello, World!    ", " "));
	// printf("strtrim : '%s'\n", strtrim("    Hello, World!    ", " "));

	// split
	printf("\n---FT-SPLIT---\n");
	int i;
	char	**result_split = ft_split("Hello, World!", ',');
	for (i = 0; result_split[i]; i++)
	{
		printf("%s", result_split[i]);
	}
	printf("\n");

	// itoa
	printf("\n---FT-ITOA---\n");
	printf("ft_itoa 1: '%s'\n", ft_itoa('1'));
	// printf("itoa 1: '%s'\n", itoa('1'));
	printf("ft_itoa 2: '%s'\n", ft_itoa('2'));
	// printf("itoa 2: '%s'\n", itoa('2'));
	printf("ft_itoa 3: '%s'\n", ft_itoa('3'));
	// printf("itoa 3: '%s'\n", itoa('3'));

	// strmapi
	printf("\n---FT_STRMAPI----\n");
	char	ft_to_upper(unsigned int albert, char gerard)
	{
		(void)albert;
		return ft_toupper(gerard);
	}
	char	str_mapi[] = "Hello,World!";
	printf("ft_strmapi : '%s'\n", ft_strmapi(str_mapi, ft_to_upper));
	// printf("strmapi : '%s'", strmapi(str_mapi, ft_to_upper));

	// striteri
	printf("\n---FT_STRITERI----\n");
	char	str_iteri[] = "Hello,World!";
	ft_striteri(str_iteri, ft_to_upper_if_odd);
	printf("ft_striteri : '%s'\n", str_iteri);
	printf("striteri : '%s'\n", str_iteri);

	// putchar_fd
	printf("\n---FT_PUTCHAR_FD----\n");
	ft_putchar_fd('A', 1);
	ft_putchar_fd('B', 2);
	// 0644 for permissions
	int fdchar = open("putchar.txt", O_WRONLY | O_CREAT, 0644);
	if (fdchar != -1)
	{
		ft_putchar_fd('C', fdchar);
		close(fdchar);
	}

	// putstr_fd
	printf("\n---FT_PUTSTR_FD----\n");
	ft_putstr_fd("Hello", 1);
	ft_putstr_fd("World!", 2);
	int fdstr = open("putstr.txt", O_WRONLY | O_CREAT, 0644);
	if (fdstr != -1)
	{
		ft_putstr_fd("12345", fdstr);
		close(fdstr);
	}
	// putendl_fd
	printf("\n---FT_PUTENDL_FD----\n");
	ft_putendl_fd("Hello", 1);
	ft_putendl_fd("World!", 2);
	int fdendl = open("putendl.txt", O_WRONLY | O_CREAT, 0644);
	if (fdendl != -1)
	{
		ft_putendl_fd("12345", fdendl);
		close(fdendl);
	}
	// putnbr_fd
	printf("\n---FT_PUTNBR_FD----\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	ft_putnbr_fd(2147483647, 2);
	printf("\n");
	int fdnbr = open("putnbr.txt", O_WRONLY | O_CREAT, 0644);
	if (fdnbr != -1)
	{
		ft_putnbr_fd(-2147483648, fdnbr);
		close(fdnbr);
	}

	//******************************************************************//
	// BONUS //
	//******************************************************************//

	// lstnew
	printf("\n---FT_LSTNEW----\n");
	char *content = "Hello, world!";
	t_list *node = ft_lstnew(content);
	if (node == NULL)
	{
		printf("Test failed\n");
		return 1;
	}
	if (node->content != content)
	{
		printf("Test failed: Node content.\n");
		return 1;
	}
	if (node->next != NULL)
	{
		printf("Test failed: Node's next is not NULL.\n");
		return 1;
	}
	printf("OK\n");
	printf("Content : '%s' & adress of the node : '%p'\n", content, node);
	free(node);

	// lstadd_front
	printf("\n---FT_LSTADD_FRONT----\n");
	char *content1 = "Hello,";
	t_list *head = ft_lstnew(content1);
	if (!head)
	{
		printf("Test failed\n");
		return 1;
	}
	char *content2 = "World!";
	t_list *new_node = ft_lstnew(content2);
	if (!new_node)
	{
		printf("Test failed\n");
		free(head);
		return 1;
	}
	ft_lstadd_front(&head, new_node);
	if (head != new_node)
	{
		printf("Test failed: Head is not pointing to the new node.\n");
		free(new_node);
		free(head);
		return 1;
	}
	if (new_node->next != head->next)
	{
		printf("Test failed: New node's next is not pointing to the original head.\n");
		free(new_node->next);
		free(new_node);
		return 1;
	}
	printf("New_node : '%p' & head : '%p' are the same\n",new_node, head);
	printf("OK, new_node is on the front\n");
	free(head->next);
	free(head);

	// lstsize
	printf("\n---FT_LSTSIZE----\n");
	t_list	*First = ft_lstnew("hello");
	t_list	*Second = ft_lstnew("dsfsA");
	t_list	*Third = ft_lstnew("Albert");
	First->next = Second;
	Second->next = Third;
	printf("Count from the begining : '%d'\n", ft_lstsize(First));
	printf("Count from the middle : '%d'\n", ft_lstsize(Second));
	printf("Count from the last : '%d'\n", ft_lstsize(Third));

	// lstlast
	printf("\n---FT_LSTLAST----\n");
	t_list	*contentlast = ft_lstnew("contenttop");
	t_list	*contentlast23 = ft_lstnew("contentmiddle");
	t_list	*contentlast31 = ft_lstnew("contentbot");
	contentlast->next = contentlast23;
	contentlast23->next = contentlast31;
	t_list	*fullcontent = 	ft_lstlast(contentlast);
	printf("%s\n", (char *)fullcontent->content);
	free(contentlast);
	free(contentlast23);
	free(contentlast31);

	// lstadd_back
	printf("\n---FT_LSTADD_BACK----\n");
	char *contentlast1 = "Hello,";
	t_list *firstlst = ft_lstnew(contentlast1);
	if (!firstlst)
	{
		printf("Test failed\n");
		return 1;
	}
	char *contentlast2 = "World!";
	t_list *secondlst = ft_lstnew(contentlast2);
	if (!secondlst)
	{
		printf("Test failed\n");
		free(firstlst);
		return 1;
	}
	char *contentlast3 = "oulala";
	t_list *thirdlst = ft_lstnew(contentlast3);
	if (!thirdlst)
	{
		printf("Test failed\n");
		free(thirdlst);
		return 1;
	}

	ft_lstadd_back(&firstlst, secondlst);
	t_list	*current1 = firstlst;
	int count1 = 0;
	printf("First : 'Hello,' & second : 'Word!'\n");
	while (current1 != NULL)
	{
		printf("Node %d content: %s\n", count1 + 1, (char *)current1->content);
		current1 = current1->next;
		count1++;
	}
	printf("\n");
	ft_lstadd_back(&thirdlst, firstlst);
	printf("First : 'oulala' & second : 'Hello,' & third  : 'World!'\n");
	t_list	*current = thirdlst;
	int count = 0;
	while (current != NULL)
	{
		printf("Node %d content: %s\n", count + 1, (char *)current->content);
		current = current->next;
		count++;
	}
	printf("\nOK, node 3 is on the back\n");
	free(secondlst);
	free(firstlst);
	free(thirdlst);

	// lsdelone
	printf("\n---FT_LSTDELONE----\n");
	t_list	*lstdelone1 = ft_lstnew(ft_strdup("Hello,"));
	t_list	*lstdelone2 = ft_lstnew(ft_strdup("World!"));
	if (!lstdelone1 || !lstdelone2)
	{
		free(lstdelone1);
		free(lstdelone2);
		return (1);
	}
	lstdelone1->next = lstdelone2;
	t_list *lstdelonecontent = lstdelone1;
	int h = 0;
	while (lstdelonecontent != NULL)
	{
		printf("Node %d content : %s\n", h + 1, (char *)lstdelonecontent->content);
		lstdelonecontent = lstdelonecontent->next;
		h++;
	}
	printf("\nAfter deleting node 2\n");
	ft_lstdelone(lstdelone2, ft_freecontent);
	lstdelone1->next = NULL;
	t_list	*lstdelonecontent2 = lstdelone1;
	int g = 0;
	while (lstdelonecontent2 != NULL)
	{
		printf("Node %d content : %s\n", g + 1, (char *)lstdelonecontent2->content);
		lstdelonecontent2 = lstdelonecontent2->next;
		g++;
	}
	free(lstdelone1);

	// lstclear
	printf("\n---FT_LSTCLEAR----\n");
	t_list	*lstclear1 = ft_lstnew("Hello,");
	t_list	*lstclear2 = ft_lstnew("World!");
	t_list	*lstclear3 = ft_lstnew("Oulala");
	lstclear1->next = lstclear2;
	lstclear2->next = lstclear3;
	t_list *lstclearcontent = lstclear1;
	int j = 0;
	while (lstclearcontent != NULL)
	{
		printf("Node %d content : %s\n", j + 1, (char *)lstclearcontent->content);
		lstclearcontent = lstclearcontent->next;
		j++;
	}
	ft_lstclear(&lstclearcontent, ft_freecontent);
	if (lstclearcontent == NULL)
		printf("\nClear\n");
	else
		printf("\nNot clear\n");
	free(lstclear1);
	free(lstclear2);
	free(lstclear3);
	free(lstclearcontent);

	// lstiter
	printf("\n---FT_LSTITER----\n");
	t_list	*lstiter1 = ft_lstnew("Hello,");
	t_list	*lstiter2 = ft_lstnew("World!");
	t_list	*lstiter3 = ft_lstnew("Oulala");
	lstiter1->next = lstiter2;
	lstiter2->next = lstiter3;
	ft_lstiter(lstiter1, ft_print_content);
	free(lstiter1);
	free(lstiter2);
	free(lstiter3);

	// lstmap
	printf("\n---FT_LSTMAP----\n");
	t_list	*lstmap1 = ft_lstnew("Hello,");
	t_list	*lstmap2 = ft_lstnew("World!");
	t_list	*lstmap3 = ft_lstnew("Oulala");
	lstmap1->next = lstmap2;
	lstmap2->next = lstmap3;
	printf("Avant :\n");
	ft_lstiter(lstmap1, ft_print_content);
	t_list *new_map = ft_lstmap(lstmap1, ft_add_content, ft_freecontent);
	printf("\nAprès :\n");
	ft_lstiter(new_map, ft_print_content);
	free(lstmap1);
	free(lstmap2);
	free(lstmap3);
	free(new_map);
	return (0);
}