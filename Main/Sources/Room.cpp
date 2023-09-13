#include "Room.h"
#include "Main.h"

Room::Room(int roomNumber) {
  this->roomNumber = roomNumber;

  for (int i = 0; i < 3; i++) {
    this->doors[i] = nullptr;
  }

  for (int i = 0; i < 3; i++) {
    this->doors[i] = new Door(roomNumber, doorList[roomNumber-1][i]);
    
    if (this->doors[i]->room2 == -1) {
      doors[i] = nullptr;
    }
  }
}