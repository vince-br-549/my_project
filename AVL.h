/*
 * AVL.h
 *
 *  Created on: Sep 19, 2022
 *      Author: vince
 */

#ifndef AVL_H_
#define AVL_H_
struct Node {
    int data;
    int height;
    int hits;
    Node *left;
    Node *right;
};
class AVL {
private:
	Node	*head;
	int dups;
    int 	getHeight(Node *p);
    int 	getBalanceFactor(Node *n);
    void 	delete_bin_tree(Node *root);
    Node *rotateAsNeeded(Node* root);
    Node	*deleteNode(Node *root,int data);
    Node	*getMinimum(Node *root);
    Node	*getMaximum(Node *root);
    void 	levelorder_newline(Node *v);
    Node 	*llrotation(Node *n);
    Node 	*rrrotation(Node *n);
    Node 	*rlrotation(Node *n);
    Node 	*lrrotation(Node *n);
    Node	*inpre(Node* p);
    Node	*insuc(Node* p);
    int 	search(Node *root,int data);
    Node	*insert(Node *r,int data);


public:


	AVL();
	virtual ~AVL();
	int 	getHeight();
	int		getBalanceFactor();
	int		getMinumum();			// not implemented YET
    int		getMaximum();			// not implemented YET
    bool	search(int data);
    bool	insert(int data);
    void 	levelorder_newline();
    bool 	deleteNode(int data);

};


#endif /* AVL_H_ */
