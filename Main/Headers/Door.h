#ifndef _DOOR_H_
#define _DOOR_H_

#include "Room.h"

struct Door
{
  Room *sourceRoom;
  Room *targetRoom;

  Door(Room *sourceRoom, Room *targetRoom);
};

#endif