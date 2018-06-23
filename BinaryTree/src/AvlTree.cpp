#include <iostream>
#include "AvlTree.h"

using namespace std;

/**
 * Default constructor.
 */
AvlTree::AvlTree() : BinarySearchTree()
{
}

/**
 * Destructor.
 */
AvlTree::~AvlTree()
{
}

/**
 * Private method to compute the height of a subtree.
 * Overrides the base class method.

 */
int AvlTree::height(const BinaryNode *ptr) const
{
	return ptr == nullptr ? -1 : ptr->height;
}

/**
 * Private method to insert a data item into a subtree
 * and set the new root of the subtree.
 */
void AvlTree::insert(const int data, BinaryNode* &ptr)
{
	BinarySearchTree::insert(data, ptr);
	rebalance(ptr);
}

/**
 * Private method to balance the tree.
 * @param ptr pointer to the node to balance.
 */
BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
	probe_count++;
	if (ptr == nullptr)
		{
		return ptr;
		}

	probe_count += 2;
	// Left side too high.
	if (height(ptr->left) - height(ptr->right) > 1)
	{
		probe_count += 2;
		if (height(ptr->left->left) >= height(ptr->left->right))
		{
			ptr = single_right_rotation(ptr);
		}
		else
		{
			ptr = double_left_right_rotation(ptr);
		}
	}

	// Right side too high.
	else if (height(ptr->right) - height(ptr->left) > 1)
	{
		probe_count += 2;
		if (height(ptr->right->right) >= height(ptr->right->left))
		{
			ptr = single_left_rotation(ptr);
		}
		else
		{
			ptr = double_right_left_rotation(ptr);
		}
	}

	probe_count += 2;
	// Recompute the node's height.
	ptr->height = (max(height(ptr->left),
			height(ptr->right)) + 1);

	return ptr;
}

/**
 * Case 1 (outside left-left): Rebalance with a single right rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{
	//Node k2 is unbalanced.

	probe_count++;
	//k2's left child becomes the new root of the subtree.
	BinaryNode *new_root = k2->left;

	probe_count++;
	//k2 adopts the new root's right child as its new left child.
	k2->left = new_root->right;

	probe_count++;
	//k2 becomes the right child of the new root
	new_root->right = k2;

	probe_count += 2;
	//Recompute the old root node k2's height.
	k2->height = (max(height(k2->left), height(k2->right)) + 1);

	return new_root;
}


BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{
	//Node k3 is unbalanced.
	//The new root of the subtree is got after two rotations.

	probe_count ++;
	//Step 1 is a single left rotation of k3's left child
	k3->left = single_left_rotation(k3->left);

	//Step 2 is a single right rotation of k3
	return single_right_rotation(k3);
}

BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
	//Node k1 is unbalanced.
	//The new root of the subtree is got after two rotations.

	probe_count ++;
	//Step 1 is a single right rotation of k1's right child
	k1->right = single_right_rotation(k1->right);

	//Step 2 is a single left rotation of k1
	return single_left_rotation(k1);
}

BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{
	//Node k1 is unbalanced.

	probe_count++;
	//k1's right child becomes the new root of the subtree.
	BinaryNode *new_root = k1->right;

	probe_count++;
	//k1 adopts C's left child as its new right child
	k1->right = new_root->left;

	probe_count++;
	//Node k1 becomes the left child of the new root
	new_root->left = k1;

	probe_count += 2;
	//Recompute the old root node k1's height.
	k1->height = (max(height(k1->left), height(k1->right)) + 1);

	return new_root;
}
