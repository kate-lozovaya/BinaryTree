#include <BinaryTree.hpp>
#include <catch.hpp>

SCENARIO("default constructor") 
{
	Tree node;
	REQUIRE(node.x_() == 0);
}

SCENARIO("add")
{
	Tree tree;
	int newEl;
	tree.fIn("Tree.txt");
	std::ifstream("newEl.txt") >> newEl;
	tree.add(newEl);
	REQUIRE(right_() == 7);
}

SCENARIO("search")
{
	Tree tree;
	Node* node;
	tree.fIn("Tree+newEl.txt");
	node = tree.search(5);
	REQUIRE(x_() == 5);
	REQUIRE(left_() == 3);
	REQUIRE(right_() == 7);
}
				
SCENARIO("fIn")
{
	Tree tree;
	tree.fIn("Tree.txt");
	REQUIRE(x_() == 5);
}
