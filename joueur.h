#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct {
    float x;
    float y;
    float vitesse;
} Joueur;

void initialiserJoueur(Joueur *joueur);
void deplacerJoueur(Joueur *joueur);



#endif //JOUEUR_H
