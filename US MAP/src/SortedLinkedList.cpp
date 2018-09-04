#include "SortedLinkedList.h"
#include <iomanip>
#include <iostream>
#include <string>

SortedLinkedList::SortedLinkedList() //Default constructor
{
	head = NULL;
}

/**
 * Insert a new node into the sorted linked list.
 * Uses the overloaded Node::operator > to compare nodes.
 * @param node points to the node to insert.
 */

void SortedLinkedList::insert(Node *node)
{

	Node* prev;  //pointer to previous node
	Node* curr;  // pointer to current node

	if (head == nullptr) //If the list is empty
	{
		node->next = nullptr;
		head = node;
	}
	else
	{
		if (*head > *node) //Insert as the first node
		{
			node->next = head;
			head = node;
		}
		else //Insert after a node to keep order
		{
			curr = head;
			while (curr != nullptr && *node > *curr)
			{
				prev = curr;
				curr = curr->next;
			}

			prev->next = node;
			node->next = curr;
		}
	}
}

// Overloaded stream output insertion operator.
ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
	Node* prev = list.head;
	Node* curr;
	int nrow = 0;   // new row
	int display = 0; // display
	int cpos = 0;   // current position

	if (prev != nullptr)
	{
		if(prev->get_row() > 0)
		{
			int i=0;
			while(i < prev->get_row())
			{
				i++;
				outs << endl;
			}
		}
	}

	outs << setw(prev->get_col()) << *prev;

	if (prev->get_name() == "")
	{
		cpos = prev->get_col();
	}
	else
	{
		cpos = prev->get_col() + prev->get_name().length() +prev->get_state().length()+1;
	}
	curr = prev->next;

	while (curr != nullptr)
	{
		if ( curr->get_row() > prev->get_row() ) //To check every node if it can be displayed
		{
			nrow = 1;
			int i=0;
			while(i < (curr->get_row() - prev->get_row()))
			{
				i++;
				outs << endl;
			}
		}
		if (nrow == 0)
		{
			if ( curr->get_col() > cpos ) //To check if the current node position overlap
			{
				outs << setw(curr->get_col() - cpos) << *curr;
				display = 1;
			}

			if ( display == 1 ) //Update the current cursor position
			{
				if ( curr->get_name() == "" ) //Check if the node is a boundary
				{
					cpos = curr->get_col(); //current cursor position is after displaying #
					display = 0;
				}
				else //Check if the node is a city
				{
					//current cursor position is after displaying
					cpos= curr->get_col() + curr->get_name().length()+  curr->get_state().length() + 1;
					display = 0;
				}
			}
		}
		else
		{
			outs << setw(curr->get_col()) << *curr;

			if (curr->get_name() == "")
			{
				cpos = curr->get_col();
			}
			else
			{
				cpos = curr->get_col() + curr->get_name().length() +curr->get_state().length()+1;

			}
			nrow = 0;
		}

		prev = curr;
		curr = curr->next;
	}
	return outs;
}
