CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g
LDFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage

all: my_string.a

my_string.a:
	$(CC) $(CFLAGS) -c *.c sprintf/*.c
	ar rc my_string.a *.o
	ranlib my_string.a

test:
	$(CC) $(CFLAGS) $(LDFLAGS) *.c sprintf/*.c tests/*.c -lm `pkg-config --cflags --libs check`
	./a.out
	rm a.out

gcov_report:
	$(CC) $(CFLAGS) $(LDFLAGS) $(GCOVFLAGS) *.c sprintf/*.c tests/*.c -o gcov_main -lm `pkg-config --cflags --libs check`
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov*

style_check:
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n */*.c */*.h

cpk:
	cppcheck *.[ch]

rebuild: clean all
