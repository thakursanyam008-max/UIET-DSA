#include<iostream>
using namespace std ;

int main(){
    int n ;
    cout << "Enter size of array :" ;
    cin >> n ;

    int arr[n] ;

    cout<< "Enter the Elements in array :" ;
    for(int i = 0 ; i < n ; i++){
        cin>> arr[i] ;
    }

    for(int i = 0 ; i < n ; i++){

        if(arr[i] == 0){
            for(int j= i+1 ; j<n ; j++){
                if(arr[j] != 0){
                    swap(arr[i],arr[j]) ;
                    break ;
                }
            }
        }

        cout << "Array after moving zeros to the end: ";
        for(int i=0 ; i<n ; i++){
            cout << arr[i] << " " ;
        }
    }
}