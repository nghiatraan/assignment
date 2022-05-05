#include <iostream>

using namespace std ;

int *get_even_nem( int* arr, int* sz){
    int size = *sz;
    int count = 0;
    int * p = new int[*sz];
    for (int  i = 0; i < size; i++)
    {
        if ( *(arr + i ) % 2 == 0){
            *( p + count) = *(arr + i);
            count++;
        }        
    }
    *sz =count;
    return p;
}

int main(){
    int sz;
    cout << "Nhap kich thuoc mang arr " ;
    cin >> sz;
    int *arr = new int[sz];
    for ( int i = 0; i < sz; i++)
    {
        cout << "\n A[" << i << "] =";
        cin >> *(arr + i) ;
    }
    int* p = get_even_nem( arr , &sz );
    cout << "Mang so chan \n";
    for (int i = 0; i < sz; i++)
    {
        cout << *( p + i ) << " " ;
    }
    cout << endl << "Kich thuoc mang so chan: " << sz ;
    delete[] arr;
    return 0;
}
