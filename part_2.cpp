#include <iostream>
using namespace std ;

int main(){
    int n , i ,j ;
    cin >> n ;
    if ( n%2 == 0){
        n = n+1 ;
    } 
    for ( i=0 ; i < (n/2 +1) ; i++){
        for ( j=0 ; j < n ; j++){
            if ( (n/2 - i -1) < j && j < (n/2 + i +1 ) ){
                cout << "*";
            }
            else{
                cout << " ";
            }          
        }
        cout << endl;
    }
        for ( i=0 ; i < n/2 ; i++){
        for ( j=0 ; j < n ; j++){
            if (  i < j && j < (n - i - 1) ){
                cout << "*";
            }
            else{
                cout << " ";
            }          
        }
        cout << endl;
    }
    return 0;
}