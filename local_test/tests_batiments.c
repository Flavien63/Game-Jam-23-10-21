#include "tests_batiments.h"

void TestCreation()
{
    batiment_io_t batiment = NULL;

    newBatiment(&batiment , 18 , 24 , 2 , 1);

    deleteBatiment(batiment);
}