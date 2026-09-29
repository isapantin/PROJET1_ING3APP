#ifndef ECRANACCEUIL_H
#define ECRANACCEUIL_H

#include <allegro5/allegro.h>

// On indique simplement que Jeu existe
typedef struct Jeu Jeu;


void afficherEcranAccueil(Jeu *jeu);

void gererEcranAccueil(Jeu *jeu, ALLEGRO_EVENT *event);


#endif