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
	int size1, size2;
	tree.fIn("Tree.txt");
	size1 = tree.size(tree.root_());
	tree.insert(7);
	size2 = tree.size(tree.root_());
	REQUIRE((size1 + 1) == size2);
}

SCENARIO("search")
{
	Tree<int> tree;
	Node<int> * node;
	bool a;
	tree.fIn("Tree+newEl.txt");
	a = tree.check_search(7);
	REQUIRE(a == true);
}
				
SCENARIO("fIn")
{
	Tree<int> tree;
	tree.fIn("Tree.txt");
	REQUIRE(tree.x_() == 5);
}
