all: s21_matrix_oop.a

s21_matrix_oop.a:
	g++ -c s21_matrix_oop.cc
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

test:
	g++ s21_matrix_oop.cc test.cc -lgtest -o test
	-./test
	rm -rf test

clean:
	rm -rf *.o *.a test *.gcda *.gcno report *.info

style:
	clang-format -n -style=google *.cc *.h
	clang-format -i -style=google *.cc *.h
