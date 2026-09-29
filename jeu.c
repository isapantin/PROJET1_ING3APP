#include "jeu.h"
#include <assert.h>


void initialiserJeu(Jeu *jeu)
{
    // Initialisation d'Allegro
    assert(al_init());
    assert(al_install_keyboard());
    assert(al_init_image_addon());


    // Création de la fenêtre
    jeu->fenetre =
        al_create_display(LARGEUR_ECRAN, HAUTEUR_ECRAN);

    assert(jeu->fenetre);


    // Création de la file d'événements
    jeu->queue =
        al_create_event_queue();

    assert(jeu->queue);


    // Création du timer
    jeu->timer =
        al_create_timer(1.0 / FPS);

    assert(jeu->timer);

    // AJOUT : au démarrage, on affiche l'accueil
    jeu->etat = ECRAN_ACCUEIL;


    // Enregistrer les événements
    al_register_event_source(
        jeu->queue,
        al_get_display_event_source(jeu->fenetre)
    );

    al_register_event_source(
        jeu->queue,
        al_get_keyboard_event_source()
    );

    // AJOUT : permet de récupérer les mouvements/clics de souris
    al_register_event_source(
        jeu->queue,
        al_get_mouse_event_source()
    );

    al_register_event_source(
        jeu->queue,
        al_get_timer_event_source(jeu->timer)
    );


    // Initialiser les touches
    jeu->haut = false;
    jeu->bas = false;
    jeu->gauche = false;
    jeu->droite = false;


    // Initialiser le joueur
    initialiserJoueur(&jeu->joueur);

    // Charger ses images
    chargerImagesJoueur(&jeu->joueur);


    // Démarrer le timer
    al_start_timer(jeu->timer);
}


void afficherJeu(Jeu *jeu)
{
    // Fond noir
    // AJOUT
    // Si nous sommes sur l'écran d'accueil,
    // on affiche le menu.
    if (jeu->etat == ECRAN_ACCUEIL)
    {
        afficherEcranAccueil(jeu);

        // On conserve ton al_flip_display()
        al_flip_display();

        return;
    }

    // TON CODE DE BASE CONSERVE
    al_clear_to_color(al_map_rgb(0, 0, 0));


    // Récupérer l'image actuelle du joueur
    ALLEGRO_BITMAP *image =
        getImageJoueur(&jeu->joueur);


    // Dessiner le joueur
    al_draw_scaled_bitmap(
        image,

        // Partie de l'image à prendre
        0,
        0,
        al_get_bitmap_width(image),
        al_get_bitmap_height(image),

        // Position à l'écran
        jeu->joueur.x,
        jeu->joueur.y,

        // Taille à l'écran
        50,
        50,

        0
    );


    // Afficher l'image
    al_flip_display();
}


void libererJeu(Jeu *jeu)
{
    // Libérer les images du joueur
    libererJoueur(&jeu->joueur);

    // Libérer Allegro
    al_destroy_timer(jeu->timer);
    al_destroy_event_queue(jeu->queue);
    al_destroy_display(jeu->fenetre);
}