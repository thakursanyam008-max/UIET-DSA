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

int main(){
    TreeNode* Root = new TreeNode{};
    CreateTree(Root);
    return 0;
}