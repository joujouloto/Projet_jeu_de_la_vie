#ifndef MAIN_SDL_H
#define MAIN_SDL_H

#include "Jeu_v2.h"

#include <SDL2/SDL.h>


#include <SDL2/SDL_ttf.h>

void main_sdl();

void afficher_grille_SDL(SDL_Renderer *renderer, _grille grille );


void effacer_sdl(SDL_Window* window, SDL_Renderer * pRendu);

void fermeture_SDL(SDL_Window *win, SDL_Renderer *renderer);

#endif