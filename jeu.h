#ifndef JEU_H
#define JEU_H

#include "Variable.h"

typedef struct {
    ALLEGRO_DISPLAY *fenetre;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
} Jeu;

void initialiserJeu(Jeu *jeu);
void libererJeu(Jeu *jeu);

#endif