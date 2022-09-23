#include <iostream>
#include <cstdlib>

template<typename T>
struct Node {
	T key;
	int priority, size;
	Node<T> *left, *right;

	Node(const T& _key) : key(_key), priority(rand()),
	size(1), left(nullptr), right(nullptr)
	{}
	
	void setLeft(Node<T>* newLeft)
	{
		left = newLeft;
		calcSize();
	}
	void setRight(Node<T>* newRight)
	{
		right = newRight;
		calcSize();
	}
	void calcSize() {
		size = 1;
		if(left != nullptr) size += left->size;
		if(right != nullptr) size += right->size;
	}
};

template<typename T>
class Treap
{
	typedef std::pair<Node<T>*, Node<T>*> NodePair;
private:
	Node<T>* root;	
	
	Node<T>* insert(Node<T>* root, Node<T>* node)
	{
		if(root == nullptr) 
		{
			root = node;
		}
		else if(root->priority < node->priority)
		{
			NodePair splitted = split(root, node->key);
			
			node->setLeft(splitted.first);
			node->setRight(splitted.second);
			root = node;
		}
		else if(node->key < root->key)
		{
			root->setLeft(insert(root->left, node));
		}
		else
		{
			root->setRight(insert(root->right, node));
		}
	}
	
	Node<T>* merge(Node<T>* a, Node<T>* b)
	{
		if(a == nullptr) return b;
		if(b == nullptr) return a;
		if(a->priority < b->priority)
		{
			b->setLeft(merge(a, b->left));
			return b;
		}
		else
		{
			a->setRight(merge(a->right, b));
			return a;
		}
	}
	
	Node<T>* erase(Node<T>* root, T key)
	{
		if(root == nullptr) return root;
		
		if(root->key == key)
		{
			Node<T> *ret = merge(root->left, root->right);
			
			delete root;
			return ret;
		}
		if(key < root->key)
			root->setLeft(erase(root->left, key));
		else
			root->setRight(erase(root->right, key));
		
		return root;
	}
	NodePair split(Node<T>* root, T key) 
	{
		if(root == nullptr) return NodePair(nullptr, nullptr);
		
		if(root->key < key)
		{
			NodePair rightSubtree = split(root->right, key);
			root->setRight(rightSubtree.first);
			return NodePair(root, rightSubtree.second);
		}
		else
		{
			NodePair leftSubtree = split(root->left, key);
			root->setLeft(leftSubtree.second);
			return NodePair(leftSubtree.first, root);
		}
	}
	
	Node<T>* kthElement(Node<T> *root, int k)
	{
		int leftSize = 0;
		if(root->left != nullptr)
			leftSize = root->left->size;
		if(k <= leftSize)
			return kthElement(root->left, k);
		if(k == leftSize+1) return root;
		return kthElement(root->right, k-leftSize-1);
	}
	
	int countLessThan(Node<T>* root, T key)
	{
		if(root == nullptr) return 0;
		if(root->key >= key)
			return countLessThan(root->left, key);
		int ls = (root->left ? root->left->size : 0);
		return ls + 1 + countLessThan(root->right, key);
	}
	
	void inorder(Node<T>* root)
	{
		if(root!=nullptr)
		{
			inorder(root->left);
			std::cout << root->key << ' ';
			inorder(root->right);
		}
		return;
	}
public:
	Treap() : root(nullptr)
	{}
	
	void insert(T key)
	{
		Node<T> *node = new Node<T>(key);
		if(root == nullptr)
			root = node;
		else
			insert(root, node);
	}
	
	void erase(T key)
	{
		this->root = erase(this->root, key);
	}
	
	T kthElement(int k)
	{
		return kthElement(root, k)->key;
	}
	int countLessThan(T key)
	{
		return countLessThan(root, key);
	}
	
	void inorder()
	{
		if(root!=nullptr)
		{
			inorder(root->left);
			std::cout << root->key << ' ';
			inorder(root->right);
		}
		return;
	}
};

int main()
{
	Treap<int> root;
	for(int i = 1; i <= 10; ++i)
		root.insert(i);
	
	// std::cout << root.kthElement(3);
	root.inorder();
	std::cout << '\n';
	root.erase(1);
	root.erase(6);
	root.erase(5);
	root.erase(8);
	root.inorder();
	std::cout << '\n';
	
	return 0;
}