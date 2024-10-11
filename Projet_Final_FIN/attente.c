
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "attente.h"
#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OBSTACLES 100



void attente(int milliseconds) {
    clock_t start_time = clock();
    while ((clock() - start_time) * 1000 / CLOCKS_PER_SEC < milliseconds) {
    }
}