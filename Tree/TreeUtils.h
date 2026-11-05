#pragma once
#include "TreeNode.h"

// Week 6: recursive functions that work on ANY binary tree.
// Every function takes the root of a (sub)tree; nullptr = empty tree.

// ---- Q2: traversals (print the values, separated by spaces) ----
void preorder(const TreeNode* node);        // node - left - right
void inorder(const TreeNode* node);         // left - node - right
void postorder(const TreeNode* node);       // left - right - node
int  countNodes(const TreeNode* node);
int  countLeaves(const TreeNode* node);

// ---- Q3: height and level order ----
int  height(const TreeNode* node);          // edges on the longest path:
// empty = -1, single node = 0
void levelOrder(const TreeNode* node);      // breadth first, uses a queue

// ---- Q6: balance ----
bool isBalanced(const TreeNode* node);      // |h(left) - h(right)| <= 1
// at EVERY node

// ---- memory ----
void destroy(TreeNode* node);               // deletes the whole subtree
