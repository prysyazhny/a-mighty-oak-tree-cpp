#pragma once

#include "squirrel.hpp"
#include <string>

class Node
{
private:
  Squirrel *squirrel;
  Node *left_node;
  Node *right_node;

public:
  Node(Squirrel *squirrel)
  {
    this->squirrel = squirrel;
    this->left_node = nullptr;
    this->right_node = nullptr;
  }

  void set_left(Node *left)
  {
    this->left_node = left;
  }

  void set_right(Node *right)
  {
    this->right_node = right;
  }

  Node *left()
  {
    return this->left_node;
  }

  Node *right()
  {
    return this->right_node;
  }

  Squirrel *get_squirrel()
  {
    return this->squirrel;
  }
};