#ifndef USINE_BRIQUE_H
#define USINE_BRIQUE_H

#include "batiment_io.h"

#define MAX_STOCK_UB_E0 2
#define MAX_STOCK_UB_S 1

/****************************************************************************************/
/*newUsinne_brique : cree un nouveau batiment de type Usine_Brique selon les bonnes spec*/
/****************************************************************************************/
void newUsine_brique(batiment_io_t * tab_bat[C_MAX][C_MAX] , int pos_x , int pos_y);

/****************************************************************************************/
/*processUsinne_brique : produit la bonne ressource selon les spec de Usine_brique      */
/****************************************************************************************/
int processUsine_Brique(batiment_io_t * batiment);

/****************************************************************************************/
/*fctUsinne_brique : fonction qui fait tourner le batiment sur un tic                   */
/****************************************************************************************/
void fctUsine_Brique(batiment_io_t * batiment);

#endif