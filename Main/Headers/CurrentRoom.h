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
    int legalmoves[3] = {-1, -1, -1};
    int riddleInRoom[ROOM_AMOUNT];

    
    CurrentRoom(int n);

    void checkLegalMoves();

    void printRoomStatus();

    void optionSelect();

    void debug();


};


#endif