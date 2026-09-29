#include "jeu.h"
#include "ecranAcceuil.h"
#include "variable.h"
#include <stdbool.h>

int main(void)
{
    Jeu jeu = {0};
    ALLEGRO_EVENT event;

    initialiserJeu(&jeu);

    bool fini = false;

    while (!fini)
    {
        al_wait_for_event(jeu.queue, &event);

        // Fermer la fenêtre
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            fini = true;
        }

        // Gestion de l'écran d'accueil
        if (jeu.etat == ECRAN_ACCUEIL)
        {
            gererEcranAccueil(&jeu, &event);
        }

        // Quitter
        if (jeu.etat == ECRAN_QUITTER)
        {
            fini = true;
        }

        // Gestion du clavier uniquement pendant le jeu
        if (jeu.etat == ECRAN_JEU)
        {
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
        }

        // Mise à jour à chaque tick du timer
        if (event.type == ALLEGRO_EVENT_TIMER)
        {
            if (jeu.etat == ECRAN_JEU)
            {
                deplacerJoueur(
                    &jeu.joueur,
                    jeu.haut,
                    jeu.bas,
                    jeu.gauche,
                    jeu.droite
                );

                mettreAJourAnimation(
                    &jeu.joueur,
                    jeu.haut,
                    jeu.bas,
                    jeu.gauche,
                    jeu.droite
                );
            }

            afficherJeu(&jeu);
        }
    }

    libererJeu(&jeu);

    return 0;
}

