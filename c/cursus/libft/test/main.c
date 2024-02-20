#include "../libft.h"
#include "lib/greatest/greatest.h"

/**
 * ft_isalpha
 * */
TEST x_sould_be_alpha(void)
{  
  int test_input[4] = {'a', 'b', '3', '!'};

  ASSERT_NEQ(0, ft_isalpha(test_input[0]));
  ASSERT_NEQ(0, ft_isalpha(test_input[1]));
  ASSERT_EQ(0, ft_isalpha(test_input[2]));
  ASSERT_EQ(0, ft_isalpha(test_input[3]));

  PASS();
}

GREATEST_MAIN_DEFS();

SUITE(ft_suite)
{
    RUN_TEST(x_sould_be_alpha);
}

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    
    RUN_SUITE(ft_suite);

    GREATEST_MAIN_END();
}
