#ifndef _CURRENTROOM_H_
#define _CURRENTROOM_H_

#include "Room.h"
#include "Door.h"
#include "Constants.h"

class CurrentRoom {
  public:
    int roomIndex;
    Room* room;
    Room* rooms[ROOM_AMOUNT];
    Door* doors[ROOM_AMOUNT][3];
    Room* legalmoves[3];

    CurrentRoom(int n);

    void printAdjacentRooms();

    void move(int index);

    void debug();


};


#endif