#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<typename T>
struct Node
{
	T x;
	Node* left;
	Node* right;
};

template<class Node>
class Tree
{
private:
	Node* root;
public:
	Tree();
	Tree(Node* node);
	Tree(const Tree &node);
	int x_()const;
	Node* left_()const;
	Node* right_()const;
	void add(Node* newEl);
	Tree search(int x);
	void fIn(string filename);
	void fOut(string filename)const;
	void Out(Node* curEl)const;
};
