#ifndef _RIDDLE_H_
#define _RIDDLE_H_

#include <string>

struct Riddle
{
  std::string riddleText = "Placeholder text - question - type A";
  std::string riddleSolution = "A";
  int indexRoom = -1;
  int indexDoor = -1;
  std::string effectOnSolve = "nothing";

  Riddle(std::string text, std::string solution, int room, int door, std::string effect);
};

#endif