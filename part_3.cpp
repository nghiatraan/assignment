#include <iostream>
using namespace std ;

int Input( int d , int m , int y){
    if( m <=0 || m >=13){
        return 1;
    }
    switch (m){
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12:
        {
            if( 0<d && d<32 ){
            return 31;
            break;}
            return 2;
            break;
        }
        case 2 : 
        {
            if( (y % 4 == 0) && (0<d && d<30)){
                return 29;
                break;
            }else if (0<d && d<29){
                return 28;
                break;
            }
            return 2;
            break;
        }
        case 4 : case 6 : case 9 : case 11 : 
        {
            if(0<d && d<31){
                return 30;
                break;
            }
            return 2;
            break;
        } 
    }
}

void nextday(int d , int m , int y){
    int nextd = 0, nextm = 0, nexty = 0;
    if (d == Input(d , m , y))
    {
       if ( m == 12)
       {
           nexty = y + 1;
           nextm = 1;
           nextd = 1;
       }
       nexty = y;
       nextm = m + 1;
       nextd = 1;  
    }else{
    nexty = y;
    nextm = m;
    nextd = d + 1;
    }
    cout << "The next day: " << nextd << "/" << nextm << "/" << nexty << endl;   
}


void previousday(int d , int m , int y){
    int pred = 0, prem = 0, prey = 0;
    if (d == 1)
    {
       if ( m == 1)
       {
           prey = y - 1;
           prem = 12;
           pred = 31;
       }else{
       prey = y;
       prem = m - 1;
       pred = Input( d , prem , y);
       } 
    }else{
    prey = y;
    prem = m;
    pred = d - 1;
    }
    cout << "The next day: " << pred << "/" << prem << "/" << prey << endl;   
}

int main(){
    int d, m, y;
    int n;
    cout << "Input dd/mm/yyyy \n";
    cin >> d >> m >> y ;
    if(Input(d, m, y) == 1 ){
        cout << " Nhap lai month \n";
    }else if(Input(d, m, y) == 2){
        cout << " Nhap lai date \n";
    }else{
        cout << "Date: " << d << endl;
        cout << "month: " << m << endl;
        cout << "year: " << y << endl;
        cout << endl;
        cout << "============MENU============" << endl;
        cout << "1. Find the number of month" << endl;
        cout << "2. Show the next day (dd/mm/yyyy)" << endl;
        cout << "3. Show previous day (dd/mm/yyyy)" << endl;
        cout << "4. exit" << endl;
        cout << endl;
        while (1)
        {
            cout << "Seclec to the number" << endl;
            cin >> n;
            switch(n){
                case 1:
                {
                    cout << "number of month: " << Input( d , m , y) << endl;
                    break;         
                }
                case 2:
                {
                    nextday(d , m , y );
                    break;
                }
                case 3:
                {
                    previousday(d , m , y );
                    break;
                }     
            }
            if(n==4){
                break;
            }
        }
    }
}
