#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
int data;
Node* left;
Node* right;
int height;


Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
    height = 0;
}


};

int getHeight(Node* root) {
    if (root == NULL) {
    return -1;
}
return root->height;
}

int getBalanceFactor(Node* root) {
    if (root == NULL) {
    return 0;
}


return getHeight(root->left) - getHeight(root->right);


}

void updateHeight(Node* root) {
    if (root == NULL) {
    return;
}

root->height = max(getHeight(root->left),
                   getHeight(root->right)) + 1;


}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

void preOrder(Node* root) {
    if (root == NULL) {
        return; 
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}

Node* insert(Node* root, int val) {

    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    else {
        return root;
    }

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && val < root->left->data) {
        return rightRotate(root);
    }

    if (balanceFactor > 1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balanceFactor < -1 && val > root->right->data) {
        return leftRotate(root);
    }

    if (balanceFactor < -1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;


}

int main() {
Node* root = NULL;


root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);

cout << "Preorder Traversal: ";
preOrder(root);

cout << "\nInorder Traversal: ";
inOrder(root);

cout << "\nHeight of AVL Tree: "
     << getHeight(root);

cout << endl;

return 0;


}