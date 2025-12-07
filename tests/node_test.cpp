#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/node.hpp"
#include "../src/squirrel.hpp"

TEST_CASE("Squirrel stores and returns its name") {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");

    REQUIRE( cheeks.get_name() == "Cheeks" );
    REQUIRE( squeaks.get_name() == "Squeaks" );
}

TEST_CASE("New Node starts with no children") {
    Squirrel cheeks("Cheeks");
    Node node(&cheeks);

    REQUIRE( node.left()  == nullptr );
    REQUIRE( node.right() == nullptr );
}

TEST_CASE("Node can set and retrieve left child") {
    Squirrel parent_squirrel("Parent");
    Squirrel left_squirrel("Lefty");

    Node parent(&parent_squirrel);
    Node left_child(&left_squirrel);

    parent.set_left(&left_child);

    Node* retrieved_left = parent.left();
    REQUIRE( retrieved_left != nullptr );
    REQUIRE( retrieved_left->get_squirrel()->get_name() == "Lefty" );
}

TEST_CASE("Node can set and retrieve right child") {
    Squirrel parent_squirrel("Parent");
    Squirrel right_squirrel("Righty");

    Node parent(&parent_squirrel);
    Node right_child(&right_squirrel);

    parent.set_right(&right_child);

    Node* retrieved_right = parent.right();
    REQUIRE( retrieved_right != nullptr );
    REQUIRE( retrieved_right->get_squirrel()->get_name() == "Righty" );
}

TEST_CASE("Node can have both left and right children and they are distinct") {
    Squirrel root_squirrel("Root");
    Squirrel left_squirrel("Left");
    Squirrel right_squirrel("Right");

    Node root(&root_squirrel);
    Node left_node(&left_squirrel);
    Node right_node(&right_squirrel);

    root.set_left(&left_node);
    root.set_right(&right_node);

    Node* retrieved_left  = root.left();
    Node* retrieved_right = root.right();

    REQUIRE( retrieved_left  != nullptr );
    REQUIRE( retrieved_right != nullptr );
    REQUIRE( retrieved_left  != retrieved_right );

    REQUIRE( retrieved_left->get_squirrel()->get_name()  == "Left" );
    REQUIRE( retrieved_right->get_squirrel()->get_name() == "Right" );
}
