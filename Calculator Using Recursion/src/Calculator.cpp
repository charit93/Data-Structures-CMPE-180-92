
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Calculator.h"

using namespace std;


Calculator::Calculator() // Default constructor.
{
}

Calculator::~Calculator() //Destructor.
{
}

double Calculator::expression() // Calculating Arithmetic Expression
{
	char in;
	int minus = 0;  // negative
	int check = 0; // check
	double d;

	cin >> ws;
	in = cin.peek();


	if (in == '-' || in=='+')  // Checking the sign
	{
		if(in=='-')
		{
			cin >> in;                  // minus -
			minus=1;            // Storing the sign
		}
		else
			if(in=='+')
			{
				cin >> in;  // plus +
			}
	}

	d= term();          // evaluate the first term
	if (minus==1)
	{
		d = -d;   // negate it if there was a leading -
	}

	do
	{
		// Skip blanks and check if there is a + or - operator.
		cin >> ws;
		in = cin.peek();

		if(in=='+' || in=='-')
		{
			if(in=='+')
			{
				cin >> in;        // read the +
				d =d+term();  // evaluate the next term and add its d

			}
			else
				if(in=='-')
				{
					cin >> in;        // read the -
					d =d-term();  // evaluate the next term and subtract its d
				}
		}
		else
		{
			check=1; // no more terms
		}
	} while (!check);

	return d;  // the expression's d
}
double Calculator::term() // Calculating Term
{
	double power1; // evaluate the first power
	double power2; // evaluate the second power
	int check =0;
	char in;
	power1=power();

	do 	// Loop to evaluate factors
	{
		// Skip blanks and check if there is a * or / operator.
		cin >> ws;
		in = cin.peek();

		if(in=='*' || in=='/'){
			if(in=='*')
			{
				cin >> in;         // operator *
				power1 =power1*power();  //
			}
			else
				if(in=='/')       // operator /
				{
					cin >> in;
					power2 = power();  // evaluate the next power

					if (power2 != 0) // Dividing unless the d is 0
					{
						power1 =power1/power2;
					}
					else
					{
						string error=string("Division by zero");
						throw error;

						return 0;
					}
				}
		}
		else
		{
			check = 1;  // no more factors
		}
	}while (!check);

	return power1;  // the term's d
}
double Calculator::factor()  // Calculating factor
{
	double d;
	double number;
	cin >> ws;             //  Skipping white spaces
	char in ;
	in=cin.peek();  // Checking the next characters

	// Recursion evaluation
	if (in == '(')
	{
		cin >> in;                    //  (
		d = expression();  // Evaluating the expression

		in = cin.peek(); // Checking whether next character matches or not
		if (in == ')')
		{
			cin >> in;     //  )
		}
		else
		{
			string error=string("Missing )");
			throw error;
		}

		return d;  // return value of d
	}else
		if (isdigit(in))   // Evaluate a number.
		{

			cin >> number;  // let >> read and evaluate the number
			return number;
		}

		else  //  Error
		{

			string error=string("Invalid factor");
			throw error;
			return 0;
		}
}
double Calculator::power()   // Calculating power
{
	double d;   // evaluate the base factor
	int check = 0;
	char in;
	d=factor();

	do // Loop to evaluate powers
	{
		cin >> ws;  // Skipping and checking for ^ operator
		in = cin.peek();

		if (in == '^')
		{
			cin >> in;                    // operator ^
			d = pow(d, power());  // raising the d to the next power
		}
		else {
			check=1;                 //No powers available
		}
	} while (!check);

	return d;
}
