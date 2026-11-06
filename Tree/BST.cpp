#include "BST.h"
#include "TreeUtils.h"
#include <iostream>
using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    destroy(root);                  // postorder delete of every node
}

// ============================ Q4 ============================
bool BST::insert(int value)
{
    bool inserted = false;
    root = insertInto(root, value, inserted);
    return inserted;
}

TreeNode* BST::insertInto(TreeNode* node, int value, bool& inserted)
{
    if (node == nullptr) {          // found the empty spot
        inserted = true;
        return makeNode(value);
    }
    if (value < node->data)
        node->left = insertInto(node->left, value, inserted);
    else if (value > node->data)
        node->right = insertInto(node->right, value, inserted);
    // equal: duplicate, nothing happens
    return node;
}

// ============================ Q5 ============================
bool BST::find(int value) const
{
    const TreeNode* cur = root;
    while (cur != nullptr) {
        if (value == cur->data)
            return true;
        if (value < cur->data)      // only ONE subtree can contain it
            cur = cur->left;
        else
            cur = cur->right;
    }
    return false;
}

bool BST::findMin(int& value) const
{
    if (root == nullptr)
        return false;
    const TreeNode* cur = root;
    while (cur->left != nullptr)    // keep going left
        cur = cur->left;
    value = cur->data;
    return true;
}

bool BST::findMax(int& value) const
{
    if (root == nullptr)
        return false;
    const TreeNode* cur = root;
    while (cur->right != nullptr)   // keep going right
        cur = cur->right;
    value = cur->data;
    return true;
}

// ============================ Q7 ============================
bool BST::remove(int value)
{
    bool removed = false;
    root = removeFrom(root, value, removed);
    return removed;
}

TreeNode* BST::removeFrom(TreeNode* node, int value, bool& removed)
{
    if (node == nullptr)
        return nullptr;             // not found
    if (value < node->data) {
        node->left = removeFrom(node->left, value, removed);
        return node;
    }
    if (value > node->data) {
        node->right = removeFrom(node->right, value, removed);
        return node;
    }
    // this is the node to remove
    removed = true;
    if (node->left == nullptr || node->right == nullptr) {
        // case 1 (leaf) and case 2 (one child): the child takes its place
        TreeNode* child = node->left;
        if (child == nullptr)
            child = node->right;
        delete node;
        return child;               // nullptr for a leaf
    }
    // case 3 (two children): copy the inorder successor, remove it below
    TreeNode* successor = node->right;
    while (successor->left != nullptr)
        successor = successor->left;        // smallest of the right subtree
    node->data = successor->data;
    bool dummy = false;
    node->right = removeFrom(node->right, successor->data, dummy);
    return node;
}

// ============================ wrappers ============================
void BST::preorder() const { ::preorder(root); }
void BST::inorder() const { ::inorder(root); }
void BST::postorder() const { ::postorder(root); }
int  BST::height() const { return ::height(root); }
bool BST::isBalanced() const { return ::isBalanced(root); }
bool BST::isEmpty() const { return root == nullptr; }
