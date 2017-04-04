#include "BinaryTree.hpp"
#include <catch.hpp>

SCENARIO("default constructor") 
{
	Tree<int> node;
	REQUIRE(node.root_() == nullptr);
}

SCENARIO("insert")
{
	Tree<int> tree;
	tree.insert(7);
	REQUIRE(tree.x_() == 7);
	REQUIRE(tree.left_() == nullptr);
	REQUIRE(tree.right_() == nullptr);
}

SCENARIO("search")
{
	Tree<int> tree;
	bool a;
	tree.insert(7);
	a = tree.check_search(7);
	REQUIRE(a == true);
}

SCENARIO("size")
{
	Tree<int> tree;
	int size = 0;
	tree.insert(7);
	size = tree.size(tree.root_());
	REQUIRE(size == 1);
}
