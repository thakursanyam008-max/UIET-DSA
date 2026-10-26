#include<iostream>

using namespace std ;

int tips(float speed){

    int count = 0 ;

    while(speed > 0.00001){
        count++ ;
        speed = speed/2 ;
    }

    return count ;

}

int main(){
    cout << tips(39.7) ;
}