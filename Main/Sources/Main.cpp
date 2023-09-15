#include <iostream>

#include "Main.h"

int main()
{
  CurrentRoom* currentRoom = new CurrentRoom(1);
  while(true) {
  currentRoom->checkLegalMoves();

  currentRoom->printRoomStatus();
  currentRoom->optionSelect();
  currentRoom->catchInput();
  currentRoom->debug();
  }
  return 0;
}