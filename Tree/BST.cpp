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
    // TODO: empty spot -> makeNode; smaller -> left; larger -> right
    return node;
}

// ============================ Q5 ============================
bool BST::find(int value) const
{
    return false;                   // TODO: walk down, one side only
}

bool BST::findMin(int& value) const
{
    return false;                   // TODO: leftmost node
}

bool BST::findMax(int& value) const
{
    return false;                   // TODO: rightmost node
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
    // TODO: find the node; leaf / one child / two children (successor)
    return node;
}

// ============================ wrappers ============================
void BST::preorder() const { ::preorder(root); }
void BST::inorder() const { ::inorder(root); }
void BST::postorder() const { ::postorder(root); }
int  BST::height() const { return ::height(root); }
bool BST::isBalanced() const { return ::isBalanced(root); }
bool BST::isEmpty() const { return root == nullptr; }
