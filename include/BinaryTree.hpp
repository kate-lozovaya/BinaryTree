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
	Node(T const& value) : x{ value }, left{ nullptr }, right{ nullptr } {}
};

template<typename T>
class Tree
{
private:
	Node<T> * root;
public:
	Tree()
	{
		root  = nullptr;
	}

	~Tree()
	{
		deleteNode(root);
	}

	void deleteNode(Node<T> * node)
	{
		if (node == nullptr) return;
		deleteNode(node->left);
		deleteNode(node->right);
		delete node;
	}

	T x_() const
	{
		return root->x;
	}

	T left_() const
	{
		return root->left->x;
	}

	T right_() const
	{
		return root->right->x;
	}

	Node<T> * root_() const
	{
		return root;
	}

	void insert(const T& value)
	{
		insert(root, value);
	}

	void insert(Node<T>* & node, const T& value)
	{
		if (node) {
			if (value < node->x) {
				insert(node->left, value);
			}
			else if (value > node->x) {
				insert(node->right, value);
			}
			else {
				return;
			}
		}
		else {
			node = new Node<T>(value);
		}
	}

	Node<T> * search(const T& x)const
	{
		Node<T> * curEl = root;
		while (curEl != nullptr)
		{
			if (curEl->x == x)
				break;
			else
			{
				if (x > curEl->x)
					curEl = curEl->right;
				else curEl = curEl->left;
			}
		}
		return curEl;
	}

	void fIn(const string filename)
	{
		ifstream fin;
		unsigned int k;
		fin.open(filename);
		if (!fin.is_open())
			cout << "The file isn't find" << endl;
		else
		{
			deleteNode(root);
			if (fin.eof()) return;
			else
			{
				fin >> k;
				T newEl;
				for (unsigned int i = 0; i < k; ++i)
				{
					fin >> newEl;
					insert(newEl);
				}
			}
			fin.close();
		}
	}

	unsigned int size(Node<T> * node)const
	{
		unsigned int size_ = 0;
		if (node != nullptr)
			size_ = size(node->left) + 1 + size(node->right);
		return size_;
	}

	void out_to_file(const string filename)const
	{
		ofstream fout;
		fout.open(filename);
		if (!fout.is_open())
			cout << "The file isn't find" << endl;
		else
		{
			unsigned int size_ = size(root);
			if (size_ == 0)
				return;
			fout << size_ << "\t";
			fOut(root, fout);
			fout.close();
		}
	}

	void fOut(Node<T> * node, ostream&stream)const
	{
		if (node != nullptr)
		{
			fOut(node->left, stream);
			stream << node->x << " ";
			fOut(node->right, stream);
		}
	}

	void out(ostream & stream)const
	{
		Out(root, stream, 0);
	}

	void Out(Node<T> * node, ostream&stream, size_t level)const
	{
		Node<T> * curEl = node;
		if (curEl != nullptr)
		{
			Out(curEl->right, stream, level + 1);
			for (unsigned int i = 0; i < level; ++i)
				stream << '-';
			stream << curEl->x << endl;
			Out(curEl->left, stream, level + 1);
		}
	}
};
