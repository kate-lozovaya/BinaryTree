#include <iostream> 
#include <string> 
#include <fstream> 
using namespace std;

template<typename T>
struct Node
{
	T x;
	Node<T> * left;
	Node<T> * right;
};

template<typename T>
class Tree
{
private:
	Node<T> * root;
public:
	Tree()
	{
		root->x = 0;
		root->left = root->right = nullptr;
	}

	~Tree()
	{
		deleteNode(root);
	}

	void deleteNode(Node<T> * node)
	{
		if (node == NULL) return;
		deleteNode(node->left);
		deleteNode(node->right);
		delete node;
	}

	T x_() const
	{
		return root->x;
	}

	Node<T> * left_() const
	{
		return root->left;
	}

	Node<T> * right_() const
	{
		return root->right;
	}

	void add(const T newEl)
	{
		if (root == nullptr)
			root->x = newEl;
		else
		{
			Node<T> * El = new Node<T>;
			Node<T> * curEl = new Node<T>;
			curEl = root;
			while (curEl != nullptr)
			{
				El = curEl;
				if (newEl > curEl->x)
					curEl = curEl->right;
				else
				if (newEl < curEl->x)
					curEl = curEl->left;
				else return;
			}
			if (newEl > El->x)
			{
				El->right = new Node<T>;
				El->right->x = newEl;
				El->right->left = El->right->right = nullptr;
			}
			else
			{
				El->left = new Node<T>;
				El->left->x = newEl;
				El->left->left = El->left->right = nullptr;
			}
		}
	}

	Node<T> * search(const T x)
	{
		Node<T> * curEl = root;
		while (curEl != nullptr)
		{
			if (curEl->x == x)
				return curEl;
			else
			{
				if (x > curEl->x)
					curEl = curEl->right;
				else curEl = curEl->left;
			}
		}
		return nullptr;
	}

	void fIn(string filename)
	{
		ifstream fin;
		fin.open(filename);
		if (!fin.is_open())
			cout << "The file isn't find" << endl;
		else
		{
			deleteNode(root);
			root = new Node<T>;
			root->x = 0;
			root->left = root->right = nullptr;
			if (fin.eof()) return;
			else
			{
