#include <iostream>
#include <string>
using namespace std;

#ifndef AVLTREE
#define AVLTREE

typedef string keyType;

class node{
    public:
        keyType url;
        node * left;
        node * right;
        int height;
};

int height(node * n);

node * createNewNode(keyType);

int max(int, int);

node * leftrotate(node *);

node * rightrotate(node *);

int getBalance(node *N);

void printInorder(node * n);

bool insertNode(node * n, keyType url);

node* insert(node* n, keyType url);

node * searchTreeByKey (node * n, keyType url);

ostream & operator << (ostream & out, node * rhs);

node* deleteNode(node* root, keyType url);

node * minValueNode(node* n);

#endif