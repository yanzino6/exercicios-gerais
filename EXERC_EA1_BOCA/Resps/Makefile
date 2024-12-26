all: geraos main

geraos: registro.c jogador.c servidor.c main.c
	gcc -c jogador.c registro.c servidor.c

main: registro.o jogador.o servidor.o main.o
	gcc registro.o jogador.o servidor.o main.o -o main

