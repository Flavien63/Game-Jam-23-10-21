CC = gcc
OPT = -c -Wextra -Wall -gcc
#SDL2 = -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

jeu : main.o lunaire.o
	$(CC) main.o lunaire.o

main.o : main.c lunaire.o
	$(CC) $(OPT) main.c

lunaire.o : lunaire.c lunaire.h
	$(CC) $(OPT) lunaire.c