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

    int pos ;
    bool found = false;
    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<i ; j++){
            if(arr[i] == arr[j]){
                pos = i ;
                found = true ;
                break ;
            
            }
        }
    }

    if(found){
        cout<< pos+1 <<"th position" ;
    }
    else{
        cout<< -1 ;
    }

}