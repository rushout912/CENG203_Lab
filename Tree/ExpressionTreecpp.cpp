#include "ExpressionTree.h"
#include <iostream>
#include <sstream>                  // stringstream: splits the tokens
#include <stack>                    // std::stack: Week 4's Stack, any type
#include <stdexcept>                // runtime_error
using namespace std;

bool isOperator(const string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// ============================ Q8 ============================
ExprNode* buildFromPostfix(const string& postfix)
{
    stack<ExprNode*> st;            // holds finished subtrees
    stringstream ss(postfix);
    string token;
    while (ss >> token) {           // one token at a time: "3", "4", "+"
        // TODO: make a node; operator -> pop right, pop left; push it
    }
    return st.empty() ? nullptr : st.top();
}

void printPrefix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";      // operator first: Polish notation
    printPrefix(node->left);
    printPrefix(node->right);
}

void printPostfix(const ExprNode* node)
{
    if (node == nullptr)
        return;
    printPostfix(node->left);
    printPostfix(node->right);
    cout << node->data << " ";      // operator last: reverse Polish
}

// ============================ Q9 ============================
void printInfix(const ExprNode* node)
{
    // TODO: "(" left " op " right ")" for operators, the number otherwise
}

double evaluate(const ExprNode* node)
{
    return 0.0;                     // TODO: number -> stod; else combine
}

void destroyExpr(ExprNode* node)
{
    if (node == nullptr)
        return;
    destroyExpr(node->left);
    destroyExpr(node->right);
    delete node;
}
