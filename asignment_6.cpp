#include <iostream>
using namespace std ;

/*************************************************************
//Function : Import data for matrix
//Parameter: 
In:pArr Pointer is allocated in function importData
In:szRow:Row size of matrix
In:szCol: Column size of matrix
//Return : true: success, false: fail
*************************************************************/
bool importData(int ***pArr, int szRow, int szCol, char M){
    *pArr = new int*[szRow] ;
    if (!*pArr)
        return false;
    for ( int i = 0 ; i < szRow ; i++ ){ 
        (*pArr)[i] = new int[szRow] ;
        if (!(*pArr)[i])
            return false;
        }
    cout << "Enter the number in the matrix " << M << endl;
    for (int i = 0; i < szRow; i++)
    {
        for (int j = 0; j < szCol; j++)
        {
            cout << M << "[" << i << "][" << j << "] = " ;
            cin >> *(*((*pArr)+i)+j);
        }
    }
    return true;
}
/*******************************************
function addMatrix
//Parameter: 
In:pArr1,pArr2 Pointer is allocated in function importData
In:szRow:Row size of matrix
In:szCol: Column size of matrix
//Return : p Pointer is allocated in function add2Matrix
********************************************/
int **add2Matrix(int **pArr1, int **pArr2, int szRow, int szCol){
    int **p = new int*[szRow] ;
    if (!p)
        return 0;
    for ( int i = 0 ; i < szRow ; i++ ){ 
        p[i] = new int[szRow] ;
        if (!p[i])
            return 0;
        }
    for (int i = 0; i < szRow; i++)
    {
        for (int j = 0; j < szCol; j++)
        {
            p[i][j]=pArr1[i][j]+pArr2[i][j];
        }
    }
    return p;
}
/*********************************************************
function: printMatrix
Parameter 
In:pArr Pointer is allocated in function importData and add2Matrix
In:szRow:Row size of matrix
In:szCol: Column size of matrix
**********************************************************/
void printMatrix(int **pArr, int szRow, int szCol, char M ){
    cout << "Matrix " << M << "= " << endl;
    for (int i = 0; i < szRow; i++)
    {
        for (int j = 0; j < szCol; j++)
        {   
            cout << *(*(pArr+i)+j) << "  ";
        }
        cout << endl ;
    }
}

/****************************************************
function:freeMem
Parameter 
In:pArr Pointer is allocated in function importData and add2Matrix
In:szRow:Row size of matrix
In:szCol: Column size of matrix
****************************************************/
void freeMen(int **pArr, int szRow, int szCol){
    for(int i = 0; i<szRow; i++){
        delete[]pArr[i];
    }
    delete[]pArr;
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
    importData( &pArr1, szRow, szCol, 'A');
    importData( &pArr2, szRow, szCol, 'B');
    pArr = add2Matrix( pArr1 , pArr2 , szRow, szCol);
    printMatrix(pArr1, szRow, szCol ,'A');
    printMatrix(pArr2, szRow, szCol ,'B');
    printMatrix(pArr, szRow, szCol ,'C');
    freeMen( pArr1, szRow, szCol);
    freeMen( pArr2, szRow, szCol);
    freeMen( pArr, szRow, szCol);
    return 0;
}
