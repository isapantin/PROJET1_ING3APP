#include "jeu.h"

void initialiserJeu(Jeu *jeu) {

    jeu->fenetre = al_create_display(LARGEUR, HAUTEUR);
    assert(jeu->fenetre);
    al_set_window_position(jeu->fenetre,100,25);

    jeu->queue = al_create_event_queue();
    assert(jeu->queue);

    jeu->timer = al_create_timer(1.0 / FPS);
    assert(jeu->timer);

    al_register_event_source(
        jeu->queue,
        al_get_display_event_source(jeu->fenetre)
    );

    al_register_event_source(
        jeu->queue,
        al_get_keyboard_event_source()
    );

    al_register_event_source(
        jeu->queue,
        al_get_timer_event_source(jeu->timer)
    );

    al_start_timer(jeu->timer);
}

void libererJeu(Jeu *jeu) {

    al_destroy_timer(jeu->timer);
    al_destroy_event_queue(jeu->queue);
    al_destroy_display(jeu->fenetre);
}

void afficherJeu(Jeu *jeu)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_flip_display();
}