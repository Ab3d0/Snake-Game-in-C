but: snake

OFILES= main.o \
	afficherScore.o\
	temp.o\
	gameover.o\
	jeu.o\
	attente.o\
        damier.o\
	chargement.o\
	record.o

CC= gcc
CFLAGS= -ansi -pedantic -lgraph -g

main.o : afficherScore.h temp.h gameover.h  attente.h  chargement.h jeu.h damier.h record.h

afficherScore.o : afficherScore.h

temp.o : temp.h

gameover.o  : gameover.h record.h

attente.o : attente.h

jeu.o : jeu.h gameover.h

chargement.o : chargement.h

damier.o : damier.h

record.o : record.h 


snake : $(OFILES)
	    $(CC) $(CFLAGS) -o snake $(OFILES)

clean :
	-rm -f $(OFILES) snake

run : snake
	./snake

.PHONY : nut clean 
