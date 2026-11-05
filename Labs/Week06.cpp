#include "Labs.h"
#include "../Tree/TreeNode.h"
#include "../Tree/TreeUtils.h"
#include "../Tree/BST.h"
#include "../Tree/ExpressionTree.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void runWeek06()
{
    cout << "--- Week 6: Trees and Binary Search Trees ---" << endl;
    cout << boolalpha;

    // ---------- Q2: a binary tree built by hand ----------
    TreeNode* root = makeNode(1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);
    root->right->right = makeNode(6);
    cout << "[Q2] preorder : ";  preorder(root);   cout << endl;
    cout << "[Q2] inorder  : ";  inorder(root);    cout << endl;
    cout << "[Q2] postorder: ";  postorder(root);  cout << endl;
    cout << "[Q2] nodes = " << countNodes(root)
        << "  leaves = " << countLeaves(root) << endl;

    // ---------- Q3: height and level order ----------
    cout << "[Q3] height(root) = " << height(root)
        << "  height(node 4) = " << height(root->left->left)
        << "  height(empty) = " << height(nullptr) << endl;
    cout << "[Q3] level order: ";  levelOrder(root);  cout << endl;
    destroy(root);
    root = nullptr;

    // ---------- Q4: BST insert ----------
    BST bst;
    int keys[] = { 10, 5, 15, 7, 12, 20, 3 };
    for (int k : keys)
        bst.insert(k);
    cout << "[Q4] insert(10) again = " << bst.insert(10) << endl;
    cout << "[Q4] inorder  : ";  bst.inorder();    cout << endl;
    cout << "[Q4] preorder : ";  bst.preorder();   cout << endl;
    cout << "[Q4] postorder: ";  bst.postorder();  cout << endl;

    // ---------- Q5: find, min, max ----------
    int v = 0;
    cout << "[Q5] find(7) = " << bst.find(7)
        << "  find(8) = " << bst.find(8) << endl;
    bst.findMin(v);
    cout << "[Q5] min = " << v;
    bst.findMax(v);
    cout << "  max = " << v << endl;

    // ---------- Q6: shape and balance ----------
    cout << "[Q6] height = " << bst.height()
        << "  balanced = " << bst.isBalanced() << endl;
    BST chain;
    for (int k = 1; k <= 5; k++)
        chain.insert(k);            // sorted input: the worst case
    cout << "[Q6] chain 1..5: height = " << chain.height()
        << "  balanced = " << chain.isBalanced() << endl;
    cout << "[Q6] chain preorder: ";  chain.preorder();  cout << endl;

    // ---------- Q7: remove ----------
    bst.remove(3);
    cout << "[Q7] remove(3) leaf       : ";  bst.inorder();  cout << endl;
    bst.remove(5);
    cout << "[Q7] remove(5) one child  : ";  bst.inorder();  cout << endl;
    bst.remove(10);
    cout << "[Q7] remove(10) two kids  : ";  bst.inorder();  cout << endl;
    cout << "[Q7] preorder now: ";  bst.preorder();  cout << endl;
    cout << "[Q7] remove(99) = " << bst.remove(99) << endl;

    // ---------- Q8: expression tree from postfix ----------
    ExprNode* expr = buildFromPostfix("3 4 + 5 2 - *");
    cout << "[Q8] prefix : ";  printPrefix(expr);   cout << endl;
    cout << "[Q8] postfix: ";  printPostfix(expr);  cout << endl;

    // ---------- Q9: infix and evaluation ----------
    cout << "[Q9] infix  : ";  printInfix(expr);  cout << endl;
    cout << "[Q9] value  = " << evaluate(expr) << endl;
    destroyExpr(expr);

    ExprNode* bad = buildFromPostfix("8 2 2 - /");
    cout << "[Q9] infix  : ";  printInfix(bad);  cout << endl;
    try {
        double value = evaluate(bad);           // throws: next line skipped
        cout << "[Q9] value  = " << value << endl;
    }
    catch (const runtime_error& e) {
        cout << "[Q9] Error: " << e.what() << endl;
    }
    destroyExpr(bad);
}
