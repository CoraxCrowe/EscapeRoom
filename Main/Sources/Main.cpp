#include <iostream>

#include "Main.h"

bool running = true;

int main()
{
  CurrentRoom *currentRoom = new CurrentRoom(0);
  currentRoom->startGame();
  while (running)
  {
    currentRoom->checkLegalMoves();
    currentRoom->printRoomStatus();
    currentRoom->optionSelect();
    currentRoom->catchInput();
    running = currentRoom->endGame();
  }
  return 0;
}