#include "CurrentRoom.h"
#include "Main.h"
#include "Room.h"

#include <iostream>

int roomList[] = {1, 2, 3, 4, 5, 6, 7};
int doorList[][3] = {{2, -1, -1},
                     {1, 3, 4},
                     {2, -1, -1},
                     {2, 5, 6},
                     {4, -1, -1},
                     {4, 7, 8},
                     {6, -1, -1},
                     {6, -1, -1}};
Room* rooms[8];

void initialize(Room* rooms) {
  for (int i = 0; i < 8; i++) {
    rooms[i] = new Room(i);
  }

  CurrentRoom* currentRoom = new CurrentRoom();
}

void listDoors(CurrentRoom* currentRoom) {
  for (int i = 0; i < 3; i++) {
    if (currentRoom->room->doors[i] == nullptr) {
      continue;
    } else {
      std::cout << "A door leads to room " << currentRoom->room->doors[i]->room2;
    }
  }
}

int main() {


  return 0;
}