#include "Variable.h"
#include "jeu.h"

int main(void) {
    // Initialisation d'Allegro
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());

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