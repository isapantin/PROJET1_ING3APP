#ifndef JEU_H
#define JEU_H

#include <stdbool.h>
#include <allegro5/allegro.h>
#include "variable.h"
#include "joueur.h"


#define LARGEUR_ECRAN 1200
#define HAUTEUR_ECRAN 800
#define FPS 60


typedef struct
{
    // Allegro
    ALLEGRO_DISPLAY *fenetre;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;

    // Joueur
    Joueur joueur;

    // Touches
    bool haut;
    bool bas;
    bool gauche;
    bool droite;

} Jeu;


void initialiserJeu(Jeu *jeu);

void afficherJeu(Jeu *jeu);

void libererJeu(Jeu *jeu);


#endif