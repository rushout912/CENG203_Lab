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
        ExprNode* node = new ExprNode;
        node->data = token;
        node->left = nullptr;
        node->right = nullptr;
        if (isOperator(token)) {
            node->right = st.top(); // the LAST pushed operand is the right
            st.pop();
            node->left = st.top();  // the one before it is the left
            st.pop();
        }
        st.push(node);              // operand or finished subtree
    }
    return st.top();                // the last subtree is the whole tree
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
    if (node == nullptr)
        return;
    if (isOperator(node->data)) {   // parentheses around every operation
        cout << "(";
        printInfix(node->left);
        cout << " " << node->data << " ";
        printInfix(node->right);
        cout << ")";
    }
    else {
        cout << node->data;         // a number: just print it
    }
}

double evaluate(const ExprNode* node)
{
    if (!isOperator(node->data))    // base case: a number
        return stod(node->data);
    double lhs = evaluate(node->left);      // postorder: children first
    double rhs = evaluate(node->right);
    if (node->data == "+") return lhs + rhs;
    if (node->data == "-") return lhs - rhs;
    if (node->data == "*") return lhs * rhs;
    if (rhs == 0.0)
        throw runtime_error("Division by zero");
    return lhs / rhs;
}

void destroyExpr(ExprNode* node)
{
    if (node == nullptr)
        return;
    destroyExpr(node->left);
    destroyExpr(node->right);
    delete node;
}
