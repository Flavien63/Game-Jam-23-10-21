#include "liste_c_batiments.h"

cellule_bat_t *creeCelBat()
{
    cellule_bat_t *nouv = NULL;

    nouv = (cellule_bat_t *)malloc(sizeof(cellule_bat_t));

    if (nouv == NULL)
        printf("Erreur malloc : creeCel\n");
    else
        nouv->suiv = NULL;

    return nouv;
}

void insereTeteBat(cellule_bat_t *l, batiment_io_t *batiment)
{
    cellule_bat_t *nouv = creeCelBat();
    if (nouv == NULL)
    {
        printf("Erreur malloc : creeCel\n");
    }
    else
    {
        nouv->val = batiment;
        nouv->suiv = l;
        l = nouv;
    }
}

void supprCelBat(cellule_bat_t **prevCel)
{
    if (*prevCel != NULL)
    {
        cellule_bat_t *suppr = *prevCel;
        *prevCel = suppr->suiv;
        free(suppr);
    }
}

void libereListeBat(cellule_bat_t *l)
{
    cellule_bat_t **prevCel = &l;
    cellule_bat_t *currCel = *prevCel;
    while (currCel != NULL)
    {
        supprCelBat(prevCel);
        currCel = *prevCel;
    }
}

void afficheListeBat(cellule_bat_t * l)
{
    cellule_bat_t *currCel = l;
    printf("Liste \n");
    while (currCel != NULL)
    {
        printf("usine %d\tperiode %d\n", currCel->val->pos_x , currCel->val->stock_entree[0]);
        currCel = currCel->suiv;
    }
    printf("\n");
}

cellule_bat_t **rechPrecBat(cellule_bat_t **head, batiment_io_t* v)
{
  cellule_bat_t **prevCel = head;
  cellule_bat_t *currCel = *prevCel;
  while (currCel != NULL && currCel->val > v)
  {
    prevCel = &currCel->suiv;
    currCel = currCel->suiv;
  }
  return prevCel;
}