#ifndef _RIDDLE_H_
#define _RIDDLE_H_

#include <string>

struct Riddle {
  std::string riddleText = "Placeholder text - question - type A";
  std::string riddleSolution = "A";

  Riddle(std::string text, std::string solution); 

};

#endif