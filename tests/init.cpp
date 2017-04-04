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
	a = tree.check_search(10);
	REQUIRE(a == false);
}
				
SCENARIO("fIn", "size")
{
	Tree<int> tree;
	int size = 0;
	tree.fIn("Tree.txt");
	size = tree.size(tree.root_());
	REQUIRE(size == 4);
}

SCENARIO("out_to_file")
{
	Tree<int> tree1, tree2;
	tree1.out_to_file("TreeOut.txt");
	tree2.fIn("TreeOut.txt");
	REQUIRE(tree1.size(tree1.root_() == tree2.size(tree2.root_());
}
