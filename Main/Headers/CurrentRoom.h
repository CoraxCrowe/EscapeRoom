#ifndef _CURRENTROOM_H_
#define _CURRENTROOM_H_

#include "Constants.h"

#include "Room.h"
#include "Door.h"
#include "Riddle.h"

class CurrentRoom
{
public:
  int roomIndex;
  Room *room;
  Room *rooms[ROOM_AMOUNT];
  Door *doors[ROOM_AMOUNT][3];
  int legalmoves[3] = {-1, -1, -1};
  int riddleInRoom[ROOM_AMOUNT];
  Riddle *riddles[2] = {nullptr};

  CurrentRoom(int n);

  void checkLegalMoves();

  void printRoomStatus();

  void optionSelect();

  void debug();

  void catchInput();

  bool arrayHasItem(char input, char array[], int arraysize);

  void solveRiddle();

  void move(int x);
  
  void startGame();

  bool endGame();

};

#endif