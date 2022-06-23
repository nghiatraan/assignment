#include "assignment_12.h"
#include <string.h>

using namespace std;

/************************************
*Function: Push data into stack
*parameter: n - number want to push
*Return  : void
************************************/

void CStack::Push(int n)
{

    if ( top >= MAX_SIZE)
    {
        cout << "Stack overflow\n";
    }
    else
        top++;
        stack[top] = n;
}

/************************************
*Function: Pop data out of stack
*Return  : The top element of the stack
************************************/

int CStack::Pop()
{
    if ( top < 0)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        return stack[--top];
    }

}

/***************************************
*Function: show all of elements of stack
*Return  : void
***************************************/
void CStack::print()
{   
    cout << "(top)s[" << top <<"]= "<< stack[top] << endl;
    for ( int i = top -1 ; i>= 0 ; i-- )
    {
        cout << "s[" << i << "] = " << stack[i] << endl;
    }
}

int main()
{
    CStack stack;
    int top ;
    int num ;
    int option ;
    while (1)
    {
    cout << "Select option:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Show\n";
    cout << "4. Exit\n";
    cin >> option;
        switch (option)
        {
        case 1:
        {
            int in;
            cout << "Enter number of number want to push \n";
            cin >> in;
            for ( int i = 0 ; i < in ; i++){
            cout << "Enter number want to push: \n";
            cin >> num;
            stack.Push(num);
            }
            break;
        }
        case 2:
        {
            top = stack.Pop();
            break;
        }
        case 3:
        {    
            stack.print();
            break;
        }
        case 4:
        {
            exit(1);
        }
        default:
        {
            cout << "Enter the number:\n";
        }
        }

    }
    return 0;
}