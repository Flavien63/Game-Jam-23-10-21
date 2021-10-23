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
    batiment_io_t * lst_batiment[1];            //a changer avec la creation de la liste des usines
    
    newUsine_brique(lst_batiment , 18 , 34);
    fctUsine_Brique(lst_batiment[0]);
    newDoor(lst_batiment[0] , 0 , 0 , 1);
    printf("type port0 = %d\n" , lst_batiment[0]->d_top.type);
    deleteDoor(lst_batiment[0] , 0);
    deleteBatiment(lst_batiment[0]);
}