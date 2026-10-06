

#include "ecranAcceuil.h"
#include "jeu.h"
#include "Variable.h"
// AJOUT
void afficherEcranAccueil(Jeu *jeu)
{
    ALLEGRO_FONT *font = al_create_builtin_font();


    // AJOUT
    int sourisX = 0;
    int sourisY = 0;

    // AJOUT
    ALLEGRO_MOUSE_STATE mouseState;

    // AJOUT
    al_get_mouse_state(&mouseState);

    // AJOUT
    sourisX = mouseState.x;
    sourisY = mouseState.y;

    // AJOUT
    // Fond
    al_clear_to_color(al_map_rgb(18, 79, 105));

    // AJOUT
    // Grand bandeau supérieur
    al_draw_filled_rectangle(
        0,
        0,
        LARGEUR,
        180,
        al_map_rgb(30, 36, 65)
    );

    // AJOUT
    // Titre
    al_draw_text(
        font,
        al_map_rgb(255, 255, 255),
        LARGEUR / 2,
        65,
        ALLEGRO_ALIGN_CENTER,
        "ING1 SURVIVOR"
    );

    // AJOUT
    // Sous-titre
    al_draw_text(
        font,
        al_map_rgb(89, 135, 156),
        LARGEUR / 2,
        105,
        ALLEGRO_ALIGN_CENTER,
        "Vas-tu survivre à ta première année ?"
    );

    /*
     * ============================================================
     * BOUTON JOUER
     * ============================================================
     */

    // AJOUT
    bool sourisSurJouer =
        sourisX >= 500 &&
        sourisX <= 900 &&
        sourisY >= 350 &&
        sourisY <= 450;

    // AJOUT
    if (sourisSurJouer)
    {
        // Bouton plus clair lorsque la souris passe dessus
        al_draw_filled_rounded_rectangle(
            500,
            350,
            900,
            450,
            20,
            20,
            al_map_rgb(80, 150, 255)
        );
    }
    else
    {
        // Bouton normal
        al_draw_filled_rounded_rectangle(
            500,
            350,
            900,
            450,
            20,
            20,
            al_map_rgb(55, 110, 210)
        );
    }

    // AJOUT
    al_draw_text(
        font,
        al_map_rgb(255, 255, 255),
        LARGEUR / 2,
        390,
        ALLEGRO_ALIGN_CENTER,
        "JOUER"
    );

    /*
     * ============================================================
     * BOUTON QUITTER
     * ============================================================
     */

    // AJOUT
    bool sourisSurQuitter =
        sourisX >= 500 &&
        sourisX <= 900 &&
        sourisY >= 500 &&
        sourisY <= 600;

    // AJOUT
    if (sourisSurQuitter)
    {
        al_draw_filled_rounded_rectangle(
            500,
            500,
            900,
            600,
            20,
            20,
            al_map_rgb(120, 70, 75)
        );
    }
    else
    {
        al_draw_filled_rounded_rectangle(
            500,
            500,
            900,
            600,
            20,
            20,
            al_map_rgb(70, 70, 85)
        );
    }

    // AJOUT
    al_draw_text(
        font,
        al_map_rgb(255, 255, 255),
        LARGEUR / 2,
        540,
        ALLEGRO_ALIGN_CENTER,
        "QUITTER"
    );

    // AJOUT
    // Petite indication en bas
    al_draw_text(
        font,
        al_map_rgb(110, 120, 145),
        LARGEUR / 2,
        HAUTEUR - 60,
        ALLEGRO_ALIGN_CENTER,
        "Cliquez sur JOUER pour commencer"
    );

    // AJOUT
    al_destroy_font(font);
}


// AJOUT
void gererEcranAccueil(Jeu *jeu, ALLEGRO_EVENT *event)
{
    // AJOUT
    if (event->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        // AJOUT
        int x = event->mouse.x;
        int y = event->mouse.y;

        /*
         * Bouton JOUER
         */
        // AJOUT
        if (x >= 500 &&
            x <= 900 &&
            y >= 350 &&
            y <= 450)
        {
            // AJOUT
            jeu->etat = ECRAN_JEU;
        }

        /*
         * Bouton QUITTER
         */
        // AJOUT
        if (x >= 500 &&
            x <= 900 &&
            y >= 500 &&
            y <= 600)
        {
            // AJOUT
            jeu->etat = ECRAN_QUITTER;;
        }
    }
}