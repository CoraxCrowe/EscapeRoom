#ifndef _MAIN_H_
#define _MAIN_H_

#include "Room.h"
#include "CurrentRoom.h"

#include <algorithm>
#include <iostream>

extern int roomList[];
extern int doorList[][3];
extern Room* rooms[8];

void initialize(Room* rooms);
void listDoors(CurrentRoom* currentRoom);

#endif