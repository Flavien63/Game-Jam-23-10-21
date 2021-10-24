#ifndef MAP_H
#define MAP_H

#include "tuyau.h"
#include "batiments/batiment_io.h"

#define TAILLE_MAP 20
#define NB_MAX_CASE (20 * 20)

#define NB_MAX_TUYAU 10


struct tuyau;

typedef struct map
{
    int vierge[TAILLE_MAP][TAILLE_MAP];
    batiment_io_t *batiment[TAILLE_MAP][TAILLE_MAP];
    struct tuyau **tuyau[TAILLE_MAP][TAILLE_MAP];

} map_t;

#endif
