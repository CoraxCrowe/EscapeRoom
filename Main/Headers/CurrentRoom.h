#ifndef _CURRENTROOM_H_
#define _CURRENTROOM_H_

#include "Door.h"
#include "Room.h"
#include "Riddle.h"

class CurrentRoom {
  public:
    void Move(int n);
    Room* room;


};

#endif