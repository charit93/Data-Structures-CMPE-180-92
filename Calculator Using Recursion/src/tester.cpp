#include <iostream>
#include <stdlib.h>
#include "Calculator.h"

using namespace std;

int main()
{
	Calculator calculator;
	char in;
	do  // Arithmetic Expressions
	{
		cout << endl << "Expression? ";
		cin >> ws;
		in = cin.peek();

		if (in != '.') // Evaluating Expression
		{
			try
			{
				cout << calculator.expression()<< endl; // Print its value

				cin >> in;
				if (in != '=')
				{
					string error=string("Unexpected ") + in;
					throw error;
				}
			}
			catch(string& message)
			{
				cout << "***** " << message << endl;
			}
			string leftout;  // Skipping the left out in line
			getline(cin, leftout);
		}
	} while (in != '.');

	cout << endl << "Done!" << endl;
	return 0;
}
