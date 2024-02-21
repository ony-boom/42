#include "../libft.h"
#include "lib/greatest/greatest.h"
#include <stdio.h>
#include <string.h>

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define RESET   "\x1B[0m"

/**
 * ft_isalpha
 * */
TEST x_sould_be_alpha(void)
{  
  printf("ft_isalpha: ");
  int test_input[4] = {'a', 'b', '3', '!'};

  ASSERT_NEQ(0, ft_isalpha(test_input[0]));
  ASSERT_NEQ(0, ft_isalpha(test_input[1]));
  ASSERT_EQ(0, ft_isalpha(test_input[2]));
  ASSERT_EQ(0, ft_isalpha(test_input[3]));

  printf(GREEN "OK\n" RESET);

  PASS();

}

/**
 * ft_memmove
 * */
TEST should_pass_even_overlaping(void)
{
  printf("\n");

  printf("ft_memmove: ");
  char input[100] = "Hello, Ony!";
  char *dest = input+3; 

  ASSERT_EQ(memmove(dest, input, 4), ft_memmove(dest, input, 4));

  printf(GREEN "OK\n" RESET);
  
  PASS();
}

/**
 * ft_strlcat
 * */
TEST should_concat_like_the_original(void)
{
  printf("\n");

  printf("ft_strlcat: ");

  char dest[100] = "Left here, ";
  char *src = "alone";

  ft_strlcat(dest, src, 17);
  ASSERT_STR_EQ("Left here, alone", dest);

  char d2[4] = "ony";
  char s2[1] = "p";

  ft_strlcat(d2, s2, 1);

  ASSERT_MEM_EQ("ony", d2, 4);

  char d3[11] = "sunho";
  char s3[16] = " shadow monarch";

  ft_strlcat(d3, s3, 14);

  ASSERT_STR_EQ("sunho shadow ", d3);

  printf(GREEN "OK\n" RESET);

  PASS();
}

/**
 * ft_strchr
 * */
TEST should_return_occurence(void)
{
  printf("\n");

  printf("ft_strchr: ");

  char src[] = "Still think that Ms Kobayashi's dragon maid is a peak anime";
  char c = 'M';

  ASSERT_STR_EQ(strchr(src, c), ft_strchr(src, c));

  char *s2 = "Hello";
  char c2 = '\0';
  
  ASSERT_MEM_EQ(strchr(s2, c2), ft_strchr(s2, c2), 0);

  printf(GREEN "OK\n" RESET);

  PASS();
}

GREATEST_MAIN_DEFS();

SUITE(libft_test)
{
    RUN_TEST(x_sould_be_alpha);
    RUN_TEST(should_pass_even_overlaping);
    RUN_TEST(should_concat_like_the_original);
    RUN_TEST(should_return_occurence);
}

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    
    RUN_SUITE(libft_test);

    GREATEST_MAIN_END();
}
