/*bacground.c*/
/*23 octobre 2021*/
#include "background.h"

/*gcc fade.c -o fade -Wall -Wextra -g -lSDL2 -lSDL2_image */

SDL_Texture *load_texture_from_image(char *file_image_name, SDL_Renderer *renderer)
{
	SDL_Surface *my_image = NULL;	// Variable de passage
	SDL_Texture *my_texture = NULL; // La texture

	my_image = IMG_Load(file_image_name); // Chargement de l'image dans la surface
										  // image=SDL_LoadBMP(file_image_name); fonction standard de la SDL,
										  // uniquement possible si l'image est au format bmp */
	if (my_image == NULL)
		printf("my-image is NULL\n");

	my_texture = SDL_CreateTextureFromSurface(renderer, my_image); // Chargement de l'image de la surface vers la texture
	SDL_FreeSurface(my_image);									   // la SDL_Surface ne sert que comme élément transitoire
	if (my_texture == NULL)
		printf("my-texture is NULL\n");

	return my_texture;
}

void minerais(int x, int y, SDL_Texture *texture, SDL_Renderer *renderer)
{
	SDL_Rect destination = {0};
	destination.x = x * 45;
	destination.y = y * 45;
	destination.w = 45;
	destination.h = 45;
	SDL_RenderCopy(renderer, texture, NULL, &destination);
}

void dessin_arriere_plan(SDL_Renderer *renderer, SDL_Texture **tableau_minerai)
{
	//dessin de la carte au hasard sans cluster
    /*for (int j = 0; j < 20; ++j)
    {
        for (int i = 0; i < 20; ++i)
        {
            carte[i][j] = ((hasard < 910) && (hasard >= 850)) + ((hasard < 960) && (hasard >= 910)) * 2 + ((hasard < 980) && (hasard >= 960)) * 3 + ((hasard < 995) && (hasard >= 980)) * 4 + ((hasard < 1000) && (hasard >= 995)) * 5;
			printf("La case %d %d aura la texture : %d\n", i, j, carte[i][j]);
			printf("Le nombre au hasard est : %d\n", hasard);
			hasard = rand() % 1000;
        }
    }*/

	int carte[20][20] = {{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			 			 {0,1,1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0},
			 			 {0,1,1,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,4,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0},
						 {0,0,0,0,0,0,0,0,0,7,9,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,8,10,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,3,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						 {0,1,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0},
						 {0,1,1,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0},
						 {0,0,1,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
						 {0,0,0,7,13,9,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
						 {0,0,0,11,15,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,8,12,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};



	for (int j = 0; j < 20; ++j)
	{
		for (int i = 0; i < 20; ++i)
		{
			minerais(i, j, tableau_minerai[carte[i][j]], renderer);
		}
	}
}
