#ifndef _CURRENTROOM_H_
#define _CURRENTROOM_H_

#include "Room.h"
#include "Door.h"

class CurrentRoom {
  public:
    int roomIndex;

    void printAdjacentRooms(Door* doors[][3]);

    void move(int index);
};


#endif