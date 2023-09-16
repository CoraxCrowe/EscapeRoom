#include <iostream>

#include "Main.h"

int main()
{
  CurrentRoom *currentRoom = new CurrentRoom(0);
  while (true)
  {
    currentRoom->checkLegalMoves();
    currentRoom->printRoomStatus();
    currentRoom->optionSelect();
    currentRoom->catchInput();
  }
  return 0;
}