/*
 * AVL.cpp
 *
 *  Created on: Sep 19, 2022
 *      Author: vince
 *      completely hide the base of the tree from the user.
 *
 */
#include <iostream>
#include <queue>
#include <unordered_map>
using std::cout; using std::endl;  using std::flush; using std::cerr;

#include "AVL.h"

AVL::AVL() {
	head=nullptr;
	dups = 0;
}

// public
bool	AVL::deleteNode(int mydata) {
	if ( search(head,mydata) ) {
		//
		// make sure the Node exists before calling
		//
		head = deleteNode(head, mydata);
		return true;
	}
	return false;
}

// private ????????????????????????/  what happens if the data is not found???????????????
Node *AVL::deleteNode(Node *p,int data){
    if(p->left == nullptr && p->right == nullptr){
            if(p==this->head)
                this->head = nullptr;
        delete p;
        return nullptr;
    }
    //Node *t;		// from the original??? never used.
    Node *q;
    if(p->data < data){
        p->right = deleteNode(p->right,data);
    }
    else if(p->data > data){
        p->left = deleteNode(p->left,data);
    }
    else{
        if(p->left != nullptr){
            q = inpre(p->left);
            p->data = q->data;
            p->left=deleteNode(p->left,q->data);
        }
        else{
            q = insuc(p->right);
            p->data = q->data;
            p->right = deleteNode(p->right,q->data);
        }
    }
    return rotateAsNeeded(p);
//    if(getBalanceFactor(p)==2 && getBalanceFactor(p->left)==1){ p = llrotation(p); }
//    else if(getBalanceFactor(p)==2 && getBalanceFactor(p->left)==-1){ p = lrrotation(p); }
//    else if(getBalanceFactor(p)==2 && getBalanceFactor(p->left)==0){ p = llrotation(p); }
//    else if(getBalanceFactor(p)==-2 && getBalanceFactor(p->right)==-1){ p = rrrotation(p); }
//    else if(getBalanceFactor(p)==-2 && getBalanceFactor(p->right)==1){ p = rlrotation(p); }
//    else if(getBalanceFactor(p)==-2 && getBalanceFactor(p->right)==0){ p = llrotation(p); }
//    return p;
}

