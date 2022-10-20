all: Trabalho1.o
    gcc Trabalho1.o principal.c -o principal

Trabalho1.o: Trabalho1.h
    gcc -c Trabalho1.c

clean:
    rm -rf *.o
    rm -rf principal