#pragma once

// One node of a binary tree: a value and two child pointers
struct TreeNode
{
    int       data;
    TreeNode* left;                 // left subtree  (nullptr = none)
    TreeNode* right;                // right subtree (nullptr = none)
};

// Creates a node on the heap with both children set to nullptr
TreeNode* makeNode(int value);
