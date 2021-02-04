#include <string>
#include "BinarySearchTree.h"

using namespace std;

int BinarySearchTree::height(const BinaryNode *ptr) const
{
	if(ptr == nullptr){
		return -1;
	}
	else
	{
	int left_ptr=height(ptr->left);
	int right_ptr=height(ptr->right);
   return max(left_ptr,right_ptr)+1;
	}

}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
    if(ptr == nullptr){
    	return nullptr;
    }
    if(ptr->left == nullptr){
    	return ptr;
    }
    return find_min(ptr->left);
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
   if(ptr == nullptr){
	   return nullptr;
   }
   while(ptr->right != nullptr){
	   ptr = ptr->right;
   }
   return ptr;

}

//Reference from lecture's slide
bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{
    if(ptr == nullptr){
    	return false;
    }
    else if(data == ptr->data){
    	return true;

    }
    else if(data < ptr->data){
    	return contains(data, ptr->left);
    }
    else
    {
    	return contains(data, ptr->right);
    }

}

//Reference from lecture's slide
void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{

	if(ptr==nullptr)
	{
		ptr = new BinaryNode(data);
	}
		else if (data < ptr->data)
		{
			insert(data, ptr->left);
		}
		else if(data > ptr->data)
		{
			insert(data, ptr->right);
		}
	else
		; //update the node

}

//Reference from lecture's slide
void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
    if(ptr == nullptr)
    {
    	return;    //target node not found:do nothing
    }

    if(data < ptr->data)
    {
    	remove(data, ptr->left);
    }
    else if(data > ptr->data)
    {
    	remove(data, ptr->right);
    }

    else if (  (ptr->left != nullptr)
    && (ptr->right != nullptr))
     {
    //find min value right side
    ptr->data = find_min(ptr->right)->data;
    remove(ptr->data, ptr->right);

     }
   else
    {
    	BinaryNode *oldNode = ptr;
    	ptr = (ptr->left != nullptr) ? ptr->left: ptr->right;
    	delete oldNode;
    }



}
