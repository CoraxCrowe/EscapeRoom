#include <iostream>
#include "CurrentRoom.h"


int roomIndex = 0;

void CurrentRoom::printAdjacentRooms(Door* doors[][3]) {
  for (int i = 0; i < 3; i++){
    if (doors[this->roomIndex][i] == nullptr) {
      continue;
    }
    std::cout << "There is a door towards room " << doors[roomIndex][i]->targetRoom->roomNumber << "\n";
  }
}

void CurrentRoom::move(int index) {
  this->roomIndex = index;
  std::cout << "You move to room " << roomIndex << '\n';

}