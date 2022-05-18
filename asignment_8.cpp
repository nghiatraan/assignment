#include <iostream>
#include <cstring>
using namespace std ;
/****************************************************
function:findsubstr
Parameter 
In:str - string str
In:sub - string sub
Return : the position of the first sub string in the string str
****************************************************/
int findsubstr(const char *str, char *sub){
    int i = 0; 
    int j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == sub[j])
        {
            while (str[i] == sub[j] && sub[j] != '\0')
            {
                i++;
                j++;
            }
            return i - j;
        }        
        i++;
    }
    return -1;
}

int main(){
    char str[100];
    char sub[50];
    cout << "Enter string str: ";
    cin.getline(str,100);
    cout << "Enter string sub: ";
    cin.getline(sub,50);
    cout << "the position of the first sub string in the string str: " << findsubstr( str, sub);
    return 0;

}