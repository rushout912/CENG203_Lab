#include "TreeUtils.h"
#include <iostream>
#include <queue>                    // std::queue: the library version of
using namespace std;                // Week 4's Queue, for any type

TreeNode* makeNode(int value)
{
    TreeNode* node = new TreeNode;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// ============================ Q2 ============================
void preorder(const TreeNode* node)
{
    // TODO: base case; print; left; right
}

void inorder(const TreeNode* node)
{
    // TODO: left; print; right
}

void postorder(const TreeNode* node)
{
    // TODO: left; right; print
}

int countNodes(const TreeNode* node)
{
    return 0;                       // TODO: 1 + left + right
}

int countLeaves(const TreeNode* node)
{
    return 0;                       // TODO
}

// ============================ Q3 ============================
int height(const TreeNode* node)
{
    return -1;                      // TODO: 1 + the taller subtree
}

void levelOrder(const TreeNode* node)
{
    // TODO: std::queue<const TreeNode*>; push root; pop, print, push kids
}

// ============================ Q6 ============================
bool isBalanced(const TreeNode* node)
{
    return false;                   // TODO: compare the heights, recurse
}

// ============================ memory ============================
void destroy(TreeNode* node)
{
    if (node == nullptr)
        return;
    destroy(node->left);            // children first ...
    destroy(node->right);
    delete node;                    // ... the node last (postorder)
}
