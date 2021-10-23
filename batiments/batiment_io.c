#include <stdio.h>
#include <stdlib.h>
#include "batiment_io.h"

int initBatiment(batiment_io_t ** batiment , int nb_s_entree , int nb_s_sortie)
{
    int erreur = 0;

    *batiment = (batiment_io_t *)malloc(sizeof(batiment_io_t));
    if (*batiment != NULL)
    {
        (*batiment)->stock_entree = (int *)malloc(sizeof(int) * nb_s_entree);
        (*batiment)->stock_sortie = (int *)malloc(sizeof(int) * nb_s_sortie);
        if ((*batiment)->stock_entree == NULL || (*batiment)->stock_sortie == NULL)
        {
            erreur = 1;
        }
    }
    else
    {
        erreur = 1;
    }

    return erreur;
}

int newDoor(batiment_io_t * batiment , int side , int * tube , int type)
{
    int erreur = 0;

    switch (side)
    {
        case 0 :
            batiment->d_top.tube = tube;
            batiment->d_top.type = type;
            break;
        case 1 :
            batiment->d_right.tube = tube;
            batiment->d_right.type = type;
            break;
        case 2 :
            batiment->d_bottom.tube = tube;
            batiment->d_bottom.type = type;
            break;
        case 3 :
            batiment->d_left.tube = tube;
            batiment->d_left.type = type;
            break;
        default :
            erreur = 1;
    }

    return erreur;
}