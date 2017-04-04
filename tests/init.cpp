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

SCENARIO("out_to_file")
{
	Tree<int> tree1, tree2;
	int size1, size2;
	tree1.fIn("Tree.txt");
	size1 = tree1.size(tree1.root_());
	tree1.out_to_file("TreeOut.txt");
	tree2.fIn("TreeOut.txt");
	size2 = tree2.size(tree2.root_());
	REQUIRE(size1 == size2);
}
