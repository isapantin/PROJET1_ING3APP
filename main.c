#include "Variable.h"
#include "jeu.h"
#include "ecranAcceuil.h"

int main(void) {

    // Initialisation d'Allegro
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());

    // Initialisation de la souris
    assert(al_install_mouse());

    // Initialisation des polices
    al_init_font_addon();
    al_init_ttf_addon();

    // Création du jeu
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

        // Gestion des clics sur l'écran d'accueil
        if (jeu.etat == ECRAN_ACCUEIL)
        {
            gererEcranAccueil(&jeu, &event);
        }

        // Si le bouton QUITTER a été utilisé
        if (jeu.etat == -1)
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

            al_flip_display();
        }
    }

    // Libération
    libererJeu(&jeu);

    return 0;
}