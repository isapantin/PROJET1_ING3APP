#include "ecranReglage.h"
#include "variable.h"

void afficherEcranReglages(Jeu *jeu)
{
    ALLEGRO_FONT *font = al_create_builtin_font();

    ALLEGRO_MOUSE_STATE mouseState;

    al_get_mouse_state(&mouseState);

    int sourisX = mouseState.x;
    int sourisY = mouseState.y;

    // Fond
    al_clear_to_color(al_map_rgb(20, 25, 45));

    // Bandeau supérieur
    al_draw_filled_rectangle(
        0, 0,
        LARGEUR, 180,
        al_map_rgb(30, 36, 65)
    );

    // Titre
    al_draw_text(
        font,
        al_map_rgb(255, 255, 255),
        LARGEUR / 2,
        65,
        ALLEGRO_ALIGN_CENTER,
        "REGLAGES"
    );

    // Bouton RETOUR
    if (sourisX >= 500 && sourisX <= 900 &&
        sourisY >= 650 && sourisY <= 730)
    {
        al_draw_filled_rounded_rectangle(
            500, 650,
            900, 730,
            20, 20,
            al_map_rgb(80, 150, 255)
        );
    }
    else
    {
        al_draw_filled_rounded_rectangle(
            500, 650,
            900, 730,
            20, 20,
            al_map_rgb(55, 110, 210)
        );
    }

    al_draw_text(
        font,
        al_map_rgb(255, 255, 255),
        LARGEUR / 2,
        675,
        ALLEGRO_ALIGN_CENTER,
        "RETOUR"
    );

    al_destroy_font(font);
}


void gererEcranReglages(Jeu *jeu, ALLEGRO_EVENT *event)
{
    if (event->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        int x = event->mouse.x;
        int y = event->mouse.y;

        // Bouton RETOUR
        if (x >= 500 && x <= 900 &&
            y >= 650 && y <= 730)
        {
            jeu->etat = jeu->etatPrecedent;
        }
    }
}