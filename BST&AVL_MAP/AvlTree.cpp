#include <iostream>
#include "AvlTree.h"

using namespace std;

int AvlTree::height(const BinaryNode *ptr)
{
    this->probe_count++;
    return ptr == nullptr ? -1 : ptr->height;
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

BinaryNode *AvlTree::rebalance(BinaryNode *&ptr)
{
    if (ptr == nullptr) return ptr;

    // Left side too high.
    if (height(ptr->left) - height(ptr->right) > 1)
    {
        this->probe_count += 6;

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
        this->probe_count += 6;

        if (height(ptr->right->right) >= height(ptr->right->left))
        {
            ptr = single_left_rotation(ptr);
        }
        else
        {
            ptr = double_right_left_rotation(ptr);
        }
    }
    else
    {
        this->probe_count += 4;
    }

    // Recompute the node's height.
    ptr->height = (max(height(ptr->left),
                       height(ptr->right)) + 1);
    this->probe_count += 2;

    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{
    BinaryNode *k1 = k2->left;

    // Rotate.
    k2->left = k1->right;
    k1->right = k2;

    // Recompute node heights.
    k2->height = (max(height(k2->left), height(k2->right)) + 1);
    k1->height = (max(height(k1->left), k2->height) + 1);

    this->probe_count += 9;
    return k1;
}

BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{
    k3->left = single_left_rotation(k3->left);
    this->probe_count += 2;
    return single_right_rotation(k3);
}

BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
    k1->right = single_right_rotation(k1->right);
    this->probe_count += 2;
    return single_left_rotation(k1);
}

BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{
    BinaryNode *k2 = k1->right;

    // Rotate.
    k1->right = k2->left;
    k2->left  = k1;

    // Recompute node heights.
    k1->height = (max(height(k1->left), height(k1->right)) + 1);
    k2->height = (max(height(k2->right), k1->height) + 1);

    this->probe_count += 9;
    return k2;
}

int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    this->probe_count += 6;

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
