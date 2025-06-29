#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "src/Jeu_v2.h"
#include "src/Gaulois.h"

#include <iostream>

using namespace std;


//------------------------------Déclaration de constantes décrviant les dimensions et la position de la première fenêtre SDL---------------------------------------

#define LARGEUR_PREMIERE_FENETRE 1700
#define HAUTEUR_PREMIERE_FENETRE 950
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

//------------------------------Déclaration de variables contenant les images utilisées------------------------------------------------------------------------------------------------------------



SDL_Surface * image_vide = NULL;
SDL_Surface * image_arbre = NULL;
SDL_Surface * image_gaulois = NULL;
SDL_Surface * image_gauloise = NULL;
SDL_Surface * image_gaulois_enfant_garcon = NULL;
SDL_Surface * image_gaulois_enfant_fille = NULL;
SDL_Surface * image_animal = NULL;


//------------------------------Déclaration de variables contenant les images utilisées------------------------------------------------------------------------------------------------------------

SDL_Texture * texture_vide = NULL;

SDL_Texture * texture_arbre = NULL;

SDL_Texture * texture_gaulois = NULL;

SDL_Texture * texture_gauloise = NULL;

SDL_Texture * texture_animal = NULL;

SDL_Texture * texture_gaulois_enfant_garcon = NULL;

SDL_Texture * texture_gaulois_fille = NULL;

//ecrire du texte dans sdl


//-------------------------------------------------------------Déclaration des variables contenant les polices d'ecriture du texte à l'écran-----------------------------------------------------------
TTF_Font * font_coordonnees = NULL;

TTF_Font * font_titre_legende = NULL;

TTF_Font * font_titre_gauloise = NULL;


//-------------------------------------------------------------Déclaration des variables contenant les polices d'ecriture du texte à l'écran-----------------------------------------------------------

//-------------------------------------------------------------Déclaration des variables contenant les polices d'ecriture du texte à l'écran-----------------------------------------------------------

SDL_Surface * text = NULL;

SDL_Texture * text_texture = NULL ;

//---------------------------

Jeu_v2 jeu;


void charger_images()
{
    char * chemin_fichier_image_bmp = NULL;


    SDL_asprintf(&chemin_fichier_image_bmp, "%simages\\vide.bmp", SDL_GetBasePath());

    image_vide = SDL_LoadBMP(chemin_fichier_image_bmp);



    SDL_asprintf(&chemin_fichier_image_bmp, "%simages\\arbre.bmp", SDL_GetBasePath());

    image_arbre = SDL_LoadBMP(chemin_fichier_image_bmp);


    SDL_asprintf(&chemin_fichier_image_bmp, "%simages\\gaulois.bmp", SDL_GetBasePath());

    image_gaulois = SDL_LoadBMP(chemin_fichier_image_bmp);



    SDL_asprintf(&chemin_fichier_image_bmp, "%simages\\gauloise.bmp", SDL_GetBasePath());

    image_gauloise = SDL_LoadBMP(chemin_fichier_image_bmp);


    SDL_asprintf(&chemin_fichier_image_bmp, "%simages\\animal.bmp", SDL_GetBasePath());
    image_animal = SDL_LoadBMP(chemin_fichier_image_bmp);


    SDL_asprintf(&chemin_fichier_image_bmp, "%simages\\gaulois_enfant_garcon.bmp", SDL_GetBasePath());

    image_gaulois_enfant_garcon = SDL_LoadBMP(chemin_fichier_image_bmp);


    SDL_asprintf(&chemin_fichier_image_bmp, "%simages\\gaulois_enfant_fille.bmp", SDL_GetBasePath());

    image_gaulois_enfant_fille = SDL_LoadBMP(chemin_fichier_image_bmp);

}

