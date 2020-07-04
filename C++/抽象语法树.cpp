#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class NumberNode;
class OperatorNode;

class Node {
public :
    enum class Type {
        Number,
        Operator
    };
    class IVisitor {
    public:
        virtual void Visit(NumberNode *) = 0;
        virtual void Visit(OperatorNode *) = 0;
    };
    Node(Type t) : t(t) {}
    void setLeft(Node *node) { this->left = node; }
    void setRight(Node *node) { this->right = node; }
    Node *getLeft() { return this->left; }
    Node *getRight() { return this->right; }
    virtual void Accept(IVisitor *) = 0;
    virtual ~Node() {}
private:
    Type t;
    Node *left, *right;
};

class NumberNode : public Node {
public:
    NumberNode(string expr) : Node(Node::Type::Number) {
        int i = 0;
        while (expr[i] == '(' || expr[i] == ' ') ++i;
        this->num = atoi(expr.c_str() + i);
    }
    int getNum() { return this->num; }
    void Accept(IVisitor *vis) {
        vis->Visit(this);
    }
    ~NumberNode() {}
private:
    int num;
};

class OperatorNode : public Node {
public:
    enum class Type {
        PLUS,
        SUB,
        MULTY,
        DIV
    };
    OperatorNode(char op) : Node(Node::Type::Operator) {
        switch (op) {
            case '+': t = Type::PLUS; break;
            case '-': t = Type::SUB; break;
            case '*': t = Type::MULTY; break;
            case '/': t = Type::DIV; break;
        }
    }
    Type getType() { return this->t; }
    void Accept(IVisitor *vis) {
        vis->Visit(this);
    }
    ~OperatorNode() {}
private:
    Type t;
};

class AST {
public:
    AST(string expr);
    int output();
    Node *getRoot() { return this->root; }
private:
    Node *root;
};

AST::AST(string expr) {
    int priority = 0, pos = -1, pos_priority = 1000;
    for (int i = 0; i < expr.length(); i++) {
        int cur_priority = 1000 + 1;
        switch (expr[i]) {
            case '(': priority += 100; break;
            case ')': priority -= 100; break;
            case '+': 
            case '-': cur_priority = priority + 1; break;
            case '*': 
            case '/': cur_priority = priority + 2; break;
        }
        if (cur_priority <= pos_priority) {
            pos = i;
            pos_priority = cur_priority;
        }
    }
    if (pos == -1) {
        this->root = new NumberNode(expr);
    } else {
        string str1, str2;
        str1 = expr.substr(0, pos);
        str2 = expr.substr(pos + 1);
        this->root = new OperatorNode(expr[pos]);
        AST left(str1), right(str2);
        this->root->setLeft(left.root);
        this->root->setRight(right.root);
    }
}

class GetResultVisitor : public Node::IVisitor {
public:
    void Visit(NumberNode *obj) {
        this->result = obj->getNum();
    }
    virtual void Visit(OperatorNode *obj) {
        GetResultVisitor vis1, vis2;
        obj->getLeft()->Accept(&vis1);
        obj->getRight()->Accept(&vis2);
        switch (obj->getType()) {
            case OperatorNode::Type::PLUS :
                this->result = vis1.result + vis2.result;
                break;
            case OperatorNode::Type::SUB :
                this->result = vis1.result - vis2.result;
                break;
            case OperatorNode::Type::MULTY :
                this->result = vis1.result * vis2.result;
                break;
            case OperatorNode::Type::DIV :
                this->result = vis1.result / vis2.result;
                break;
        }
    }
    int result;
};

int AST::output() {
    GetResultVisitor vis;
    this->root->Accept(&vis);
    return vis.result;
}

int main() {
    string str;
    while (getline(cin, str)) {
        AST tree(str);
        cout << tree.output() << endl;
    }
    return 0;
}

