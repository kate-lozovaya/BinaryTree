#include "BinaryTree.h"

template<class Node> Tree<Node>::Tree()
{
	root->x = 0;
	root->left = root->right = NULL;
}
template<class Node> Tree<Node>::Tree(Node* node)
{
	root->x = node->x;
	root->left = node->left;
	root->right = node->right;
}
template<class Node> Tree<Node>::Tree(const Tree &node)
{
	root->x = node.root->x;
	root->left = node.root->left;
	root->right = node.root->right;
}
template<class Node> int Tree<Node>::x_()const
{
	return root->x;
}
template<class Node> Node* Tree<Node>::left_()const
{
	return root->left;
}
template<class Node> Node* Tree<Node>::right_()const
{
	return root->right;
}
template<class Node> void Tree<Node>::add(Node* newEl)
{
	Node* El = NULL;
	Node* curEl = root;
	while (curEl != NULL)
	{
		El = curEl;
		if (newEl->x >= curEl->x)
			curEl = curEl->right;
		else
			curEl = curEl->left;
	}
	if (newEl->x >= El->x)
		El->right = newEl;
	else
		El->left = newEl;
}
template<class Node> Tree Tree<Node>::search(int x)
{
	Node* curEl = root;
	while (curEl != NULL)
	{
		if (curEl->x == x)
			return curEl;
		else
		{
			if (x >= curEl->x)
				curEl = curEl->right;
			else
				curEl = curEl->left;
		}
	}
	return nullptr;
}
template<class Node> void Tree<Node>::fIn(string filename)
{
	ifstream fin;
	fin.open(filename);
	Node* newEl = NULL;
	if (!fin.is_open())
		cout << "The file isn't find" << endl;
	if (fin.eof()) return;
	else fin >> root->x;
	while (!fin.eof())
	{
		fin >> newEl->x;
		add(newEl);
	}
	fin.close();
}
template<class Node> void Tree<Node>::fOut(string filename)const
{
	ofstream fout;
	fout.open(filename);
	Out(root);
	fout.close();
}
template<class Node> void Tree<Node>::Out(Node* curEl)const
{
	curEl = root;
	if (curEl != NULL)
	{
		cout << curEl->x;
		Out(curEl->left);
		Out(curEl->right);
	}
}
