#include<iostream>

using namespace std ;

class Node {

public:
    int data ;
    Node* next ;

    Node(int val){
        data = val ;
        next = NULL ;
    }

};

int main(){

    int n ;
    cout << "Enter the size of Linked List : " ;
    cin >> n ;

    Node* head = NULL ;
    Node* curr = head ;

    int ele ;

    for(int i=0 ; i<n ; i++){
        
        cin >> ele ;

        Node* temp = new Node(ele);

        if (head == NULL) {
            head = temp;
            curr = temp;
        } else {
            curr->next = temp;
            curr = temp ;
        }

    }


    //              Insertion

    int choice ;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Search Element\n";
        cout << "4. Display Array\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int element, pos ;

                for(int i=0 ; i<pos ; i++){
                    curr = curr->next ;
                }

                cout << "Enter the Element : " ;
                cin >> element ;

                Node* temp = new Node(element) ;
                temp->next = curr->next ;
                curr->next = temp ;

                break ;

            }

            case 2: {
                int pos ;

                cout << "Enter the Position : " ;
                cin >> pos ;


                for(int i=0 ; i<pos ; i++){
                    curr = curr->next ;
                }

                curr->next = curr->next->next   ;

                break ;

            }

            case 3: {

                int key , j=0;
                bool found = false ;

                cout << "Enter the Element : " ;
                cin >> key ;

                for(int i=0 ; i<n ; i++){
                    if(curr->data == key){
                        cout << "Element is present at : " << j << endl ;
                        found = true ;
                        break ;
                    }
                    curr = curr->next ;
                    j++ ;
                }

                if(!found){
                    cout << "Element is not present in the Linked List" << endl ;
                }

                break ;

            }

            case 4: {
            
                for(int i=0 ; i<n ; i++){
                    cout << curr->data << " " ;
                    curr = curr->next ;
                }

                break;
        }

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    
    }while(choice != 5) ;

    return 0 ;

}