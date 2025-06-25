#include <SDL3/SDL.h>
#include <iostream>

using namespace std;


//------------------------------Déclaration de constantes décrviant les dimensions et la position de la première fenêtre SDL---------------------------------------

#define LARGEUR_PREMIERE_FENETRE 1500
#define HAUTEUR_PREMIERE_FENETRE 800
#define ORIGINE_POS_X_PREMIERE_FENETRE 200
#define ORIGINE_POS_Y_PREMIERE_FENETRE 50

//------------------------------Déclaration de constantes décrviant les dimensions et la position de la première fenêtre SDL---------------------------------------



//On déclare la fenêtre principale

SDL_Window *fenetre_principale;

//On déclare le rendu qui va permettre de dessiner dans la fenêtre principale

SDL_Renderer *rendu_fenetre_principale;



//texture pour dessiner dans la fenêtre
static SDL_Texture *texture = NULL;

static int texture_largeur = 0;

static int texture_hauteur = 0;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{

}



int main(int argc, char *argv[])
{



    //On déclare un evenement que l'on va receptionner pour pouvoir fermer la fenêtre
    SDL_Event event;

    //On déclare un tableau de caractères qui représente le chemin du fichier bmp que l'on va charger
    char * chemin_fichier_bmp = NULL;

    //On alloue une surface
    SDL_Surface * surface_fichier_bmp_gaulois = NULL;



    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }



    if (!SDL_CreateWindowAndRenderer("Jeu de la vie", LARGEUR_PREMIERE_FENETRE, HAUTEUR_PREMIERE_FENETRE, SDL_WINDOW_RESIZABLE, &fenetre_principale, &rendu_fenetre_principale)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

     if(!SDL_SetWindowPosition(fenetre_principale, ORIGINE_POS_X_PREMIERE_FENETRE, ORIGINE_POS_Y_PREMIERE_FENETRE))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Peut pas changer la position de la fenêtre %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    SDL_SetAppMetadata("Jeu de la vie", "1.0", "jeu_de_la_vie");

    SDL_asprintf(&chemin_fichier_bmp, "%simages\\gaulois.bmp", SDL_GetBasePath());

    surface_fichier_bmp_gaulois = SDL_LoadBMP(chemin_fichier_bmp);

    if (!surface_fichier_bmp_gaulois) {
        SDL_Log("N'a pas pu charger le fichier bmp gaulois: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_free(chemin_fichier_bmp);

    texture_largeur = surface_fichier_bmp_gaulois->w;
    texture_hauteur = surface_fichier_bmp_gaulois->h;

    texture = SDL_CreateTextureFromSurface(rendu_fenetre_principale, surface_fichier_bmp_gaulois);

    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 0, SDL_ALPHA_OPAQUE);  /* black, full alpha */


    if (!texture) {
        SDL_Log("Peut pas utiliser texture: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    SDL_DestroySurface(surface_fichier_bmp_gaulois);

    SDL_FRect dst_rect;

    /* center this one. */
    dst_rect.x = 0;
    dst_rect.y = 0;
    dst_rect.w = texture_largeur;
    dst_rect.h = texture_hauteur;
    SDL_RenderTexture(rendu_fenetre_principale, texture, NULL, &dst_rect);

    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderPresent(rendu_fenetre_principale);

    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            break;
        }

    }

    SDL_DestroyRenderer(rendu_fenetre_principale);
    SDL_DestroyWindow(fenetre_principale);

    SDL_Quit();

    return 0;
}
