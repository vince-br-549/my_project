//============================================================================
// Name        : AVLclass.cpp
// Author      : Vincent Herried
// Version     :
// Copyright   : Vincent Herried
// Description : invoke AVL tree class
//============================================================================

#include <iostream>
#include <ctime>
#include <climits>


#include "AVL.h"
using  std::cout;  using std::endl; using std::cin;
int main() {
	unsigned int dups{};
	int numberOfElements {};
	int	c,x;
	srand(time(NULL));	// seeding the random number generator
	// create the tree object
	AVL *myTree = new AVL;
	cout << "AVL binary search tree with class\n";
	do {
		cout<<"\n1 Display level order on newline";
		cout<<"\n2 Insert";
		cout<<"\n3 Delete one";
		cout<< "\n4 Delete all";
		cout<<"\n5 Search";
		cout<<"\n0 Exit\n";
		cout<<"\nChoice: ";

		cin >> c;

		switch (c)
		{
		case 1:
			myTree->levelorder_newline();
			cout << endl;
			break;
		case 2:
			cout << "\nEnter number. ";
			cin >> numberOfElements;
			for (int i = 0; i< numberOfElements; i++){
				int aNumber = rand() - (INT_MAX)/2;
				//aNumber %= numberOfElements;
				if ( ! myTree->insert(aNumber) ) dups++;
			}

			cout <<"\n" << dups << " duplicats, "
					<< myTree->getBalanceFactor() << " balance factor\n" ;
			break;
		case 3:
			cout << "\nWhat to delete? ";
			cin >>x;
			if ( myTree->deleteNode(x) ) cout << "Success\n";
			else cout << "Fail\n";
			break;
		case 4:
			cout << "\nNot yet implimented\n";
			break;
		case 5:
			cout << "\nsearch value? ";
			cin >> x;
			if ( ! myTree -> search(x) ) cout << "not ";
			cout << "found\n";
			break;
		case 0:
			cout << "\nBye\n";
            break;
		default:
			cout << "\nInvalid input\n";
		}
	} while (c!= 0);


	delete myTree;
	myTree = nullptr;
	cout << "All is well that ends well!" << endl; // prints !!!Hello World!!!
	return 0;
}







