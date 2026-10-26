#include<iostream>
#include<cmath>

using namespace std ;

void proj(float vel , float deg){

    float rad = deg * 22/(7 * 180) ;

    float hm = (vel*vel * sin(rad) * sin(rad)) / 9.8 ;
    float rm = (vel*vel * sin(2*rad)) /9.8 ;

    cout <<"Maximum height reached => " << hm << endl;
    cout <<"Maximum range reached => " << rm ;

}

int main(){
    proj(15 , 30) ;
}