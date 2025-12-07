#pragma once

#include <string>

class Squirrel
{
private:
  std::string name;

public:
  Squirrel(std::string name)
  {
    this->name = name;
  }

  std::string get_name()
  {
    return this->name;
  }
};