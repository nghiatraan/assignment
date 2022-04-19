#include <iostream>
using namespace std ;

int sodoi(int n){
  int m  = 0;
  while( n >0) {
    m = m*10 + n%10;
    n = n / 10;
  }
  return m;
}

int main(){
  int n;
  cout << " Nhap so n \n";
  cin >> n; 
  if (n<0){
    n = -1*n ;
  }
  if (n == sodoi(n)){
    cout << n << " la so doi xung. \n";
  }
  else{
    cout << n << " khong la so doi xung. \n";
  }
  return 0;
}