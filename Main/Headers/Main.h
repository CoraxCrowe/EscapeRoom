#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>

#include "Door.h"

extern Room* rooms[3];
extern Door* doors[][3];

void printAdjacentRooms(int roomIndex);

#endif