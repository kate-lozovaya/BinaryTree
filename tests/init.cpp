#include <BinaryTree.hpp>
#include <catch.hpp>

SCENARIO("default constructor") 
{
	Tree node;
	REQUIRE(node.x_() == 0);
	REQUIRE(node.left_() == NULL);
	REQUIRE(node.right_() == NULL);
}

SCENARIO("add")
{
	Tree tree1, tree2;
	Node* newEl;
	tree1.fIn("Tree.txt");
	std::ifstream("newEl.txt") >> newEl->x;
	tree1.add(newEl);
	tree2.fIn("Tree+newEl.txt");
	REQUIRE(tree1 == tree2);
}

SCENARIO("search")
{
	Tree tree;
	Node* node;
	tree.fIn("Tree.txt");
	node.fIn("Node.txt");
	REQUIRE(tree.search(7) == node);
}
				
SCENARIO("fIn")
{
	Tree tree;
	tree.fIn("Tree.txt");
	REQUIRE(tree->x_ == 5);
}

SCENARIO("fOut")
{
	Tree tree1, tree2;
	tree1.fIn("Tree.txt");
	tree2.fIn("TreeOut.txt");
	tree1.fOut("TreeOut.txt");
	tree1.fIn("TreeOut.txt");
	REQUIRE(tree1 == tree2);
}
