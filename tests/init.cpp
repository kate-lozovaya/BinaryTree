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

SCENARIO("prev_")
{
	Tree<int> tree;
	Node<int> * node;
	tree.insert(3);
	tree.insert(4);
	tree.insert(2);
	node = tree.prev_(4);
	REQUIRE(node->x == 3);
}

SCENARIO("out_to_file", "fIn")
{
	Tree<int> tree1, tree2;
	int size1, size2;
	tree1.insert(3);
	tree1.insert(4);
	tree1.out_to_file("TreeOut.txt");
	size1 = tree1.size(tree1.root_());
	tree2.fIn("TreeOut.txt");
	size2 = tree2.size(tree2.root_());
	REQUIRE(size1 == 2);
	REQUIRE(size2 == 2);
	REQUIRE(tree2.x_() == 3);
}
