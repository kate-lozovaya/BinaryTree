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

	Node<T> * left_() const
	{
		return root->left;
	}

	Node<T> * right_() const
	{
		return root->right;
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
		if (node)
		{
			try
			{
				if (value == node->x)
					throw 2;
				if (value < node->x)
					insert(node->left, value);
				else if (value > node->x)
					insert(node->right, value);
			}
			catch (int i)
			{
				cout << "This element is saved in the tree\n";
			}
		}
		else node = new Node<T>(value);
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
	
	bool check_search(const T& x)
	{
		Node<T> * node;
		node = search(x);
		if (node != nullptr)
			return true;
		else return false;
	}

	void fIn(const string filename)
	{
		ifstream fin;
		unsigned int k;
		fin.open(filename);
		try
		{
			if (!fin.is_open())
				throw 4;
			deleteNode(root);
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
		catch (int i)
		{
			cout << "The file isn't find" << endl;
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
		try
		{
			if (!fout.is_open())
				throw 4;
			unsigned int size_ = size(root);
			try
			{
				if (size_ == 0)
					throw 1;
				fout << size_ << "\t";
				fOut(root, fout);
				fout.close();
			}
			catch (int i)
			{
				cout << "The tree is empty\n";
			}
		}
		catch (int i)
		{
			cout << "The file isn't find" << endl;
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
	
	Node<T> * prev_(const T& x)
	{
		return prev_(root, x);
	}
	
	Node<T> * prev_(Node<T> * & node, const T& x)
	{
		Node<T> * cur = node;
		if (check_search(x))
		{
			if (x < cur->x)
			{
				if (x != cur->left->x)
					prev_(cur->left, x);
				else return cur;
			}
			else if (x > cur->x)
			{
				if (x != cur->right->x)
					prev_(cur->right, x);
				else return cur;
			}
			else return nullptr;
		}
		else return nullptr;
	}
	
	void deleteX(const T& x)
	{
		try
		{
			if (check_search(x) == false)
				throw 3;
			Node<T> * curEl = search(x);
			Node<T> * prev = prev_(x);
			if (curEl->left == nullptr && curEl->right == nullptr)
			{
				if (prev->left == curEl)
					prev->left = nullptr;
				if (prev->right == curEl)						
					prev->right = nullptr;
			}
			else if (curEl->left != nullptr&&curEl->right == nullptr)
			{
				if (curEl->x < prev->x)						
					prev->left = curEl->left;
				else prev->right = curEl->left;
			}
			else if (curEl->right != nullptr)
			{
				Node<T> * min = curEl->right;
				while (min->left)
					min = min->left;
				T a = min->x;					
				deleteX(min->x);
				curEl->x = a;
			}
		}
		catch (int i)
		{
			cout << "There isn't this element in the tree\n";
		}
	}
};
