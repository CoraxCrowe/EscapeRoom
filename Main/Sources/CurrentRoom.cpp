#include <iostream>
#include "CurrentRoom.h"


int roomIndex = 0;
Room* room = nullptr;
Room* rooms[3] = {nullptr};
Door* doors[][3] = {nullptr};
   

/*Room *rooms[3]{new Room(0), new Room(1), new Room(2)};
Door *doors[][3]{
    {new Door(rooms[0], rooms[1]), nullptr, nullptr},
    {new Door(rooms[1], rooms[0]), new Door(rooms[1], rooms[2]), nullptr},
    {new Door(rooms[2], rooms[1]), nullptr, nullptr}}; */


CurrentRoom::CurrentRoom(int n) {
  this->roomIndex = n;
  for (int i = 0; i < 3; i++){
    this->rooms[i] = new Room(i);
  }
  this->room = rooms[n];
  
  for (int i = 0; i < 3; i++){
    for (int j = 0; j<3; j++){
      this->doors[i][j] = nullptr;
    }
  }

  this->doors[0][0] = new Door(rooms[0], rooms[1]);
  this->doors[1][0] = new Door(rooms[1], rooms[0]);
  this->doors[1][1] = new Door(rooms[1], rooms[2]);
  this->doors[2][0] = new Door(rooms[2], rooms[1]);



  
}

void CurrentRoom::printAdjacentRooms() {
  for (int i = 0; i < 3; i++){
    if (doors[roomIndex][i] == nullptr) {
      continue;
    }
    std::cout << "There is a door towards room " << this->doors[roomIndex][i]->targetRoom->roomNumber << "\n";
  }
}

void CurrentRoom::move(int index) {
  this->roomIndex = index;
  this->room = rooms[index];
  std::cout << "You move to room " << roomIndex << '\n';

}

void CurrentRoom::debug() {
  std::cout << this->room->roomNumber << "\n";
  std::cout << this->doors[0][0]->targetRoom->roomNumber << '\n';
}