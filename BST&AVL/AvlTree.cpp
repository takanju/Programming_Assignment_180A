/*
 * AvlTree.cpp
 *
 *  Created on: Nov 18, 2020
 *      Author: swapnanjali
 */


#include <iostream>
#include "AvlTree.h"

using namespace std;

int AvlTree::height(const BinaryNode *ptr) const
{
	if (ptr == NULL){
	   return -1 ;

	}
else
	{
	int left_ptr=height(ptr->left);
	int right_ptr=height(ptr->right);
   return max(left_ptr,right_ptr)+1;
	}

}

void AvlTree::insert(const int data, BinaryNode* &ptr)
{

    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}


//Reference from lecture's slide

BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
   if(ptr == nullptr)
   {
	   return ptr;
   }

   //left side too high
   if(height(ptr->left)- height(ptr->right) >1)
   {
	   if(height(ptr->left->left) >= height(ptr->left->right))
	   {
		   ptr = single_right_rotation(ptr);
		   cout <<"   --- Single right rotation at node "<<ptr->data<<endl;
	   }
	   else
	   {
		   ptr = double_left_right_rotation(ptr);
		   cout <<"   --- Double left-right rotation at node "<<ptr->data<<endl;
	   }
   }

	   else if(height(ptr->right) - height(ptr->left)>1)
	   {
		   if(height(ptr->right->right)>=height(ptr->right->left))
		   {
			   ptr = single_left_rotation(ptr);
			   cout <<"   --- Single left rotation at node "<<ptr->data<<endl;
		   }
		   else
		   {
			   ptr = double_right_left_rotation(ptr);
			   cout <<"   --- Double right-left rotation at node "<<ptr->data<<endl;
		   }
	   }



    // Recompute the node's height.
    ptr->height = max(height(ptr->left), height(ptr->right))+1;

    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}


//Reference : https://users.cs.fiu.edu/~weiss/dsaa_c++/code/AvlTree.cpp

BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{
	BinaryNode *k1 = k2;
	k1= k2->left;
		k2->left = k1->right;
		k1->right = k2;
	k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
	 k1->height = max( height( k1->left ), k2->height ) + 1;
	 k2 = k1;
		return k2;

}


//Reference : https://users.cs.fiu.edu/~weiss/dsaa_c++/code/AvlTree.cpp
BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{
	k3->left =  single_left_rotation( k3->left );
	return single_right_rotation( k3 );

}


//Reference : https://users.cs.fiu.edu/~weiss/dsaa_c++/code/AvlTree.cpp
BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
	k1->right =  single_right_rotation( k1->right );
return single_left_rotation( k1 );
}


//Reference : https://users.cs.fiu.edu/~weiss/dsaa_c++/code/AvlTree.cpp
BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{
	BinaryNode *k2 = k1->right;
		 k1->right = k2->left;
		 k2->left = k1;
		 k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
		 k2->height = max( height( k2->left ), k1->height ) + 1;
		 k1 = k2;
		return k2;

}

int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}

