test: sigfigs.o
	gcc -g -o test sigfigs.o

sigfigs.o: sigfigs.c sigfigs.h
	gcc -c sigfigs.c

run: test
	./test

clean:
	rm *.o