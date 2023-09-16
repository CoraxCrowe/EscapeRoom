#include "Riddle.h"

Riddle::Riddle(std::string text, std::string solution, int room, int door, std::string effect)
{
  this->riddleSolution = solution;
  this->riddleText = text;
  this->indexRoom = room;
  this->indexDoor = door;
  this->effectOnSolve = effect;
}