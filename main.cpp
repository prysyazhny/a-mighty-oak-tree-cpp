#include <iostream>

#include "src/node.hpp"
#include "src/squirrel.hpp"

#include <string>

int main()
{
  Squirrel cheeks = Squirrel("Cheeks");
  Node node_one = Node(&cheeks);

  Squirrel squeaks = Squirrel("Squeaks");
  Node node_two = Node(&squeaks);

  Squirrel fluffybutt = Squirrel("Mr. Fluffy Butt");
  Node node_three = Node(&fluffybutt);

  node_one.set_left(&node_two);
  node_one.set_right(&node_three);

  Node *retrieved_node_one = node_one.left();  // This should retrieve the left node
  std::cout << "Left Node: " <<  retrieved_node_one->get_squirrel()->get_name() << std::endl;
  Node *retrieved_node_two = node_one.right(); // This should retrieve the right node
  std::cout << "Right Node: " << retrieved_node_two->get_squirrel()->get_name() << std::endl;
}