void afficher_grille_SDL()
{
	shared_ptr<Gaulois> gaulois;
	Position position ;


    SDL_FRect  single_rect;

	/*int nb_lignes = 14 ;
	int nb_cases_par_ligne = 18;*/

	single_rect.w = 50;
	single_rect.h = 50;



	//169*221

	//Textures
	texture_vide = SDL_CreateTextureFromSurface(rendu_fenetre_principale, image_vide);

	texture_arbre = SDL_CreateTextureFromSurface(rendu_fenetre_principale, image_arbre);

	texture_gaulois = SDL_CreateTextureFromSurface(rendu_fenetre_principale, image_gaulois);

	texture_gauloise = SDL_CreateTextureFromSurface(rendu_fenetre_principale, image_gauloise);

	texture_animal = SDL_CreateTextureFromSurface(rendu_fenetre_principale, image_animal);

	texture_gaulois_enfant_garcon = SDL_CreateTextureFromSurface(rendu_fenetre_principale, image_gaulois_enfant_garcon);

	texture_gaulois_fille = SDL_CreateTextureFromSurface(rendu_fenetre_principale, image_gaulois_enfant_fille);

	int pos_x = 50;
	int pos_y = 50;
	int espace = 20 ;


    int debut_x = 30;
    int debut_y = 0;





	 for( set < shared_ptr<Objet> > ::iterator it = jeu.getGrille()->begin(); it !=jeu.getGrille()->end() ; it++ )
	 {



		single_rect.x =  (pos_x + espace) * (*it)->getPosition().getAbscisse() + debut_x ;
		single_rect.y = (pos_y + espace) * (*it)->getPosition().getOrdonnee() + debut_y;

        cout << (*it)->getPosition().getAbscisse() << endl;
        cout << (*it)->getPosition().getOrdonnee() << endl;

		if((*it)->getType()=="Arbre")
		{
					SDL_RenderTexture(rendu_fenetre_principale, texture_arbre, NULL, &single_rect);

		}
		else if((*it)->getType()=="Gaulois")
			{


				gaulois = dynamic_pointer_cast<Gaulois> (*it);




				if(gaulois->getSexe()=='M')
				{

				  if ( gaulois->getAge() > 10 )
				    {
				      cout << " Gaulois adulte homme " << gaulois->getPosition().toString() << endl;
				      SDL_RenderTexture(rendu_fenetre_principale, texture_gaulois, NULL, &single_rect);
				    }else
				    {
				      cout << " Gaulois garcon " << gaulois->getPosition().toString() << endl;
				      SDL_RenderTexture(rendu_fenetre_principale, texture_gaulois_enfant_garcon, NULL, &single_rect);
				    }

				}
				else
				{
				  if( gaulois->getAge() > 10 )
				    {
				      cout << " Gauloise adulte femme " << gaulois->getPosition().toString() << endl;
					SDL_RenderTexture(rendu_fenetre_principale, texture_gauloise, NULL, &single_rect);
				    }else
				    {
				      cout << " Gauloise fille " << gaulois->getPosition().toString() << endl;
				      SDL_RenderTexture(rendu_fenetre_principale, texture_gaulois_fille, NULL, &single_rect);
				    }
				}

		}else if((*it)->getType()=="Animal")
		{
		  cout << "Animal " << (*it)->getPosition().toString() << endl;

			SDL_RenderTexture(rendu_fenetre_principale, texture_animal, NULL, &single_rect);

		}




	 }


	 if ( TTF_Init() < 0 )
	{
		cout << "Error initializing SDL_ttf: " << SDL_GetError() << endl;
		SDL_DestroyWindow(fenetre_principale);
        SDL_Quit();
        return;
	}


	char * chemin_fichier_police_bmp = NULL;


    SDL_asprintf(&chemin_fichier_police_bmp, "%spolice\\arial\\ARIAL.ttf", SDL_GetBasePath());


	font_coordonnees = TTF_OpenFont(chemin_fichier_police_bmp, 10);
	if ( !font_coordonnees ) {
		cout << "Failed to load font: " << SDL_GetError() << endl;

		SDL_DestroyWindow(fenetre_principale);
        SDL_Quit();
        return;
	}


	// On met rouge comme couleur
	SDL_Color color = { 255, 0, 0 };

	 stringstream ss;



	SDL_FRect  rectangle_ecriture_coordonnees;

	string chaine_coordonnees = "";
	const char* char_constant_coordonnees = NULL;


	 for(int i=1; i <= jeu.get_nb_lignes() ; i++)
	 {
		 for(int j = 1 ; j <= jeu.get_nb_colonnes() ; j++ )
		 {
			 ss.str("");
			 char_constant_coordonnees = NULL;


			 ss << i ;
			 ss << "," ;
			 ss << j ;


			 single_rect.x =  (pos_x + espace) * i + debut_x;
			 single_rect.y = (pos_y + espace) * j + debut_y;


			 chaine_coordonnees = ss.str();
			 char_constant_coordonnees = chaine_coordonnees.c_str();




			 int taille_texte = ss.str().size();

			 text = TTF_RenderText_Solid( font_coordonnees, char_constant_coordonnees,taille_texte, color );
			 text_texture = SDL_CreateTextureFromSurface( rendu_fenetre_principale, text );

			 if ( !text ) {
				cout << "Failed to render text: " << SDL_GetError() << endl;
			}

			 rectangle_ecriture_coordonnees.x = single_rect.x + 0;
			rectangle_ecriture_coordonnees.y = single_rect.y + 0;

			rectangle_ecriture_coordonnees.w = text->w;
			rectangle_ecriture_coordonnees.h = text->h;

			SDL_RenderTexture( rendu_fenetre_principale, text_texture, NULL, &rectangle_ecriture_coordonnees );
		 }
	 }



    TTF_CloseFont(font_coordonnees);




}




