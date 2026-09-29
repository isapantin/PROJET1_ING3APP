#ifndef JEU_H
#define JEU_H

#include "Variable.h"

// permet de savoir sur quel écran on se trouve
typedef enum {
    ECRAN_ACCUEIL,
    ECRAN_JEU
} EtatJeu;

typedef struct {
    ALLEGRO_DISPLAY *fenetre;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;

    //  écran actuellement affiché
    EtatJeu etat;

} Jeu;

void initialiserJeu(Jeu *jeu);
void libererJeu(Jeu *jeu);

void afficherJeu(Jeu *jeu);

#endif