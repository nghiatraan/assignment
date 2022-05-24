#include <iostream>
using namespace std ;

class CFraction
{
	private: 
		int num;
		int den;
		
	public:
		void importFra(CFraction &Fra);
		void exportFra(CFraction Fra);	
		friend CFraction operator+ (const CFraction&, const CFraction&);
		friend CFraction operator- (const CFraction&, const CFraction&);
		friend CFraction operator* (const CFraction&, const CFraction&);
		friend CFraction operator/ (const CFraction&, const CFraction&);
};

/******************************
* Function name: importFra()
* Description: import fraction
* Parameter: 
	fra : fraction
* Return value: void
*******************************/
void CFraction::importFra(CFraction &Fra)
{
	cout << "\nEnter numberator: "; 
	cin >> Fra.num;
	cout << "Enter denominator: " ; 
	cin >> Fra.den;
	while(Fra.den == 0){
		cout << "Re-Enter denominator " ;
		cout << "Enter denominator: " ; 
		cin >> Fra.den;
	}
}
/******************************
* Function name: gcd
* Description: greatest common divisor of a & b
* Parameter: 
	int a   
	int b  
* Return value: a or b
*******************************/
int gcd(int a, int b) {
	if(a>b){
    if (b == 0) return a;
    return gcd(b, a % b);
	}
	if (a == 0) return b;
    return gcd(a, b % a);
}

/******************************
* Function name: exportFra()
* Description: export fraction
* Parameter: 
	fra  : fraction
* Return value: void
*******************************/
void CFraction::exportFra(CFraction Fra)
{
	cout << Fra.num << "/" << Fra.den;
}
/******************************
* Function name: operator+
* Description: fraction 1 + fraction 2
* Parameter: 
	const Fra1  : fraction 1
	const Fra2  : fraction 2
	CFraction result : sum of Fra1 + Fra2
	int div : greatest common divisor 
* Return value: result
*******************************/
CFraction operator+(const CFraction&Fra1, const CFraction&Fra2)
{
	CFraction result;
	result.num = Fra1.num*Fra2.den + Fra1.den*Fra2.num;
	result.den = Fra1.den*Fra2.den;
	int div = gcd(result.num,result.den);
	result.num = result.num / div;
	result.den = result.den / div;
	return result;
}

/******************************
* Function name: operator-
* Description: fraction 1 - fraction 2
* Parameter: 
	const Fra1  : fraction 1
	const Fra2  : fraction 2
	CFraction result : sum of Fra1 + Fra2
	int div : greatest common divisor 
* Return value: result
*******************************/
CFraction operator-(const CFraction&Fra1, const CFraction&Fra2)
{
	CFraction result;
	result.num = Fra1.num*Fra2.den - Fra1.den*Fra2.num;
	result.den = Fra1.den*Fra2.den;
	int div = gcd(result.num,result.den);
	result.num = result.num / div;
	result.den = result.den / div;
	return result;
}

/******************************
* Function name: operator*
* Description: fraction 1 * fraction 2
* Parameter: 
	const Fra1  : fraction 1
	const Fra2  : fraction 2
	CFraction result : sum of Fra1 + Fra2
	int div : greatest common divisor 
* Return value: result
*******************************/
CFraction operator*(const CFraction&fra1, const CFraction&fra2)
{
	CFraction result;
	result.num = fra1.num*fra2.num;
	result.den = fra1.den*fra2.den;
	int div = gcd(result.num,result.den);
	result.num = result.num / div;
	result.den = result.den / div;
	return result;
}

/******************************
* Function name: operator/
* Description: fraction 1 / fraction 2
* Parameter: 
	const Fra1  : fraction 1
	const Fra2  : fraction 2
	CFraction result : sum of Fra1 + Fra2
	int div : greatest common divisor 
* Return value: result
*******************************/
CFraction operator/(const CFraction&fra1, const CFraction&fra2)
{
	CFraction result;
	result.num = fra1.num*fra2.den;
	result.den = fra1.den*fra2.num;
	int div = gcd(result.num,result.den);
	result.num = result.num / div;
	result.den = result.den / div;
	return result;
}



int main(int argc, char** argv) {
	CFraction Fra1,Fra2;
	CFraction Sum,Sub,Mul,Div;
	
	cout << "Enter Fraction 1: ";
	Fra1.importFra(Fra1);
	cout << "Enter Fraction 2: ";
	Fra2.importFra(Fra2);
	
	cout << "\nSum of Fraction 1 and Fraction 2 = " ;
	Sum = Fra1 + Fra2;
	Sum.exportFra(Sum);
	
	cout << "\nSub of Fraction 1 and Fraction 2 = " ;
	Sub = Fra1 - Fra2;
	Sub.exportFra(Sub);
	
	cout << "\nMul of Fraction 1 and Fraction 2 = " ;
	Mul = Fra1 * Fra2;
	Mul.exportFra(Mul);
	
	cout << "\nDiv of Fraction 1 and Fraction 2 = " ;
	Div = Fra1 / Fra2;
	Div.exportFra(Div);
	return 0;
}
