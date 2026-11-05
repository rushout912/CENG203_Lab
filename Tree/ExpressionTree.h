#pragma once
#include <string>

// Expression tree: every internal node is an operator (+ - * /),
// every leaf is a number. Built from POSTFIX with a stack of nodes.
struct ExprNode
{
    std::string data;               // "3", "+", "42" ... (text, not int)
    ExprNode* left;
    ExprNode* right;
};

bool      isOperator(const std::string& token);
ExprNode* buildFromPostfix(const std::string& postfix);   // Q8
void      printPrefix(const ExprNode* node);              // preorder
void      printPostfix(const ExprNode* node);             // postorder
void      printInfix(const ExprNode* node);               // inorder + ( )
double    evaluate(const ExprNode* node);                 // Q9, throws
void      destroyExpr(ExprNode* node);                    // delete all
