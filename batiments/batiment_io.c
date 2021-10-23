#include <stdio.h>
#include <stdlib.h>
#include "batiment_io.h"

int initBatiment(batiment_io_t ** batiment , int nb_s_entree)
{
    int erreur = 0;
    *batiment = NULL;

    *batiment = (batiment_io_t *)malloc(sizeof(batiment_io_t));
    if (*batiment != NULL)
    {
        (*batiment)->stock_entree = (int *)malloc(sizeof(int) * nb_s_entree);
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

void newBatiment(batiment_io_t ** batiment , int pos_x , int pos_y , int nb_s_entree, int rang)
{
    int erreur = 0;

    erreur = initBatiment(batiment , nb_s_entree);
    if (!erreur)
    {
        (*batiment)->pos_x = pos_x;
        (*batiment)->pos_y = pos_y;
        (*batiment)->rang = rang;
        (*batiment)->niveau = 1;
        (*batiment)->nb_sortie = 0;
        (*batiment)->next_s = 0;
        (*batiment)->stock_sortie = 0;
    }
    else
    {
        printf("Erreur a la creation du batiment\n");
    }
}

void deleteBatiment(batiment_io_t * batiment)
{
    free(batiment->stock_entree);
    free(batiment);
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
    if (!erreur && type == 1)
    {
        batiment->nb_sortie++;
    }

    return erreur;
}

int deleteDoor(batiment_io_t * batiment , int * tube)
{
    int erreur = 0;
    int type;

    if (batiment != NULL)
    {
        if (batiment->d_top.tube == tube)
        {
            batiment->d_top.tube = NULL;
            type = batiment->d_top.type;
        }
        else if (batiment->d_right.tube == tube)
        {
            batiment->d_right.tube = NULL;
            type = batiment->d_right.type;
        }
        else if (batiment->d_bottom.tube == tube)
        {
            batiment->d_bottom.tube = NULL;
            type = batiment->d_bottom.type;
        }
        else if (batiment->d_left.tube == tube)
        {
            batiment->d_left.tube = NULL;
            type = batiment->d_left.type;
        }
        else
        {
            erreur = 1;
        }
    }
    else
    {
        erreur = 2;
    }

    if (!erreur && type == 1)
    {
        batiment->nb_sortie--;
    }

    return erreur;
}

int stockEntreePlein(batiment_io_t * batiment , int stock , int max)
{
    return(batiment->stock_entree[stock] == max);
}

int stockSortieVide(batiment_io_t * batiment)
{
    return(batiment->stock_sortie == 0);
}

int sendRessource(batiment_io_t * batiment)
{
    int erreur = 0;

    if (batiment->nb_sortie != 0 && ! stockSortieVide(batiment))
    {
        batiment->next_s = (batiment->next_s + 1) % batiment->nb_sortie;
        //fonction de test si le tube est plein
        //fonction d'ajout dans un tube
    }
    else
    {
        erreur = 1;
    }

    return erreur;
}