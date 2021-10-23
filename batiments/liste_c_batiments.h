#ifndef LIST_C_BATIMENTS_H
#define LIST_C_BATIMENTS_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "batiment_io.h"

typedef struct cellule_bat
{
  batiment_io_t * val;
  struct cellule_bat * suiv;
}cellule_bat_t;

cellule_bat_t *creeCelBat();

void insereTeteBat(cellule_bat_t *l, batiment_io_t *batiment);

void supprCelBat(cellule_bat_t **prevCel);

void libereListeBat(cellule_bat_t *l);

void afficheListeBat(cellule_bat_t *l);

cellule_bat_t **rechPrecBat(cellule_bat_t **head, batiment_io_t* v);

#endif