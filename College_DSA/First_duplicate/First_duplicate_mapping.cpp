#include<iostream>
#include<unordered_map>
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

    unordered_map<int,int> mp ;

    for(int i=0 ; i<n ; i++){
        mp[arr[i]] = i ;
    }

    int pos ;
    bool found = false;
    for(int i=0 ; i<n ; i++){
        if(i != mp[arr[i]]){
            pos = mp[arr[i]] ;
            found = true ;
            break ;
        }
    }

    if(found){
        cout<< pos+1 <<"th position";
    }
    else{
        cout<< -1 ;
    }    

}