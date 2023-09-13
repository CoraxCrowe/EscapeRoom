#include <iostream>

#include "Main.h"

Room *rooms[3]{new Room(0), new Room(1), new Room(2)};
Door *doors[][3]{
    {new Door(rooms[0], rooms[1]), nullptr, nullptr},
    {new Door(rooms[1], rooms[0]), new Door(rooms[1], rooms[2]), nullptr},
    {new Door(rooms[2], rooms[1]), nullptr, nullptr}};

int currentRoomIndex = 0;

void printAdjacentRooms(int roomIndex) {
  for (int i = 0; i < 3; i++){
    if (doors[roomIndex][i] == nullptr) {
      continue;
    }
    std::cout << "There is a door towards room " << doors[roomIndex][i]->targetRoom->roomNumber << "\n";
  }
}

int main()
{
  printAdjacentRooms(1);
  return 0;
}