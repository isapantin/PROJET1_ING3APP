#include "Variable.h"
#include "jeu.h"

// AJOUT
#include "ecranAcceuil.h"

int main(void) {
    // Initialisation d'Allegro
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());

    // AJOUT : initialisation de la souris
    assert(al_install_mouse());

    // AJOUT : initialisation des polices
    al_init_font_addon();

    // Création du jeu
    Jeu jeu = {0};
    ALLEGRO_EVENT event;

    initialiserJeu(&jeu);

    bool fini = false;

    while (!fini) {
        al_wait_for_event(jeu.queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            fini = true;
        }

        // AJOUT
        // Gestion des clics sur l'écran d'accueil
        if (jeu.etat == ECRAN_ACCUEIL)
        {
            gererEcranAccueil(&jeu, &event);
        }

        // AJOUT
        // Si le bouton QUITTER a été utilisé
        if (jeu.etat == -1)
        {
            fini = true;
        }

        if (event.type == ALLEGRO_EVENT_TIMER)
        {
            afficherJeu(&jeu);
            al_flip_display();
        }
    }

    // Libération
    libererJeu(&jeu);

    return 0;
}