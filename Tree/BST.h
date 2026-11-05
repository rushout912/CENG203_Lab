#pragma once
#include "TreeNode.h"

// Binary Search Tree: left subtree < node < right subtree, at every node.
// The class owns the root; the work is done by private recursive helpers.
class BST
{
private:
    TreeNode* root;                 // nullptr = empty tree

    static TreeNode* insertInto(TreeNode* node, int value, bool& inserted);
    static TreeNode* removeFrom(TreeNode* node, int value, bool& removed);

public:
    BST();
    ~BST();

    bool insert(int value);         // false = duplicate, tree unchanged
    bool find(int value) const;     // O(height)
    bool findMin(int& value) const; // leftmost node; false = empty
    bool findMax(int& value) const; // rightmost node
    bool remove(int value);         // false = not found

    void preorder() const;          // TreeUtils applied to root
    void inorder() const;           // ascending order!
    void postorder() const;
    int  height() const;
    bool isBalanced() const;
    bool isEmpty() const;
};
