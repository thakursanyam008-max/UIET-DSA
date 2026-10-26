#include<iostream>
#include<unordered_map>

using namespace std ;

int main(){

    int n , arr[100] ;
    cout << "Enter size of Input array: " ;
    cin >> n ;

    for(int i=0 ; i<n ; i++){
        cin >> arr[i] ;
    }

    unordered_map<int,int> mp ;

    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;

        if(mp[arr[i]] == 2) {
            cout << "First duplicate element: " << arr[i];
            return 0;
        }
    }

    cout << "No duplicate is present" ;
    return 0 ;

}