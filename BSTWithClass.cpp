#include <iostream>
//#include <queue>
//s#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include <climits>
//#include <chrono> // for timing

using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;
//using std::cerr;
//using std::max;
//using std::flush;

struct BstNode {
	int data;
	int hits;
	BstNode* left;
	BstNode* right;
};


class BST{
private:
	BstNode* head;
	int dups;
	bool displayDups = false;

	void delete_bin_tree(BstNode* root) {
		/*
		 * clean up the tree by deleting everything
		 * called by the class destructor
		 */
		if ( root == nullptr ) return;  // should only happen if main() called and the tree had never been populated.
		// traverse the tree deleting the nodes.
		if ( root->left != nullptr)
			delete_bin_tree(root->left);
		if ( root->right != nullptr)
			delete_bin_tree(root->right);
		// we should be at the bottom of the tree
		delete root;
		root = nullptr;
	}

	bool IsBSTUtil(BstNode* root,int minValue,int maxValue) {
		if ( root == nullptr) return true;
	//	cout << "IsBSTUtil ";
		// allows for duplicate values in the tree!  Nasty
	//	cout << "min value " << minValue << " data " << root->data << " maxValue " << maxValue << " ";
		if ( root->left) {
	//		cout << "left data: " << root->left->data << " ";
		}
	//	cout << "data " << root->data << " ";
		if ( root->right) {
	//		cout << "right data " << root->right->data << " ";
		}
	//	cout << endl;
		if (root->data > minValue && root->data < maxValue
			&& IsBSTUtil(root->left,minValue,root->data)
			&& IsBSTUtil(root->right,root->data,maxValue))
			return true;
		return false;
	}
	bool IsBSTFastCheck(BstNode* root) {
		/*
		 *
		 * second more efficient method of validating that the binary tree is a valid binary search tree.
		 *
		 */
		if (root == nullptr) return true;
		return IsBSTUtil(root,(INT_MIN),(INT_MAX));
	}
	// ------------ create a new  node
	BstNode* GetNewNode(int data) {
	//	cout << "Attempt to insert data: " << data << endl;
		BstNode* newNode = new BstNode();
		newNode->data = data;
		newNode->hits = 0;	// search hits
		newNode->left = newNode->right = nullptr;
		return newNode;
	}
	BstNode* doInsert(BstNode* root,int data) {
		if (root == nullptr) {
			return GetNewNode(data);
		}
		if( data < root->data) {
			root->left = doInsert(root->left, data);
					return root;
		}
		else if (data > root->data) {
			root->right = doInsert(root->right, data);
			return root;
		}
		dups++;		// a duplicate was not added
		return root;
	}

	void InorderPrint(BstNode* root) {
		if (root == nullptr) return;
		InorderPrint(root->left);
		cout << root->data << " ";
		InorderPrint(root->right);
	}

	bool FindIt(BstNode* root,int data) {
		// called by Find
		if ( root == nullptr) return false;
		else if ( root->data == data){
			root->hits++;
			return true;
		}
		else if (data <= root->data) return FindIt(root->left,data);
		else return (root->right,data);
		return false;		// inserted to remove compiler warning about not returning a value
	}

// called by Getmin()
	int FindMin(BstNode* root) {
		if ( root == nullptr) {
			cerr << "Error: Tree is empty!\n";
			return 0;
		}
		while ( root-> left != nullptr) root = root->left;
		return root->data;
	}

	// called by GetMax()
	int  FindMax(BstNode* root) {
		// use recursion for this one.
		if ( root == nullptr) {
			cerr << "Error: Tree is empty\n";
			return 0;
		}
		while ( root-> right != nullptr) root = root->right;
		return root->data;
	}

// called by GetHeight()
	int FindHeight(BstNode* root) {
		if ( root == nullptr) return -1;
		return max(FindHeight(root->left), FindHeight(root->right)) +1;
	}
public:
	BST(){ head = nullptr; }
	~BST(){
		// clean up the stack.
		delete_bin_tree(head);
//		cout << "The destructor has been called and "
//				"The tree has been removed from the stack!" << endl;
	};
	void Insert(int data) {
		// possibly insert the requested data.
		int ignored = dups;
		head = doInsert(head,data);
		if ( displayDups && (ignored != dups) )
		{
			cerr << "Insert of: " << data << " failed!" << endl;
			cerr << flush;
		}
	}
	void Print(){
		InorderPrint(head);
		cout << endl;
	}
	int GetDups() {
		// return the number of attempts to insert a duplicate record. The entry was not innserted.
		return dups;
	}
	bool Validate() {
		// check that it really is a valid BINARY search tree
		return IsBSTFastCheck(head);
	}
	bool Find(int data) { return FindIt(head,data); }
	int GetMin() { return FindMin(head); }
	int GetMAX()  {return FindMax(head);}
	int GetHeighT() { return  FindHeight(head); }
	void reportDups(bool maybe) {
		// should cause the insert function to  report back each duplicate attempt via some way.
		if (maybe) displayDups = true;
		else displayDups = false;
	}
};

int main(int argc, char **argv) {
	int count = 100, requestedCount;
	BST  myBST;		// Instantiate

	srand(time(NULL));	// seeding the random number generator

	cout << "Ready to create a binary tree with random data" << endl;
	cout << "Enter number of data points or zero to use default size:";
	cin  >> requestedCount;
	if ( requestedCount != 0 ) count = requestedCount;

	myBST.reportDups(true);

	cout << "Attempting to insert " << count << "  elements into tree." << endl;

	for (int i = 0; i<count; i++ ){
		int aNumber = rand() - (INT_MAX)/2;
//		aNumber %= count;
		myBST.Insert(aNumber);
	}

	if (myBST.Validate()) {
		cout << "My BST has been validated." << endl;
		if ( myBST.GetDups()) cout << "There were " << myBST.GetDups() << " Duplicates that were not inserted." << endl;
	}
	cout << "The smallest data value is: " << myBST.GetMin() << " , the largest is : " << myBST.GetMAX() << endl;
	cout << "The tree height is: " << myBST.GetHeighT() << endl;
	if ( count <= 100)
		myBST.Print();
	cout << "All is well that ends well!`:";
	return 0;
}
