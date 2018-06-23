
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BinarySearchTree.h"

class AvlTree : public BinarySearchTree
{
public:
	AvlTree();
	virtual ~AvlTree();

protected:
	virtual int height(const BinaryNode *ptr) const;
	virtual void insert(const int data, BinaryNode* &ptr);

private:
	BinaryNode *rebalance(BinaryNode* &ptr);
	BinaryNode *single_right_rotation(BinaryNode *k2);
	BinaryNode *double_left_right_rotation(BinaryNode *k3);
	BinaryNode *double_right_left_rotation(BinaryNode *k1);
	BinaryNode *single_left_rotation(BinaryNode *k1);
	int checkBalance(BinaryNode *ptr);
};

#endif // AVL_TREE_H
