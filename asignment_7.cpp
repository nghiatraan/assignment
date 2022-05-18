#include <iostream>
using namespace std ;

float Plus(float a, float b){
    return a+b;
}
float Minus(float a, float b){
    return a-b;
}
float Muntiply(float a, float b){
    return a*b;
}
float Divide(float a, float b){
    return a/b;
}
void operation(float a, float b, float(*p2Func)(float,float)){
    cout << p2Func(a,b) << endl ;
}
int main(){
    float a, b;
    cout << "Input the number A = " ;
    cin >> a;
    cout << "Input the number B = " ;
    cin >> b;
    cout << "A + B = ";
    operation( a, b, &Plus);
    cout << "A - B = ";
    operation( a, b, &Minus);
    cout << "A * B = ";
    operation( a, b, &Muntiply);
    cout << "A / B = ";
    operation( a, b, &Divide);
    return 0;
}