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

    int l=0 , r = n-1 ;
    while(l<r){
        if(arr[l] == 0 && arr[r] != 0){
            swap(arr[l],arr[r]) ;
            l++ ;
            r-- ;
        }
        else if(arr[l] != 0){
            l++ ;
        }
        else{
            r-- ;
        }
    }
    

    cout << "Array after moving zeros to the end: ";
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " " ;
    }
}