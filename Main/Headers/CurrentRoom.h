#ifndef _CURRENTROOM_H_
#define _CURRENTROOM_H_

#include "Room.h"
#include "Door.h"

class CurrentRoom {
  public:
    int roomIndex;
    Room* room;
    Room* rooms[3];
    Door* doors[][3];

    CurrentRoom(int n);

    void printAdjacentRooms();

    void move(int index);

    void debug();


};


#endif