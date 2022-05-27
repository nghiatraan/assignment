#include <iostream>
#include <cstring>
using namespace std ;

class String
{
private:
    char *str;

public:
    friend String operator+ (const String&, const String&);
    friend ostream& operator << (ostream&, String&);
    friend istream& operator >> (istream&, String&);
};

/******************************
* Function name: operator +()
* Description: String 1 + String 2
* Parameter: 
	const String &str1 (I): String 1
	const String &str2 (I): String 2
    const String &str3 (O): String 3
* Return value: str1
*******************************/
String operator+(const String& str1, const String& str2){
    String str3;
    str3.str = strcat(str1.str, str2.str);
    return str3;
}
/******************************
* Function name: operator <<()
* Description: print out string
* Parameter: 
	ostream& OUT (O) : output string
	String& Ostr (I) : input string
* Return value: OUT
*******************************/
ostream& operator<< (ostream& OUT, String& Ostr){
    OUT << Ostr.str;
    return OUT;
}
/******************************
* Function name: operator >>()
* Description: Input string
* Parameter: 
	ostream& IN (O) : output string
	String& Istr (I) : input string
* Return value: IN
*******************************/
istream& operator>>(istream& IN, String& Istr)
{	
	Istr.str = new char[50];
	IN >> Istr.str;
	return IN;
}


int main(){
    String str1, str2, str3;
    cout << "\n Enter string 1 : ";
    cin >> str1;
    cout << "\n Enter string 2 : ";
    cin >> str2;
    str3 = str1 + str2;
    cout << "\n New String : " << str3;
    return 0;





}