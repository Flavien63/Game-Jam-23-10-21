#ifndef DOOR_H
#define DOOR_H

typedef struct door
{
    int * tube;
    int type;           //2 types de port : 0 = entree ; 1 = sortie.
}door_t;

#endif