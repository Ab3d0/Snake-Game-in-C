#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "damier.h"

#define LARGEUR_FENETRE 1220
#define HAUTEUR_FENETRE 850
#define TAILLE_CELLULE 20
#define DELAI_MILLISECONDES 100
#define CYCLE 10000L
#define NB_POMMES 5
#define NB_OBSTACLES 100



void dessinerDamier() {
	int i,j;
	
    int cell_largeur = (LARGEUR_FENETRE - 20) / TAILLE_CELLULE;
    int cell_hauteur = (HAUTEUR_FENETRE - 20) / TAILLE_CELLULE;
    for ( i = 0; i < cell_hauteur; i++) {
        for ( j = 0; j < cell_largeur; j++) {
            if ((i + j) % 2 == 0) {
                ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
            } else {
                ChoisirCouleurDessin(CouleurParComposante(33, 33, 222));
            }
            RemplirRectangle(j * TAILLE_CELLULE + 20, i * TAILLE_CELLULE + 20, TAILLE_CELLULE, TAILLE_CELLULE);
        }
    }
}