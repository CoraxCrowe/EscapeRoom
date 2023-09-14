#include <iostream>
#include "CurrentRoom.h"


int roomIndex = 0;
Room* room = nullptr;

void CurrentRoom::printAdjacentRooms(Door* doors[][3]) {
  for (int i = 0; i < 3; i++){
    if (doors[this->roomIndex][i] == nullptr) {
      continue;
    }
    std::cout << "There is a door towards room " << doors[roomIndex][i]->targetRoom->roomNumber << "\n";
  }
}