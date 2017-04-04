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
	int newEl;
	tree.fIn("Tree.txt");
	std::ifstream("newEl.txt") >> newEl;
	tree.insert(newEl);
	REQUIRE(tree.right_() == 7);
}

SCENARIO("search")
{
	Tree<int> tree;
	Node<int> * node;
	tree.fIn("Tree+newEl.txt");
	node = tree.search(5);
	REQUIRE(tree.x_() == 5);
	REQUIRE(tree.left_() == 3);
	REQUIRE(tree.right_() == 7);
}
				
SCENARIO("fIn")
{
	Tree<int> tree;
	tree.fIn("Tree.txt");
	REQUIRE(tree.x_() == 5);
}