void afficher_legende()
{
	//Afficher légende


	 //------------------------------------- image gauloise ------------------------------------------------

	 SDL_FRect * rectangle_image_gauloise = NULL;

	 rectangle_image_gauloise->x = 1000;
	 rectangle_image_gauloise->y = 200;


	 rectangle_image_gauloise->w = 50;
	 rectangle_image_gauloise->h = 50;


	  SDL_RenderTexture(rendu_fenetre_principale, texture_gauloise, NULL, rectangle_image_gauloise);
	 //------------------------------------- image gauloise ------------------------------------------------


	 //------------------------------------- titre legende ------------------------------------------------

	 if ( TTF_Init() < 0 )
	{
		cout << "Error initializing SDL_ttf: " << SDL_GetError() << endl;
		SDL_DestroyWindow(fenetre_principale);
        SDL_Quit();
        return;
	}


	font_titre_legende = TTF_OpenFont("../../police/arial/ARIAL.ttf", 20);
	if ( !font_titre_legende ) {
		cout << "Failed to load font: " << SDL_GetError() << endl;
		SDL_DestroyWindow(fenetre_principale);
        SDL_Quit();
        return;
	}


	 SDL_Color color_titre_legende = { 255, 0, 0 };

	 SDL_FRect * rectangle_titre_legende = NULL;

	 rectangle_titre_legende->x = 1100;
	 rectangle_titre_legende->y = 150;

	 SDL_Surface * text_titre_legende = NULL;

	 SDL_Texture * text_texture_titre_legende = NULL ;


	 int taille_texte = 7;

	 text_titre_legende = TTF_RenderText_Solid( font_titre_legende, "Legende",taille_texte, color_titre_legende );
	 text_texture_titre_legende = SDL_CreateTextureFromSurface( rendu_fenetre_principale, text_titre_legende );

	 rectangle_titre_legende->w = text_titre_legende->w;
	 rectangle_titre_legende->h = text_titre_legende->h;



	 SDL_RenderTexture( rendu_fenetre_principale, text_texture_titre_legende, NULL, rectangle_titre_legende );

	 //------------------------------------- titre legende ------------------------------------------------

	 //------------------------------------- titre gauloise ------------------------------------------------




	 font_titre_gauloise = TTF_OpenFont("../../police/arial/ARIAL.ttf", 17);
	 if ( !font_titre_gauloise ) {
		cout << "Failed to load font: " << SDL_GetError() << endl;
		SDL_DestroyWindow(fenetre_principale);
        SDL_Quit();
        return;
	 }

	 SDL_Color color_titre_gauloise = { 255, 150, 0 };

	 SDL_FRect * rectangle_titre_gauloise = NULL;

	 rectangle_titre_gauloise->x = 990;
	 rectangle_titre_gauloise->y = 255;

	 SDL_Surface * text_titre_gauloise = NULL;

	 SDL_Texture * text_texture_titre_gauloise = NULL ;

	 taille_texte = 8;

	 text_titre_gauloise = TTF_RenderText_Solid( font_titre_gauloise, "Gauloise",taille_texte, color_titre_gauloise );
	 text_texture_titre_gauloise = SDL_CreateTextureFromSurface( rendu_fenetre_principale, text_titre_gauloise );

	 rectangle_titre_gauloise->w = text_titre_gauloise->w;
	 rectangle_titre_gauloise->h = text_titre_gauloise->h;

	 SDL_RenderTexture( rendu_fenetre_principale, text_texture_titre_gauloise, NULL, rectangle_titre_gauloise );

	 //------------------------------------- titre gauloise ------------------------------------------------


	 //------------------------------------- image gaulois ------------------------------------------------
	 SDL_FRect * rectangle_image_gaulois;

	 rectangle_image_gaulois->x = 1100;
	 rectangle_image_gaulois->y = 200;


	 rectangle_image_gaulois->w = 50;
	 rectangle_image_gaulois->h = 50;


	  SDL_RenderTexture(rendu_fenetre_principale, texture_gaulois, NULL, rectangle_image_gaulois);



	 //------------------------------------- image gaulois ------------------------------------------------


	 //------------------------------------- titre gaulois ------------------------------------------------

	 TTF_Font * font_titre_gaulois;

	 font_titre_gaulois = TTF_OpenFont("../../police/arial/ARIAL.ttf", 17);
	 if ( !font_titre_gauloise ) {
		cout << "Failed to load font: " << SDL_GetError() << endl;
		SDL_DestroyWindow(fenetre_principale);
        SDL_Quit();
        return;
	 }

	 SDL_Color color_titre_gaulois = { 255, 170, 0 };

	 SDL_FRect * rectangle_titre_gaulois = NULL;

	 rectangle_titre_gaulois->x = 1100;
	 rectangle_titre_gaulois->y = 255;

	 SDL_Surface * text_titre_gaulois = NULL;

	 SDL_Texture * text_texture_titre_gaulois = NULL ;

	 taille_texte = 7;

	 text_titre_gaulois = TTF_RenderText_Solid( font_titre_gaulois, "Gaulois", taille_texte,color_titre_gaulois );
	 text_texture_titre_gaulois = SDL_CreateTextureFromSurface( rendu_fenetre_principale, text_titre_gaulois );

	 rectangle_titre_gaulois->w = text_titre_gaulois->w;
	 rectangle_titre_gaulois->h = text_titre_gaulois->h;

	 SDL_RenderTexture( rendu_fenetre_principale, text_texture_titre_gaulois, NULL, rectangle_titre_gaulois );

    SDL_DestroyTexture(text_texture_titre_gaulois);


	 //------------------------------------- titre gaulois ------------------------------------------------


	 //------------------------------------- image gaulois enfant garcon ------------------------------------------------

	 SDL_FRect * rectangle_image_gaulois_enfant_garcon = NULL;

	 rectangle_image_gaulois_enfant_garcon->x = 1200;
	 rectangle_image_gaulois_enfant_garcon->y = 200;


	 rectangle_image_gaulois_enfant_garcon->w = 50;
	 rectangle_image_gaulois_enfant_garcon->h = 50;


	  SDL_RenderTexture(rendu_fenetre_principale, texture_gaulois_enfant_garcon, NULL, rectangle_image_gaulois_enfant_garcon);


	 //------------------------------------- image gaulois enfant garcon ------------------------------------------------

	 //------------------------------------- titre gaulois enfant garcon ------------------------------------------------

	  TTF_Font * font_titre_gaulois_enfant_garcon;

	 font_titre_gaulois_enfant_garcon = TTF_OpenFont("../../police/arial/ARIAL.ttf", 17);
	 if ( !font_titre_gaulois_enfant_garcon ) {
		cout << "Failed to load font: " << SDL_GetError() << endl;
		SDL_DestroyWindow(fenetre_principale);
        SDL_Quit();
        return;
	 }

	 SDL_Color color_titre_gaulois_enfant_garcon = { 255, 190, 0 };

	 SDL_FRect * rectangle_titre_gaulois_enfant_garcon = NULL;

	 rectangle_titre_gaulois_enfant_garcon->x = 1190;
	 rectangle_titre_gaulois_enfant_garcon->y = 255;

	 SDL_Surface * text_titre_gaulois_enfant_garcon = NULL;

	 SDL_Texture * text_texture_titre_gaulois_enfant_garcon = NULL ;

	 taille_texte = 20;

	 text_titre_gaulois_enfant_garcon = TTF_RenderText_Solid( font_titre_gaulois_enfant_garcon, "Gaulois enfant garcon",taille_texte, color_titre_gaulois_enfant_garcon );
	 text_texture_titre_gaulois_enfant_garcon = SDL_CreateTextureFromSurface( rendu_fenetre_principale, text_titre_gaulois_enfant_garcon );

	 rectangle_titre_gaulois_enfant_garcon->w = text_titre_gaulois_enfant_garcon->w;
	 rectangle_titre_gaulois_enfant_garcon->h = text_titre_gaulois_enfant_garcon->h;

	 SDL_RenderTexture( rendu_fenetre_principale, text_texture_titre_gaulois_enfant_garcon, NULL, rectangle_titre_gaulois );


	 //------------------------------------- titre gaulois enfant garcon ------------------------------------------------


}




SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    //On déclare un tableau de caractères qui représente le chemin du fichier bmp que l'on va charger
    char * chemin_carte_bmp = NULL;

    //On alloue une surface
    SDL_Surface * surface_fichier_bmp_carte = NULL;



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

    SDL_asprintf(&chemin_carte_bmp, "%simages\\carte.bmp", SDL_GetBasePath());

    surface_fichier_bmp_carte = SDL_LoadBMP(chemin_carte_bmp);

    if (!surface_fichier_bmp_carte) {
        SDL_Log("N'a pas pu charger le fichier bmp carte.bmp: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_free(chemin_carte_bmp);

    texture_largeur = surface_fichier_bmp_carte->w;
    texture_hauteur = surface_fichier_bmp_carte->h;


    texture = SDL_CreateTextureFromSurface(rendu_fenetre_principale, surface_fichier_bmp_carte);

    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 0, SDL_ALPHA_OPAQUE);  /* black, full alpha */


    if (!texture) {
        SDL_Log("Peut pas utiliser texture: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    SDL_DestroySurface(surface_fichier_bmp_carte);

    jeu.initialiser_grille();

    charger_images();






     return SDL_APP_CONTINUE;
}




void fermeture_SDL()
{

	//----------------On libere l'emplacement mémoire des textures des images de gaulois(gaulois adulter, gauloise, garçon enfant  et fille enfant) et sanglier-----------------------------------------
	SDL_DestroyTexture(texture_vide);

	SDL_DestroyTexture(texture_arbre);

	SDL_DestroyTexture(texture_gaulois);

	SDL_DestroyTexture(texture_gauloise);

	SDL_DestroyTexture(texture_animal);

	SDL_DestroyTexture(texture_gaulois_enfant_garcon);

	SDL_DestroyTexture(texture_gaulois_fille);

	SDL_DestroyTexture(text_texture);

	//----------------On libere l'emplacement mémoire des textures des images de gaulois(gaulois adulter, gauloise, garçon enfant  et fille enfant) et sanglier-----------------------------------------

	//----------------On libere l'emplacement mémoire des textures des titres de la légende -----------------------------------------

/*


	SDL_DestroyTexture(text_texture_titre_gaulois_enfant_garcon);

	SDL_DestroyTexture(text_texture_titre_gauloise);

	SDL_DestroyTexture(text_texture_titre_legende);*/

	//----------------On libere l'emplacement mémoire des textures des titres de la légende -----------------------------------------



	//------------------------------------On libère l'emplacement mémoire des images utilisés dans le jeu-----------------------------

	SDL_DestroySurface(image_vide);

	SDL_DestroySurface(image_arbre);

	SDL_DestroySurface(image_gaulois);

	SDL_DestroySurface(image_gauloise);

	SDL_DestroySurface(image_animal);

	SDL_DestroySurface(image_gaulois_enfant_garcon);

	SDL_DestroySurface(image_gaulois_enfant_fille);


	//------------------------------------On libère l'emplacement mémoire des images utilisés dans le jeu-----------------------------


	//------------------------------------On libère l'emplacement mémoire du texte utilisé pour écrire les coordonnées-----------------------------


	SDL_DestroySurface(text);


	//------------------------------------On libère l'emplacement mémoire du texte utilisé pour écrire les coordonnées-----------------------------

	//---------------------------On ferme les polices d'ecriture utilisées-------------------------------------------------------------------------
	/*


	TTF_CloseFont(font_titre_gaulois_enfant_garcon);
	TTF_CloseFont(font_titre_gaulois);
	TTF_CloseFont(font);
	TTF_CloseFont(font);
*/



	//---------------------------On ferme les polices d'ecriture utilisées-------------------------------------------------------------------------


	SDL_DestroyRenderer(rendu_fenetre_principale);
	SDL_DestroyWindow(fenetre_principale);
	SDL_Quit();
}



/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    fermeture_SDL();
}




/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_KEY_DOWN ||
        event->type == SDL_EVENT_QUIT) {
            fermeture_SDL();
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_FRect dst_rect;

    /* center this one. */
    dst_rect.x = 100;
    dst_rect.y = 100;
    dst_rect.w = texture_largeur;
    dst_rect.h = texture_hauteur;




    SDL_RenderTexture(rendu_fenetre_principale, texture, NULL, &dst_rect);

    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0x00, 0x00, 0x00, 0x00);

    afficher_grille_SDL();
    //afficher_legende();




    SDL_RenderPresent(rendu_fenetre_principale);

    return SDL_APP_CONTINUE;
}





