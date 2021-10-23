#ifndef BATIMENT_IO_H
#define BATIMENT_IO_H

#include "door.h"

typedef struct batiment_io
{
    int pos_x;
    int pos_y;
    int rang;
    int niveau;

    int * stock_entree;
    int stock_sortie;
    int nb_sortie;
    int next_s;

    door_t d_top;
    door_t d_bottom;
    door_t d_left;
    door_t d_right;
}batiment_io_t;

int initBatiment(batiment_io_t ** batiment , int nb_s_entree);

void newBatiment(batiment_io_t ** batiment , int pos_x , int pos_y , int nb_s_entree , int rang);

void deleteBatiment(batiment_io_t * batiment);

int newDoor(batiment_io_t * batiment , int side , int * tube , int type);

int deleteDoor(batiment_io_t * batiment , int * tube);

int stockEntreePlein(batiment_io_t * batiment , int stock , int max);

int stockSortieVide(batiment_io_t * batiment);

int sendRessource(batiment_io_t * batiment);

#endif