#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#include "Jeu_v2.h"

#include "main_sdl.h"

#include "Gaulois.h"

#include<chrono>
#include<thread>


//Images
		
SDL_Surface * image_vide = SDL_LoadBMP("../../images/vide.bmp");
	
SDL_Surface * image_arbre = SDL_LoadBMP("../../images/arbre.bmp");
	
SDL_Surface * image_gaulois = SDL_LoadBMP("../../images/gaulois.bmp");
	
SDL_Surface * image_gauloise = SDL_LoadBMP("../../images/gauloise.bmp");
	
SDL_Surface * image_animal = SDL_LoadBMP("../../images/animal.bmp");

SDL_Surface * image_gaulois_enfant_garcon =
	 SDL_LoadBMP("../../images/gaulois_enfant_garcon.bmp");

SDL_Surface * image_gaulois_enfant_fille =
	 SDL_LoadBMP("../../images/gaulois_enfant_fille.bmp");
	 
	 
	 
SDL_Texture * texture_vide = NULL;

SDL_Texture * texture_arbre = NULL;

SDL_Texture * texture_gaulois = NULL;

SDL_Texture * texture_gauloise = NULL;

SDL_Texture * texture_animal = NULL;

SDL_Texture * texture_gaulois_garcon = NULL;

SDL_Texture * texture_gaulois_fille = NULL;

//ecrire du texte dans sdl

TTF_Font * font = NULL;

SDL_Surface * text = NULL;

SDL_Texture * text_texture = NULL ;

SDL_Window *win = NULL;

SDL_Window *win_test_2 = NULL;


void main_sdl()
{
    
    SDL_Renderer *renderer = NULL,
	*renderer_win_test_2 = NULL;
	

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout <<  "SDL_Init Error: %s\n" <<  SDL_GetError() << endl;
        SDL_Quit();
        return;
    }

    win = SDL_CreateWindow("Jeu de la vie!", 200, 50, 1300, 800, SDL_WINDOW_SHOWN);
    if (win == NULL)
    {
       
		cout <<  "SDL_CreateWindow Error: %s\n" <<  SDL_GetError() << endl;
		SDL_DestroyWindow(win);
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
    if (renderer == NULL)
    {
		cout <<  "SDL_CreateRenderer Error: %s\n" <<  SDL_GetError() << endl;
		
        SDL_DestroyWindow(win);
        SDL_Quit();
        return;
    }
	
	win_test_2 = SDL_CreateWindow("test 2!", 1000, 200, 800, 300, SDL_WINDOW_SHOWN);
	 if (win_test_2 == NULL)
		{
		   
			cout <<  "SDL_CreateWindow Error: %s\n" <<  SDL_GetError() << endl;
			SDL_DestroyWindow(win_test_2);
			SDL_Quit();
			return;
		}
	
	renderer_win_test_2 = SDL_CreateRenderer(win_test_2, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer_win_test_2 == NULL)
    {
		cout <<  "SDL_CreateRenderer Error: %s\n" <<  SDL_GetError() << endl;
		
        SDL_DestroyWindow(win_test_2);
        SDL_Quit();
        return;
    }
	
	
	
	
	Jeu_v2 jeu;
	
	jeu.initialiser_grille();
	
	SDL_Event ev;
	
	bool isRunning = true;
	
	int tour = 0;
	
	while(isRunning)
	{
		/*
	  tour++;
	  this_thread::sleep_for(chrono::milliseconds(800));
	  //SDL_Delay(800);
		//------------------------------------------------
		
		jeu.faire_deplacer_elements();
		
		jeu.faire_manger_gaulois();

		if( tour % 3 == 0 )
		  {
		    
		    jeu.faire_reproduire_population();
		    }
		
		jeu.faire_vieillir_population_gauloise();
		
		
		//------------------------------------------------
		afficher_grille_SDL(renderer,jeu);
		SDL_RenderClear(renderer);
		
		*/
		while( SDL_PollEvent( &ev ) != 0 ) 
		{
			switch (ev.type) 
			{
				
				case SDL_WINDOWEVENT:
				//--------------------------------------------------
				switch ( ev.window.event )
				{
					case SDL_WINDOWEVENT_CLOSE:
					isRunning = false;
					cout << " dans window event close fermeture evenement type " << ev.type << endl;
					fermeture_SDL(win,renderer);
					SDL_DestroyWindow(win_test_2);
					SDL_DestroyRenderer(renderer_win_test_2);
					break;
				}
				
				break;
				//-----------------------------------------------------
				
				
				
				
				/*
				case SDL_QUIT:
				isRunning = false;
				cout << " fermeture evenement type " << ev.type << endl;
				fermeture_SDL(win,renderer);
				break;*/
			}
		
		}
	}
	
	
	
}

