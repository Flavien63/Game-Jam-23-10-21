#ifndef BATIMENT_IO_H
#define BATIMENT_IO_H

#define C_MAX 20

/*
types de batiment : usine_brique = 0;
*/

typedef struct batiment_io
{
    int pos_x;
    int pos_y;
    int type;
    int rang;
    int niveau;

    int * stock_entree;
    int stock_sortie;
    int nb_sortie;
    int next_s;

    int door_T[4];          //-1 = pas de tuyau ; 0 = entree ; 1 = sortie
}batiment_io_t;             //door_T[0] = top ; door_T[1] = right ; door_T[2] = bottom ; door_T[3] = left

int initBatiment(batiment_io_t ** batiment , int nb_s_entree);

void newBatiment(batiment_io_t ** batiment , int pos_x , int pos_y , int nb_s_entree , int rang);

void deleteBatiment(batiment_io_t * batiment);

int newDoor(batiment_io_t * batiment , int side , int type);

int deleteDoor(batiment_io_t * batiment , int side);

int stockEntreePlein(batiment_io_t * batiment , int stock , int max);

int stockSortieVide(batiment_io_t * batiment);

int destRessource(batiment_io_t * batiment);

#endif