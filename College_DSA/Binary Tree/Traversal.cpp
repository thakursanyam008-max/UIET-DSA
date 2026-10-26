#include<iostream>

using namespace std ;

class TreeNode{
    public:
        int value ;
        TreeNode* left ;
        TreeNode* right ;
};

void CreateTree(TreeNode* Node){
    cout << "Enter Value of Node : " ,
    cin >> Node->value ;

    int loc ;
    cout << "If left Exist ? 0 for NO and 1 for YES" ;
    cin >> loc ;

    if(loc == 1){
        TreeNode* newNode = new TreeNode{};
        Node->left = newNode ;
        CreateTree(newNode) ;
    }

    cout << "If right Exist ? 0 for NO and 1 for YES" ;
    cin >> loc ;

    if(loc == 1){
        TreeNode* newNode = new TreeNode{};
        Node->right = newNode ;
        CreateTree(newNode) ;
    }

}

void Preorder(TreeNode* Node){
    if(Node == nullptr) return;

    cout << Node->value << " ";
    Preorder(Node->left);
    Preorder(Node->right);
}

void Inorder(TreeNode* Node){
    if(Node == nullptr) return;

    Inorder(Node->left);
    cout << Node->value << " ";
    Inorder(Node->right);
}

void Postorder(TreeNode* Node){
    if(Node == nullptr) return;

    Postorder(Node->left);
    Postorder(Node->right);
    cout << Node->value << " ";
}

int main(){
    TreeNode* Root = new TreeNode{};
    CreateTree(Root);

    cout << "Preorder: ";
    Preorder(Root);
    cout << "\nInorder: ";
    Inorder(Root);
    cout << "\nPostorder: ";
    Postorder(Root);
    cout << '\n';

    return 0;
}