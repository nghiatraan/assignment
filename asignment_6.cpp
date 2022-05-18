#include <iostream>
using namespace std ;

/*************************************************************
//Function : Import data for matrix
//Parameter: matrix, and the number of row and column and
//name matrix
//Return : true: success, false: fail
*************************************************************/
bool importData(int ***pArr, int szRow, int szCol){
    int **p = new int*[szRow] ;
    for ( int i = 0 ; i < szRow ; i++ ){ 
        p[i] = new int[szRow] ;
        }
    cout << "Enter the number in the matrix " << endl;
    for (int i = 0; i < szRow; i++)
    {
        for (int j = 0; j < szCol; j++)
        {
        cin >> *(*(p+i)+j);
        cout << *(*(p+i)+j) << endl;
        }
    }
    *pArr = p;
    return true;
}


    
int main(){
    int szRow, szCol;
    cout << "Input number of Row : " ;
    cin >> szRow ;
    cout << "Input number of Column : " ;
    cin >> szCol ;
    int **pArr1 = NULL;
    int **pArr2 = NULL;
    int **pArr = NULL;
    importData( &pArr1, szRow, szCol);
    importData( &pArr2, szRow, szCol);
    return 0;
}