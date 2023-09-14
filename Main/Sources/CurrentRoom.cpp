#include <iostream>
#include "CurrentRoom.h"

int roomIndex = 0;
Room *room = nullptr;
Room *rooms[ROOM_AMOUNT] = {nullptr};
Door *doors[ROOM_AMOUNT][3] = {nullptr};
int riddleInRoom[ROOM_AMOUNT] = {0};

CurrentRoom::CurrentRoom(int n)
{
  this->roomIndex = n;
  for (int i = 0; i < 3; i++)
  {
    this->rooms[i] = new Room(i);
  }
  this->room = rooms[n];

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      this->doors[i][j] = nullptr;
    }
  }

  this->doors[0][0] = new Door(rooms[0], rooms[1], true, false);
  this->doors[1][0] = new Door(rooms[1], rooms[0]);
  this->doors[1][1] = new Door(rooms[1], rooms[2]);
  this->doors[2][0] = new Door(rooms[2], rooms[1]);

  for(int riddle : riddleInRoom) {
    riddle = 0;
  }
}

void CurrentRoom::checkLegalMoves()
{
  for (int i = 0; i < 3; i++)
  { 
    legalmoves[i] = -1;
    if (doors[roomIndex][i] == nullptr || doors[roomIndex][i]->isVisible == false)
    {
      continue;
    }
    legalmoves[i] = this->doors[roomIndex][i]->targetRoom->roomNumber;
  }
}

void CurrentRoom::optionSelect()
{
  std::cout << "What's your next move?\n\n";
  if (riddleInRoom[roomIndex]) {
    std::cout << "Solve riddle: press S;\n";
  }
  for (int i = 0; i < 3; i++) {
    if (legalmoves[i] != -1) {
      std::cout << "Move to room " << legalmoves[i] << ": press " << legalmoves[i];
    }
  }
}

void CurrentRoom::debug()
{
  printRoomStatus();

}

void::CurrentRoom::printRoomStatus()
{
  for (int i = 0; i < 3; i++) {
    if (doors[roomIndex][i] == nullptr || !doors[roomIndex][i]->isVisible) {
      continue;
    }
    
    if (doors[roomIndex][i]->isUnlocked) 
    {
      std::cout << "A door leads to room " << doors[roomIndex][i]->targetRoom->roomNumber << ", it's unlocked.\n";
    } else 
    {
      std::cout << "A door leads to room " << doors[roomIndex][i]->targetRoom->roomNumber << ", it's locked.\n";
    }
  }
}

