#include "tests_batiments.h"

void testCreation()
{
    batiment_io_t * batiment = NULL;
    int erreur = 0;

    newBatiment(&batiment , 18 , 24 , 1 , 1);
    
    printf("pos_x = %d\n" , batiment->pos_x);
    erreur = newDoor(batiment , 2 , 0);
    printf("type port0 = %d\n" , batiment->door_T[2]);
    deleteDoor(batiment , 0);

    deleteBatiment(batiment);
}

void testCreationUsine()
{
    batiment_io_t * tab_bat[20][20];


    newUsine_brique(tab_bat, 15 , 12);
    newDoor(tab_bat[15][12] , 0 , 1);
    fctUsine_Brique(tab_bat[15][12]);
    printf("pos_x = %d\n" , tab_bat[15][12]->pos_x);
    printf("type port0 = %d\n" , tab_bat[15][12]->door_T[0]);
    deleteDoor(tab_bat[15][12] , 0);
    deleteBatiment(tab_bat[15][12]);
}