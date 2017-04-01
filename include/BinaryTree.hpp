#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
	int x;
	Node* left;
	Node* right;
};

class Tree
{
private:
	Node* root;
public:
	Tree();
	Tree(Node* node);
	Tree(const Tree &node);
	void add(Node* newEl);
	Tree search(int x);
	void fIn(string filename);
	void fOut(string filename)const;
	void Out(Node* curEl)const;
};
