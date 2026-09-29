#include "joueur.h"
#include <assert.h>


void initialiserJoueur(Joueur *joueur)
{
    joueur->x = 600;
    joueur->y = 400;
    joueur->vitesse = 5;


    joueur->direction = 0;


    joueur->frame_actuelle = 0;


    joueur->compteur_animation = 0;
}


void chargerImagesJoueur(Joueur *joueur)
{
    // Face
    joueur->face[0] = al_load_bitmap("../imageJeu/perso_face_1.png");
    joueur->face[1] = al_load_bitmap("../imageJeu/perso_face_2.png");
    joueur->face[2] = al_load_bitmap("../imageJeu/perso_face_3.png");
    joueur->face[3] = al_load_bitmap("../imageJeu/perso_face_4.png");

    // Droite
    joueur->droite[0] = al_load_bitmap("../imageJeu/perso_droite_1.png");
    joueur->droite[1] = al_load_bitmap("../imageJeu/perso_droite_2.png");
    joueur->droite[2] = al_load_bitmap("../imageJeu/perso_droite_3.png");
    joueur->droite[3] = al_load_bitmap("../imageJeu/perso_droite_4.png");

    // Gauche
    joueur->gauche[0] = al_load_bitmap("../imageJeu/perso_gauche_1.png");
    joueur->gauche[1] = al_load_bitmap("../imageJeu/perso_gauche_2.png");
    joueur->gauche[2] = al_load_bitmap("../imageJeu/perso_gauche_3.png");
    joueur->gauche[3] = al_load_bitmap("../imageJeu/perso_gauche_4.png");

    // Derrière
    joueur->derriere[0] = al_load_bitmap("../imageJeu/perso_derriere_1.png");
    joueur->derriere[1] = al_load_bitmap("../imageJeu/perso_derriere_2.png");
    joueur->derriere[2] = al_load_bitmap("../imageJeu/perso_derriere_3.png");
    joueur->derriere[3] = al_load_bitmap("../imageJeu/perso_derriere_4.png");


    // Vérifier que toutes les images ont bien été chargées
    for (int i = 0; i < 4; i++)
    {
        assert(joueur->face[i]);
        assert(joueur->droite[i]);
        assert(joueur->gauche[i]);
        assert(joueur->derriere[i]);
    }
}


void deplacerJoueur(
    Joueur *joueur,
    bool haut,
    bool bas,
    bool gauche,
    bool droite
)
{
    if (haut)
        joueur->y -= joueur->vitesse;

    if (bas)
        joueur->y += joueur->vitesse;

    if (gauche)
        joueur->x -= joueur->vitesse;

    if (droite)
        joueur->x += joueur->vitesse;
}


void mettreAJourAnimation(
    Joueur *joueur,
    bool haut,
    bool bas,
    bool gauche,
    bool droite
)
{
    // Même logique que dans ton ancien projet

    if (haut)
        joueur->direction = 3;

    else if (bas)
        joueur->direction = 0;

    else if (gauche)
        joueur->direction = 2;

    else if (droite)
        joueur->direction = 1;


    // On avance le compteur d'animation
    joueur->compteur_animation++;


    // Toutes les 10 frames, on change d'image
    if (joueur->compteur_animation >= 10)
    {
        joueur->compteur_animation = 0;

        joueur->frame_actuelle =
            (joueur->frame_actuelle + 1) % 4;
    }


    // Si le joueur ne bouge pas,
    // on revient à la première image
    if (!haut && !bas && !gauche && !droite)
    {
        joueur->frame_actuelle = 0;
        joueur->compteur_animation = 0;
    }
}


ALLEGRO_BITMAP *getImageJoueur(Joueur *joueur)
{
    if (joueur->direction == 0)
        return joueur->face[joueur->frame_actuelle];

    if (joueur->direction == 1)
        return joueur->droite[joueur->frame_actuelle];

    if (joueur->direction == 2)
        return joueur->gauche[joueur->frame_actuelle];

    // direction == 3
    return joueur->derriere[joueur->frame_actuelle];
}


void libererJoueur(Joueur *joueur)
{
    for (int i = 0; i < 4; i++)
    {
        al_destroy_bitmap(joueur->face[i]);
        al_destroy_bitmap(joueur->droite[i]);
        al_destroy_bitmap(joueur->gauche[i]);
        al_destroy_bitmap(joueur->derriere[i]);
    }
}