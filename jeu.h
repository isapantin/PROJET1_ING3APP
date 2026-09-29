#ifndef JEU_H
#define JEU_H

#include <stdbool.h>
#include <allegro5/allegro.h>
#include "variable.h"
#include "joueur.h"


// permet de savoir sur quel écran on se trouve
typedef enum {
    ECRAN_ACCUEIL,
    ECRAN_JEU
} EtatJeu;

typedef struct {
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


    //  écran actuellement affiché
    EtatJeu etat;

} Jeu;


void initialiserJeu(Jeu *jeu);
void libererJeu(Jeu *jeu);

void afficherJeu(Jeu *jeu);

void libererJeu(Jeu *jeu);


#endif