#include "tests_batiments.h"

void testCreation()
{
    batiment_io_t * batiment = NULL;
    int erreur = 0;

    newBatiment(&batiment , 18 , 24 , 2 , 1);
    printf("pos_x = %d\n" , batiment->pos_x);
    erreur = newDoor(batiment , 0 , 0 , 1);
    printf("type port0 = %d\n" , batiment->d_top.type);
    deleteDoor(batiment , 0);

    deleteBatiment(batiment);
}

void testCreationUsine()
{
    batiment_io_t * tab_bat[20][20];


    newUsine_brique(tab_bat, 15 , 12);
    newDoor(tab_bat[15][12] , 0 , 0 , 0);
    printf("type port0 = %d\n" , tab_bat[15][12]->d_top.type);
    fctUsine_Brique(tab_bat[15][12]);
    deleteDoor(tab_bat[15][12] , 0);
    deleteBatiment(tab_bat[15][12]);
}