void afficher_grille_SDL(SDL_Renderer *renderer, Jeu_v2 pJeu )
{
	shared_ptr<Gaulois> gaulois;
	Position position ;
	
	
    SDL_Rect single_rect;
	
	/*int nb_lignes = 14 ;
	int nb_cases_par_ligne = 18;*/
	
	single_rect.w = 50;
	single_rect.h = 50;
	
	
	
	//169*221
	
	//Textures
	texture_vide = SDL_CreateTextureFromSurface(renderer, image_vide);

	texture_arbre = SDL_CreateTextureFromSurface(renderer, image_arbre);

	texture_gaulois = SDL_CreateTextureFromSurface(renderer, image_gaulois);

	texture_gauloise = SDL_CreateTextureFromSurface(renderer, image_gauloise);

	texture_animal = SDL_CreateTextureFromSurface(renderer, image_animal);

	texture_gaulois_garcon = SDL_CreateTextureFromSurface(renderer, image_gaulois_enfant_garcon);

	texture_gaulois_fille = SDL_CreateTextureFromSurface(renderer, image_gaulois_enfant_fille);
	
	int pos_x = 40;
	int pos_y = 40;
	int espace = 20 ;
	
	if ( TTF_Init() < 0 ) 
	{
		cout << "Error initializing SDL_ttf: " << TTF_GetError() << endl;
		SDL_DestroyWindow(win);
        SDL_Quit();
        return;
	}
	
	font = TTF_OpenFont("../../police/arial/ARIAL.ttf", 15);
	if ( !font ) {
		cout << "Failed to load font: " << TTF_GetError() << endl;
		SDL_DestroyWindow(win);
        SDL_Quit();
        return;
	}
	
	
	// On met blanc comme couleur
	SDL_Color color = { 255, 0, 0 };

	
	
	
	
	
	 for( set < shared_ptr<Objet> > ::iterator it = pJeu.getGrille()->begin(); it !=pJeu.getGrille()->end() ; it++ )
	 {
		 
		single_rect.x =  (pos_x + espace) * (*it)->getPosition().getAbscisse() ;
		single_rect.y = (pos_y + espace) * (*it)->getPosition().getOrdonnee();
		 
		 
		 
		if((*it)->getType()=="Arbre")
		{
					SDL_RenderCopy(renderer, texture_arbre, NULL, &single_rect);
					
		}
		else if((*it)->getType()=="Gaulois")	
			{
				
				
				gaulois = dynamic_pointer_cast<Gaulois> (*it);
					
					
				
					
				if(gaulois->getSexe()=='M')
				{
				  
				  if ( gaulois->getAge() > 10 )
				    {
				      cout << " Gaulois adulte homme " << gaulois->getPosition().toString() << endl;
				      SDL_RenderCopy(renderer, texture_gaulois, NULL, &single_rect);
				    }else
				    {
				      cout << " Gaulois garcon " << gaulois->getPosition().toString() << endl;
				      SDL_RenderCopy(renderer, texture_gaulois_garcon, NULL, &single_rect);
				    }
					
				}
				else
				{
				  if( gaulois->getAge() > 10 )
				    {
				      cout << " Gauloise adulte femme " << gaulois->getPosition().toString() << endl;
					SDL_RenderCopy(renderer, texture_gauloise, NULL, &single_rect);
				    }else
				    {
				      cout << " Gauloise fille " << gaulois->getPosition().toString() << endl;
				      SDL_RenderCopy(renderer, texture_gaulois_fille, NULL, &single_rect);
				    }
				}
		
		}else if((*it)->getType()=="Animal")
		{
		  cout << "Animal " << (*it)->getPosition().toString() << endl;
			
			SDL_RenderCopy(renderer, texture_animal, NULL, &single_rect);
			
		}
		
		
		
		 
	 }
	 
	 stringstream ss;

	

	SDL_Rect rectangle_ecriture_coordonnees = {};
	
	string chaine_coordonnees = "";
	const char* char_constant_coordonnees = NULL;
	 
	 
	 for(int i=1; i <= pJeu.get_nb_lignes() ; i++)
	 {
		 for(int j = 1 ; j <= pJeu.get_nb_colonnes() ; j++ )
		 {
			 ss.str("");
			 char_constant_coordonnees = NULL;
		 
			
			 ss << i ;
			 ss << "," ;
			 ss << j ;
			 
			 
			 single_rect.x =  (pos_x + espace) * i ;
			 single_rect.y = (pos_y + espace) * j;
			 
			 
			 chaine_coordonnees = ss.str();
			 char_constant_coordonnees = chaine_coordonnees.c_str();
			 
			 cout << char_constant_coordonnees << endl;
			 
			 
			 
			 text = TTF_RenderText_Solid( font, char_constant_coordonnees, color );
			 text_texture = SDL_CreateTextureFromSurface( renderer, text );
			 
			 if ( !text ) {
				cout << "Failed to render text: " << TTF_GetError() << endl;
			}
			 
			 rectangle_ecriture_coordonnees.x = single_rect.x + 0;
			rectangle_ecriture_coordonnees.y = single_rect.y + 0;
			
			rectangle_ecriture_coordonnees.w = text->w;
			rectangle_ecriture_coordonnees.h = text->h;
			
			SDL_RenderCopy( renderer, text_texture, NULL, &rectangle_ecriture_coordonnees );
		 }
	 }
	 
	 SDL_RenderPresent(renderer);
	
	
}


void fermeture_SDL(SDL_Window *win, SDL_Renderer *renderer)
{
	
	//free textures
	SDL_DestroyTexture(texture_vide);
	
	SDL_DestroyTexture(texture_arbre);
	
	SDL_DestroyTexture(texture_gaulois);
	
	SDL_DestroyTexture(texture_gauloise);
	
	SDL_DestroyTexture(texture_animal);
	
	SDL_DestroyTexture(texture_gaulois_garcon);
	
	SDL_DestroyTexture(texture_gaulois_fille);
	
	SDL_DestroyTexture(text_texture);
	
	//free surfaces
	
	SDL_FreeSurface(image_vide);
	
	SDL_FreeSurface(image_arbre);
	
	SDL_FreeSurface(image_gaulois);
	
	SDL_FreeSurface(image_gauloise);
	
	SDL_FreeSurface(image_animal);
	
	SDL_FreeSurface(image_gaulois_enfant_garcon);
	
	SDL_FreeSurface(image_gaulois_enfant_fille);
	
	
	SDL_FreeSurface(text);
	
	//free font
	TTF_CloseFont(font);
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

