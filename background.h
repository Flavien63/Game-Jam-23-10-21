/*bacground.h*/
/*23 octobre 2021*/
#ifndef background_gard
#define background_gard
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <time.h>

SDL_Texture *load_texture_from_image(char *file_image_name, SDL_Renderer *renderer);
void minerais(int x, int y, SDL_Texture *tableau_minerai, SDL_Renderer *renderer);
void dessin_arriere_plan(SDL_Renderer *renderer, SDL_Texture **tableau_minerai);

#endif