#ifndef CALCULATOR_H_
#define CALCULATOR_H_

using namespace std;


class Calculator
{
public:
	Calculator();
	virtual ~Calculator();

	double expression(); //Function to calculate the expression
	double term();       //Function to calculate the term
	double factor();     //Function to calculate the factor
	double power() ;     // Function to calculate the power
};

#endif /* CALCULATOR_H_ */
