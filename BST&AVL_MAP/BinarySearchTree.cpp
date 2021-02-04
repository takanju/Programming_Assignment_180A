#include <string>
#include "BinarySearchTree.h"

using namespace std;

int BinarySearchTree::height(const BinaryNode *ptr)
{
    if (ptr != nullptr)
    {
        probe_count += 2;
        return 1 + max(height(ptr->left), height(ptr->right));
    }
    else
    {
        return -1;
    }
}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr)
{
    if (ptr != nullptr)
    {
        while(ptr->left != nullptr)
        {
            probe_count += 2;
            ptr = ptr->left;
        }
    }

    return ptr;
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr)
{
    if (ptr != nullptr)
    {
        while(ptr->right != nullptr)
        {
            probe_count += 2;
            ptr = ptr->right;
        }
    }

    return ptr;
}

bool BinarySearchTree::contains(const int data, BinaryNode *ptr)
{
    while (ptr != nullptr)
    {
        if (data < ptr->data)
        {
            probe_count += 2;
            compare_count++;

            ptr = ptr->left;
        }
        else if (data > ptr->data)
        {
            probe_count += 3;
            compare_count += 2;

            ptr = ptr->right;
        }
        else
        {
            probe_count += 2;
            compare_count += 2;

            return true;  // found
        }
    }

    return false;         // not found
}

void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    if (ptr == nullptr)
    {
        ptr = new BinaryNode(data);
    }
    else if (data < ptr->data)
    {
        probe_count += 2;
        compare_count++;

        insert(data, ptr->left);
    }
    else if (data > ptr->data)
    {
        probe_count += 3;
        compare_count += 2;

        insert(data, ptr->right);
    }
    else
    {
        probe_count += 2;
        compare_count += 2;
    }
}

void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
    if (ptr == nullptr) return;   // not found, so do nothing

    // First search for the target node to remove.
    if (data < ptr->data)
    {
        probe_count += 2;
        compare_count++;

        remove(data, ptr->left);
    }
    else if (data > ptr->data)
    {
        probe_count += 3;
        compare_count += 2;

        remove(data, ptr->right);
    }

    // Remove a target node with two children.
    else if (   (ptr->left  != nullptr)
             && (ptr->right != nullptr))
    {
        probe_count += 8;
        compare_count += 2;

        // Replace the target node's data with the successor node's data.
        ptr->data = find_min(ptr->right)->data;

        // Search for and remove the successor node.
        remove(ptr->data, ptr->right);
    }

    // Remove a target node with one or no children.
    else
    {
        probe_count += 7;
        compare_count += 2;

        BinaryNode *oldNode = ptr;
        ptr = (ptr->left != nullptr) ? ptr->left
                                     : ptr->right;
        delete oldNode;
    }
}
