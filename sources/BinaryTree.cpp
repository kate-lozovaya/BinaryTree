#include "BinaryTree.h"

Tree::Tree()
{
	root->x = 0;
	root->left = root->right = NULL;
}
Tree::Tree(Node* node)
{
	root->x = node->x;
	root->left = node->left;
	root->right = node->right;
}
Tree::Tree(const Tree &node)
{
	root->x = node.root->x;
	root->left = node.root->left;
	root->right = node.root->right;
}
void Tree::add(Node* newEl)
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
Tree Tree::search(int x)
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
void Tree::fIn(string filename)
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
void Tree::fOut(string filename)const
{
	ofstream fout;
	fout.open(filename);
	Out(root);
	fout.close();
}
void Tree::Out(Node* curEl)const
{
	curEl = root;
	if (curEl != NULL)
	{
		cout << curEl->x;
		Out(curEl->left);
		Out(curEl->right);
	}
}
