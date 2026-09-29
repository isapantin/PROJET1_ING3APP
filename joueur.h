#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdbool.h>
#include <allegro5/allegro.h>

typedef struct
{
    float x;
    float y;
    float vitesse;

    ALLEGRO_BITMAP *face[4];
    ALLEGRO_BITMAP *droite[4];
    ALLEGRO_BITMAP *gauche[4];
    ALLEGRO_BITMAP *derriere[4];

    int direction;
    int frame_actuelle;
    int compteur_animation;

} Joueur;


void initialiserJoueur(Joueur *joueur);


void chargerImagesJoueur(Joueur *joueur);


void deplacerJoueur(
    Joueur *joueur,
    bool haut,
    bool bas,
    bool gauche,
    bool droite
);


void mettreAJourAnimation(
    Joueur *joueur,
    bool haut,
    bool bas,
    bool gauche,
    bool droite
);


ALLEGRO_BITMAP *getImageJoueur(Joueur *joueur);


void libererJoueur(Joueur *joueur);

#endif