// private called by the class destructor.
void AVL::delete_bin_tree(Node *root) {
	/*
	 * clean up the tree by deleting everything
	 *
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

// public
int		AVL::getBalanceFactor() {
	return getBalanceFactor(head);
}
//
//    The balance factor is known as the difference between the height of the left subtree and the right subtree.
//    Balance factor(Node) = height(Node->left) – height(Node->right)
//    Allowed values of BF are –1, 0, and +1.
//    The value –1 indicates that the right sub-tree contains one extra, i.e., the tree is right heavy.
//    The value +1 indicates that the left sub-tree contains one extra, i.e., the tree is left heavy.
//    The value 0 shows that the tree includes equal nodes on each side, i.e., the tree is perfectly balanced.
//
// private
int AVL::getBalanceFactor(Node *n){
        if(n->left && n->right){
            return n->left->height - n->right->height;
        }
        else if(n->left && n->right == nullptr){
            return n->left->height;
        }
        else if(n->left == nullptr && n->right ){
            return -n->right->height;
        }
	return 0;  // hopefuuly will never execute but fixes compile warning.
}

//public
int	AVL::getHeight() { return getHeight(head);}

// private
int AVL::getHeight(Node *p){
        if(p->left && p->right){
        if (p->left->height < p->right->height)
            return p->right->height + 1;
        else return  p->left->height + 1;
        }
        else if(p->left && p->right == nullptr){
           return p->left->height + 1;
        }
        else if(p->left ==nullptr && p->right){
           return p->right->height + 1;
        }
        return 0;
}

// public
int	AVL::getMinumum() {
	Node *temp = getMinimum(head);
	if ( temp ) return temp->data;
	else return 0;
}

// private
Node	*AVL::getMinimum(Node *root) {
		if ( root == nullptr) {
			cerr << "Error: Tree is empty!\n";
			return nullptr;
		}
		while ( root-> left != nullptr) root = root->left;
		return root;
}

// public
int	AVL::getMaximum() {
	Node *temp = getMaximum(head);
	if ( temp ) return temp->data;
	else return 0;
}

//private
Node	*AVL::getMaximum(Node* root) {
	// use recursion for this one.
	if ( root == nullptr) {
		cerr << "Error: Tree is empty\n";
		return nullptr;
	}
	else if ( root->right == nullptr) return root;
	return getMaximum(root->right);
}

// private
Node *AVL::llrotation(Node *n){
    Node *p;
    Node *tp;
    p = n;
    tp = p->left;

    p->left = tp->right;
    tp->right = p;
    return tp;
}

// private
Node *AVL::rrrotation(Node *n){
    Node *p;
    Node *tp;
    p = n;
    tp = p->right;
    p->right = tp->left;
    tp->left = p;
    return tp;
}

// private
Node *AVL::rlrotation(Node *n){
    Node *p;
    Node *tp;
    Node *tp2;
    p = n;
    tp = p->right;
    tp2 =p->right->left;
    p -> right = tp2->left;
    tp ->left = tp2->right;
    tp2 ->left = p;
    tp2->right = tp;
    return tp2;
}

// private
inline Node *AVL::rotateAsNeeded(Node* p) {
	Node *root = p;
    if(getBalanceFactor(root)==2 && getBalanceFactor(root->left)==1){
        root = llrotation(root);
    }
    else if(getBalanceFactor(root)==-2 && getBalanceFactor(root->right)==-1){
        root = rrrotation(root);
    }
    else if(getBalanceFactor(root)==-2 && getBalanceFactor(root->right)==1){
        root = rlrotation(root);
    }
    else if(getBalanceFactor(root)==2 && getBalanceFactor(root->left)==-1){
        root = lrrotation(root);
    } else if (getBalanceFactor(root)==2 && getBalanceFactor(root->left)==0){
    	root = llrotation(root);  // added
 	} else if (getBalanceFactor(root)==-2 && getBalanceFactor(root->left)==0){
    	root = llrotation(root);  // added
 	 }
    return root;
}
Node *AVL::lrrotation(Node *n){
    Node *p;
    Node *tp;
    Node *tp2;
    p = n;
    tp = p->left;
    tp2 =p->left->right;
    p -> left = tp2->right;
    tp ->right = tp2->left;
    tp2 ->right = p;
    tp2->left = tp;
    return tp2;
}

// public
bool AVL::search(int findData) {
	return search(head,findData);
}

// private
int AVL::search(Node *root,int data) {
	if ( root == nullptr) return false;
	else if ( root->data == data){
		root->hits++;
		return true;;
	}
	else if (data <= root->data) return search(root->left,data);
	else return search(root->right,data);
	return false;		// inserted to remove IDE warning about not returning a value
}

// public
bool	AVL::insert(int newData) {
	head = insert(head,newData);
	if ( dups ) return false;
	return true;
}


 Node* AVL::insert(Node *root,int data){
    if(root==NULL){
        Node *n;
        n = new Node;
        n->data = data;
        root = n;
        root->left = root->right = NULL;
        root->height = 1;
        return root;
    }
    else{
        if(data < root->data) {
        root->left = insert(root->left,data);
        } else
        root->right = insert(root->right,data);
    }

    root->height = getHeight(root);
    return rotateAsNeeded(root);
//    if(getBalanceFactor(root)==2 && getBalanceFactor(root->left)==1){
//        root = llrotation(root);
//    }
//    else if(getBalanceFactor(root)==-2 && getBalanceFactor(root->right)==-1){
//        root = rrrotation(root);
//    }
//    else if(getBalanceFactor(root)==-2 && getBalanceFactor(root->right)==1){
//        root = rlrotation(root);
//    }
//    else if(getBalanceFactor(root)==2 && getBalanceFactor(root->left)==-1){
//        root = lrrotation(root);
//    } else if (getBalanceFactor(root)==2 && getBalanceFactor(root->left)==0){
//    	root = llrotation(root);  // added
// 	} else if (getBalanceFactor(root)==-2 && getBalanceFactor(root->left)==0){
//    	root = llrotation(root);  // added
// 	 }
//    return root;
}

// public
void AVL::levelorder_newline(){
    if (this->head == nullptr){
        cout<<"\n"<<"Empty tree"<<"\n";
        return;
    }
    levelorder_newline(this->head);
}

// private
void AVL::levelorder_newline(Node *v){
    std::queue <Node *> q;
    Node *cur;
    q.push(v);
    q.push(nullptr);

    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur == nullptr && q.size()!=0){
            cout<<"\n";
            q.push(nullptr);
            continue;
        }
        if(cur!=nullptr){
            cout<<" "<<cur->data;
            if (cur->left!=nullptr){
            q.push(cur->left);
            }
            if (cur->right!=nullptr){
                q.push(cur->right);
            }
        }
    }
}


// private
 Node *AVL::inpre(Node* p){
    while(p->right!=nullptr)
        p = p->right;
    return p;
}

// private
Node *AVL::insuc(Node* p){
    while(p->left!=nullptr)
        p = p->left;

    return p;
}

// public destructor
AVL::~AVL() {
	cout << "Destructor called " << endl << flush;
	delete_bin_tree(head);
}

