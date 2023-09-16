#include <iostream>
#include "CurrentRoom.h"

int roomIndex = 0;
Room *room = nullptr;
Room *rooms[ROOM_AMOUNT] = {nullptr};
Door *doors[ROOM_AMOUNT][3] = {nullptr};
Riddle *riddles[3] = {nullptr};

CurrentRoom::CurrentRoom(int n)
{
  this->roomIndex = n;
  for (int i = 0; i < ROOM_AMOUNT; i++)
  {
    this->rooms[i] = new Room(i);
  }
  this->room = rooms[n];

  for (int i = 0; i < ROOM_AMOUNT; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      this->doors[i][j] = nullptr;
    }
  }

  this->doors[0][0] = new Door(rooms[0], rooms[1]);
  this->doors[1][0] = new Door(rooms[1], rooms[0]);
  this->doors[1][1] = new Door(rooms[1], rooms[2]);
  this->doors[1][2] = new Door(rooms[1], rooms[3]);
  this->doors[2][0] = new Door(rooms[2], rooms[1]);
  this->doors[3][0] = new Door(rooms[3], rooms[1]);
  this->doors[3][1] = new Door(rooms[3], rooms[4], false, true);
  this->doors[3][2] = new Door(rooms[3], rooms[5]);
  this->doors[4][0] = new Door(rooms[4], rooms[3]);
  this->doors[5][0] = new Door(rooms[5], rooms[3]);
  this->doors[5][1] = new Door(rooms[5], rooms[6], false, true);
  this->doors[5][2] = new Door(rooms[5], rooms[7], true, false);
  this->doors[6][0] = new Door(rooms[6], rooms[5]);
  this->doors[7][0] = new Door(rooms[7], rooms[6]);

  for (int i = 0; i < ROOM_AMOUNT; i++)
  {
    riddleInRoom[i] = -1;
  }

  riddleInRoom[2] = 0;
  riddleInRoom[4] = 1;
  riddleInRoom[6] = 2;

  riddles[0] = new Riddle("placeholder type B", "B", 3, 1, "unlock");
  riddles[1] = new Riddle("placeholder type A", "A", 5, 1, "unlock");
  riddles[2] = new Riddle("placeholder type C", "C", 5, 2, "discover");
}

void CurrentRoom::checkLegalMoves()
{
  int temp = 0;
  for (int i = 0; i < 3; i++)
  {
    legalmoves[temp] = -1;
    if (doors[roomIndex][i] == nullptr || !doors[roomIndex][i]->isVisible)
    {
      continue;
    }
    legalmoves[temp] = this->doors[roomIndex][i]->targetRoom->roomNumber;
    temp++;
  }
}

void CurrentRoom::optionSelect()
{
  std::cout << "\n\n";
  if (riddleInRoom[roomIndex] >= 0)
  {
    std::cout << "Solve riddle: press S;\n";
  }
  for (int i = 0; i < 3; i++)
  {
    if (legalmoves[i] != -1)
    {
      std::cout << "Move to room " << legalmoves[i] << ": press " << legalmoves[i] << '\n';
    }
  }
}

void ::CurrentRoom::printRoomStatus()
{
  for (int i = 0; i < 3; i++)
  {
    if (doors[roomIndex][i] == nullptr || !doors[roomIndex][i]->isVisible)
    {
      continue;
    }

    if (doors[roomIndex][i]->isUnlocked)
    {
      std::cout << "A door leads to room " << doors[roomIndex][i]->targetRoom->roomNumber << ", it's unlocked.\n";
    }
    else
    {
      std::cout << "A door leads to room " << doors[roomIndex][i]->targetRoom->roomNumber << ", it's locked.\n";
    }
  }
}

bool CurrentRoom::arrayHasItem(char input, char array[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    if (array[i] == input)
    {
      return true;
    }
  }
  return false;
}

void CurrentRoom::catchInput()
{
  char validInputs[4];
  int arraySize = 0;
  char userInput = 'N';

  if (riddleInRoom[roomIndex] >= 0)
  {
    validInputs[arraySize] = 'S';
    arraySize++;
  }

  for (int i = 0; i < 3; i++)
  {
    if (doors[roomIndex][i] == nullptr || !doors[roomIndex][i]->isVisible)
    {
      continue;
    }

    if (doors[roomIndex][i]->isUnlocked && doors[roomIndex][i] != nullptr && doors[roomIndex][i]->isVisible)
    {
      validInputs[arraySize] = doors[roomIndex][i]->targetRoom->roomNumber + 48;
      arraySize++;
    }
  }
  do
  {
    std::cout << "Pick your next move: \n";
    std::cin >> userInput;
  } while (!arrayHasItem(userInput, validInputs, arraySize));

  if (userInput == 'S')
  {
    solveRiddle();
  }
  else
  {
    move(userInput - 48);
  }
}

void CurrentRoom::solveRiddle()
{
  Riddle *currentRiddle = riddles[riddleInRoom[roomIndex]];

  std::string tempAnswer = "blank";
  std::cout << "The riddle reads: \n\n"
            << currentRiddle->riddleText << "\n\n";
  std::cout << "Your answer: ";
  std::cin >> tempAnswer;
  if (tempAnswer == currentRiddle->riddleSolution)
  {
    std::cout << "You hear a clicking sound...\nThe door in room " << currentRiddle->indexRoom;
    if (currentRiddle->effectOnSolve == "unlock")
    {
      doors[currentRiddle->indexRoom][currentRiddle->indexDoor]->isUnlocked = true;
      std::cout << " was unlocked!\n";
    }
    else
    {
      doors[currentRiddle->indexRoom][currentRiddle->indexDoor]->isVisible = true;
      std::cout << " was revealed!\n";
    }
    return;
  }
  std::cout << "Nothing happens, the answer must be wrong...\n\n";
}

void CurrentRoom::move(int x)
{
  std::cout << "You move to room " << x << "\n";
  roomIndex = x;
  room = rooms[x];
}

void CurrentRoom::debug()
{
}