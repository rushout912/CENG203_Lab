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
    if (node == nullptr)            // base case: empty subtree
        return;
    cout << node->data << " ";      // node first ...
    preorder(node->left);           // ... then the left subtree ...
    preorder(node->right);          // ... then the right subtree
}

void inorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";      // node in the middle
    inorder(node->right);
}

void postorder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";      // node last
}

int countNodes(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(const TreeNode* node)
{
    if (node == nullptr)
        return 0;
    if (node->left == nullptr && node->right == nullptr)
        return 1;                   // a leaf: no children
    return countLeaves(node->left) + countLeaves(node->right);
}

// ============================ Q3 ============================
int height(const TreeNode* node)
{
    if (node == nullptr)
        return -1;                  // empty tree: no edges at all
    int hl = height(node->left);
    int hr = height(node->right);
    return 1 + (hl > hr ? hl : hr); // one edge down to the taller child
}

void levelOrder(const TreeNode* node)
{
    if (node == nullptr)
        return;
    queue<const TreeNode*> q;       // FIFO: nodes wait in arrival order
    q.push(node);
    while (!q.empty()) {
        const TreeNode* cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->left != nullptr)   // children join the end of the queue
            q.push(cur->left);
        if (cur->right != nullptr)
            q.push(cur->right);
    }
}

// ============================ Q6 ============================
bool isBalanced(const TreeNode* node)
{
    if (node == nullptr)
        return true;                // an empty tree is balanced
    int diff = height(node->left) - height(node->right);
    if (diff > 1 || diff < -1)
        return false;
    return isBalanced(node->left) && isBalanced(node->right);
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
