#include <iostream>
#include "CurrentRoom.h"
#include "Main.h"
#include "Room.h"


void CurrentRoom::Move(int n) {
  this->room = rooms[n];
  

}
