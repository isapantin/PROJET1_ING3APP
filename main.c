#include "jeu.h"


int main()
{
    Jeu jeu;

    initialiserJeu(&jeu);


    bool fini = false;

    ALLEGRO_EVENT event;


    while (!fini)
    {
        al_wait_for_event(jeu.queue, &event);


        // Fermer la fenêtre
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            fini = true;
        }


        // Touche enfoncée
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (event.keyboard.keycode)
            {
                case ALLEGRO_KEY_Z:
                    jeu.haut = true;
                    break;

                case ALLEGRO_KEY_S:
                    jeu.bas = true;
                    break;

                case ALLEGRO_KEY_Q:
                    jeu.gauche = true;
                    break;

                case ALLEGRO_KEY_D:
                    jeu.droite = true;
                    break;
            }
        }


        // Touche relâchée
        if (event.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch (event.keyboard.keycode)
            {
                case ALLEGRO_KEY_Z:
                    jeu.haut = false;
                    break;

                case ALLEGRO_KEY_S:
                    jeu.bas = false;
                    break;

                case ALLEGRO_KEY_Q:
                    jeu.gauche = false;
                    break;

                case ALLEGRO_KEY_D:
                    jeu.droite = false;
                    break;
            }
        }


        // Toutes les 1/60 secondes
        if (event.type == ALLEGRO_EVENT_TIMER)
        {
            // Déplacer le joueur
            deplacerJoueur(
                &jeu.joueur,
                jeu.haut,
                jeu.bas,
                jeu.gauche,
                jeu.droite
            );


            // Mettre à jour l'animation
            mettreAJourAnimation(
                &jeu.joueur,
                jeu.haut,
                jeu.bas,
                jeu.gauche,
                jeu.droite
            );


            // Afficher
            afficherJeu(&jeu);
        }
    }


    libererJeu(&jeu);

    return 0;
}