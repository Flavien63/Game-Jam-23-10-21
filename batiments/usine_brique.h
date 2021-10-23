#ifndef USINE_BRIQUE_H
#define USINE_BRIQUE_H

#include "batiment_io.h"
#include "liste_c_batiments.h"

#define MAX_STOCK_UB_E0 2
#define MAX_STOCK_UB_S 1

void newUsine_brique(batiment_io_t * tab_bat[C_MAX][C_MAX] , int pos_x , int pos_y);

int processUsine_Brique(batiment_io_t * batiment);

void fctUsine_Brique(batiment_io_t * batiment);

#endif