CC=clang
CFlags=-Werror -Wfatal-errors -Wall -Wextra -x c

test: ./test-rational
	./test-rational

clean:
	rm -f ./number.o ./rational.o ./rational-test.o ./test-rational

./rational.o: ./rational.c ./rational.h ./number.h
	$(CC) $(CFlags) -c ./rational.c -o ./rational.o

./rational-test.o: ./test/rational.c
	$(CC) $(CFlags) -c ./test/rational.c -o ./rational-test.o

./test-rational: ./rational.o ./rational-test.o
	$(CC) ./rational.o ./rational-test.o -o ./test-rational
