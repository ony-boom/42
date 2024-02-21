test: build_test
	@./test | ./lib/greatest/contrib/greenest

build_test: main.c
	@cc -g -Wall -Werror main.c ../ft_*.c -o test

clean:
	rm -f test
	
