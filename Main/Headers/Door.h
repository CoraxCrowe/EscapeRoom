#ifndef _DOOR_H_
#define _DOOR_H_

struct Door {
  int doorNumber;
  int room1;
  int room2;
  bool isUnlocked;
  bool isVisible;

  Door(int room1, int room2);
};

#endif