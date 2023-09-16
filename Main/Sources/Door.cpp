#include "Door.h"
#include "Room.h"

Room *sourceRoom = nullptr;
Room *targetRoom = nullptr;

Door::Door(Room *sourceRoom, Room *targetRoom)
{
  this->sourceRoom = sourceRoom;
  this->targetRoom = targetRoom;
  this->isUnlocked = true;
  this->isVisible = true;
}

Door::Door(Room *sourceRoom, Room *targetRoom, bool isUnlocked, bool isVisible)
{
  this->sourceRoom = sourceRoom;
  this->targetRoom = targetRoom;
  this->isUnlocked = isUnlocked;
  this->isVisible = isVisible;
}