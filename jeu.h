#ifndef JEU_H
#define JEU_H

#include <stdbool.h>
#include <allegro5/allegro.h>

#include "joueur.h"


#define LARGEUR_ECRAN 1400
#define HAUTEUR_ECRAN 900
#define FPS 60


// Permet de savoir sur quel écran on se trouve
typedef enum
{
    ECRAN_ACCUEIL,
    ECRAN_JEU,
    ECRAN_QUITTER,
    ECRAN_REGLAGES
} EtatJeu;


typedef struct Jeu
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

    // Écran actuellement affiché
    EtatJeu etat;
    EtatJeu etatPrecedent;

} Jeu;


void initialiserJeu(Jeu *jeu);

void afficherJeu(Jeu *jeu);

void libererJeu(Jeu *jeu);


#endif