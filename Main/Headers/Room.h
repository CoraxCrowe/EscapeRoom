#ifndef _ROOM_H_
#define _ROOM_H_

#include "Door.h"
#include "Riddle.h"

struct Room {
  int roomNumber;
  Door* doors[3];

  Room(int roomNumber);

};

#endif