#ifndef background_gard
#define background_gard
/*bacground.h*/
/*23 octobre 2021*/
#include <SDL2/SDL_image.h>        
#include <SDL2/SDL.h>
#include "tuyau.h"
#include "batiments/batiment_io.h"

SDL_Texture* load_texture_from_image(char  *  file_image_name, SDL_Renderer *renderer );
void dessin_texture(int x, int y, int numero_minerai, SDL_Texture** tableau_minerai, SDL_Renderer* renderer, int, SDL_RendererFlip);
void dessin_arriere_plan(SDL_Renderer* renderer, SDL_Texture** tableau_minerai);
int r_angle(int num_tuyau);
SDL_RendererFlip r_miroir(int num_tuyau);
int r_numero_texture(int num_tuyau);
void dessin_tuyau(listeTuyau_t * tuyau_l, SDL_Texture** tableau_minerai, SDL_Renderer* rendeder);
void dessin_bat(batiment_io_t *carte[20][20], SDL_Renderer *renderer, SDL_Texture ** tableau_texture);

#endif
