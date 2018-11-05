#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template <class T>

class BinarySearchTree
{
public:
	BinarySearchTree(){}
	~BinarySearchTree() {makeEmpty();}

	const T findMin() {Node* temp = findMin(m_root); return temp->m_data;}
	const T findMax() {Node* temp = findMax(m_root); return temp->m_data;}
	bool contains(const T data) {return contains(data, m_root);}
	bool isEmpty() {return !m_root;}
	void inorderTraverse() {inorderTraverse(m_root);}
	void preorderTraverse() {preorderTraverse(m_root);}
	void postorderTreverse() {postorderTraverse(m_root);}

	void makeEmpty() {makeEmpty(m_root);}
	void insert(T data) {insert(data, m_root);}
	void remove(T data) {remove(data, m_root);}

private:

	// a node struct containing the data for a node
	// it's templated to contain any sort of data
	// and a struct is used as it contains no functions aisde from the constructor
	struct Node
	{
		T m_data;
		Node* m_leftSub;
		Node* m_rightSub;

		Node (T data, Node* leftSub, Node* rightSub)
			: m_data(data), m_leftSub(leftSub), m_rightSub(rightSub){}
	};

	Node* m_root = nullptr;


	// returns the lowest value of a tree
	// by looking at all the leftSubs until it finds the last one and returns it
	Node* findMin(Node* root){
		if(root)
			while(root->m_leftSub)
				root = root->m_leftSub;
		return root;
	}


	// returns the highest value of a tree
	// by looking at all the rightSubs until it finds the last one and returns it
	Node* findMax(Node* root){
		if(!root)
			return nullptr;
		if(!root->m_rightSub)
			return root;
		return findMin(root->m_rightSub);
	}

	// checks if a tree conitains a certain data
	bool contains(const T data, Node* root){
		// if we are at the end of a subtree, the node is a nullptr
		// the data does not exist in the tree
		// this is the most likely scenario so we check for that first
		if(!root)
			return false;
		// if the data searched for is smaller than the current node
		// continue searching through the left subtree
		else if (data < root->m_data)
			return contains(data, root->m_leftSub);
		// if the data is larger search through the right subtree
		else if (data > root->m_data)
			return contains(data, root->m_rightSub);
		// if the node exist and its data is not smaller or larger
		// than the data we're searching for
		// it must be equal, and we return true
		else
			return true;
	}



	// traverses through the nodes on the tree from left to right
	// prints after going to the leftSub and before gaoing to the rightSub
	// this will result in getting the data in ascending order
	void inorderTraverse(Node* root) {
		if(root){
			if(root->m_leftSub)
				inorderTraverse(root->m_leftSub);

			std::cout << root->m_data << " ";

			if(root->m_rightSub)
				inorderTraverse(root->m_rightSub);
		}
	}


	void preorderTraverse(Node* root) {
		if(root){

			std::cout << root->m_data << " ";

			if(root->m_leftSub)
				preorderTraverse(root->m_leftSub);
			if(root->m_rightSub)
				preorderTraverse(root->m_rightSub);
		}
	}


	void postorderTraverse(Node* root) {
		if(root){
			if(root->m_leftSub)
				postorderTraverse(root->m_leftSub);
			if(root->m_rightSub)
				postorderTraverse(root->m_rightSub);

			std::cout << root->m_data << " ";

		}
	}


	// traverses through all nodes
	// deletes a node when it gets to a leaf
	void makeEmpty(Node* root) {

		m_root = nullptr;

		if(root) {
			makeEmpty(root->m_leftSub);
			makeEmpty(root->m_rightSub);
			delete root;
		}
	}


	// inserts new node into the tree
	void insert(T data, Node* root) {

		// if there is no previous root, this is now the root of the new subtree
		if(!root) {
			root = new Node(data, nullptr, nullptr);
		}
		// traverses to the left if the data is smaller than the current node
		// and to the right if the data is larger
		// inserts a new node if it reaches a node with no subNode in that direction
		else if(data < root->m_data) {
			if (root->m_leftSub)
				insert(data, root->m_leftSub);
			else
				root->m_leftSub = new Node(data,  nullptr, nullptr);
		}
		else if(data > root->m_data) {
			if (root->m_rightSub)
				insert(data, root->m_rightSub);
			else
				root->m_rightSub = new Node(data,  nullptr, nullptr);
		}
		// if there is no root in the whole tree
		// the new node is the root
		if(!m_root)
			m_root = root;
	}


	// finds the data searched for and deletes that node
	// returns the new root to replace the node removed
	Node* remove(T data, Node* root) {
		// node is a nullptr and can't be deleted
		if(!root)
			return nullptr;

		// first we need to find the node we want to remove
		// by traversing through the tree to find the right node
		// when a node is actually deleted, we need to make sure
		// its parent replaces it with the proper new subNode
		// this is why we set that subNode to be what this function returns
		if(data < root->m_data)
			root->m_leftSub = remove(data, root->m_leftSub);
		else if(data > root->m_data)
			root->m_rightSub = remove(data, root->m_rightSub);


		// if the node exists, and the data is not more or less than
		// the data being searched for, we have found the node to remove
		// we then need to prepare for a few different cases

		else{
			// if the node has either no children or one child
			// if the node has no leftSub we can return the rightSub
			// so it can be the new rightSub of the parent of the node we are removing
			// this also works if there are no children, because then it will return a nullptr
			// we have to set the node as a temp in order to return it after deletion
			if(!root->m_leftSub){
				Node* tempNode = root->m_rightSub;
				delete root;
				return tempNode;
			}
			else if(!root->m_rightSub){
				Node* tempNode = root->m_leftSub;
				delete root;
				return tempNode;
			}

			// if the node has two children
			// instead of deleting the node, which would mean a lot of reconnecting children
			// we first find the lowest value of the rightSub
			// we move the data from that sub to the node we're removing
			// we know that that node will have no leftSubs, so we just need to fix the rightSub
			// we now remove the node we just copied, which is somewhere on the rightSubTree
			// and repreat this proccess to get the new rightSub
			Node* tempNode = findMin(root->m_rightSub);

			root->m_data = tempNode->m_data;

			root->m_rightSub = remove(tempNode->m_data, root->m_rightSub);

		}

		// if the data is not found, it cannot be deleted
		// so the node just returns itself and nothing changes
		return root;
	}
};



#endif // BINARYSEARCHTREE_H
