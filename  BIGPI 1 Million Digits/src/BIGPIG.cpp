#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 10;
const int PLACES         = 1000000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

void output(const mpf_t& pi,double executiontime);

int main()
{

	mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits



	//variables and initialization of the variables
	mpf_t a0;
	mpf_init(a0);

	mpf_t ai;
	mpf_init(ai);

	mpf_t ain;
	mpf_init(ain);

	mpf_t y0;
	mpf_init(y0);

	mpf_t yi;
	mpf_init(yi);

	mpf_t yin;
	mpf_init(yin);

	mpf_t pi;
	mpf_init(pi);

	mpf_t multi;
	mpf_init(multi);

	mpf_t sqart;
	mpf_init(sqart);

	mpf_t power4;
	mpf_init(power4);

	mpf_t dsqrt;
	mpf_init(dsqrt);

	mpf_t psave;
	mpf_init(psave);

	mpf_t v1;
	mpf_init(v1);

	mpf_t v2;
	mpf_init(v2);

	mpf_t v3;
	mpf_init(v3);

	mpf_t v4;
	mpf_init(v4);

	mpf_t v5;
	mpf_init(v5);

	mpf_t v6;
	mpf_init(v6);

	mpf_t v7;
	mpf_init(v7);

	mpf_t v8;
	mpf_init(v8);

	mpf_t v9;
	mpf_init(v9);

	mpf_t v10;
	mpf_init(v10);

	mpf_t v11;
	mpf_init(v11);


	//constants with initialization and assignment

	mpf_t value1;
	mpf_init_set_ui (value1, 1);

	mpf_t value2;
	mpf_init_set_ui (value2, 2);

	mpf_t value4;
	mpf_init_set_ui (value4, 4);

	mpf_t value6;
	mpf_init_set_ui (value6, 6);


	mpf_sqrt (sqart, value2); //sqrt(2)

	mpf_mul (multi, sqart, value4); //4*sqrt(2)

	mpf_sub (a0, value6, multi); //a[0] as 6 - 4sqrt(2)

	mpf_sub (y0, sqart, value1); //y[0] as sqrt(2) - 1

	//Set a[0] and y[0]

	mpf_set (ain, a0);
	mpf_set (yin, y0);

	auto start_time = std::chrono::system_clock::now();

	int i=1;
	do
	{
		double power=pow(2, ((2 * i) + 1)); // 2 to the power [2i+1]

		//y[i-1] ^ 4 into power4

		mpf_pow_ui (power4, yin, 4);

		//(1 - v1) into v1

		mpf_sub (v1, value1, power4);

		mpf_sqrt (dsqrt, v1); //v1 compute sqrt(v1) into dsqrt

		mpf_sqrt (v2, dsqrt); //compute sqrt(dsqrt) into v2.

		mpf_sub (v3, value1, v2); //1 - 4th root(y[i-1] ^ 4)

		mpf_add (v4, v2, value1); //1 + 4th root(y[i-1] ^ 4)

		mpf_div (yi, v3, v4); //  v3/v4

		mpf_add (v5, yi, value1);  //1 + y[i] into v5.

		mpf_pow_ui (v6, v5, 4);  //v5 ^ 4 into v6

		mpf_mul (v7, ain, v6);  //a[i-1] * v6 into v7.

		mpf_pow_ui (v8, yi, 2); //y[i] ^ 2 into v8

		mpf_add (v9, v5, v8); //1 + y[i] + y[i] ^ 2. into v9 - adding v5+v8

		mpf_mul (v10, yi, v9);  //y[i](1 + y[i] + y[i] ^ 2) from v9 * y[i] into v10

		mpf_init_set_ui (psave,power); //2 ^ (2i + 1) and assign the value to psave = power value saved

		mpf_mul (v11, v10, psave); //2 ^ (2i + 1) * v10 into v11

		mpf_sub (ai, v7, v11);  // Last term adding both the values

		mpf_set (yin, yi); //y[i] to y[i-1] for next iteration

		mpf_set (ain, ai); //a[i] to a[i-1] for next iteration

		i++;

	}while(i <= MAX_ITERATIONS);


	mpf_div (pi, value1, ai); //pi is 1/ai

	std::chrono::duration<double> elapsed_time = std::chrono::system_clock::now() - start_time; // time difference current and execution

	double executiontime = elapsed_time.count();

	output(pi,executiontime);

	//Free the space occupied by all the MPIR variables
	mpf_clear (a0);
	mpf_clear (ai);
	mpf_clear (ain);
	mpf_clear (y0);
	mpf_clear (yi);
	mpf_clear (yin);
	mpf_clear (value1);
	mpf_clear (value2);
	mpf_clear (value4);
	mpf_clear (value6);
	mpf_clear (pi);
	mpf_clear (multi);
	mpf_clear (sqart);
	mpf_clear (power4);
	mpf_clear (dsqrt);
	mpf_clear (psave);
	mpf_clear (v1);
	mpf_clear (v2);
	mpf_clear (v3);
	mpf_clear (v4);
	mpf_clear (v5);
	mpf_clear (v6);
	mpf_clear (v7);
	mpf_clear (v8);
	mpf_clear (v9);
	mpf_clear (v10);
	mpf_clear (v11);
	return 0;

}

void output(const mpf_t& pi,double executiontime)
{

	char *referencepi=0;
	int k=1;
	mp_exp_t expo;   // storing the decimal
	referencepi = mpf_get_str(referencepi,&expo,BASE,PRECISION,pi);   // converting number to string
	cout<<"pi to 1Million places:"<<endl<<endl;

	for(int i = 0; i< expo; i++)
	{
		cout << referencepi[i]; // 3 will be printed
	}
	cout << ".";
	do
	{

		cout<<referencepi[k];

		if(k% BLOCK_SIZE == 0)
			//blank after each block.
			cout<<" ";

		if(k% LINE_SIZE == 0)
			//new line after 100 digits per line
			cout<<"\n  ";

		if(k% (PLACES/2) == 0)
			// space between two blocks of each having 5 blocks and 100 lines each
			cout<<"\n  ";
		k++;
	}
	while(k<PRECISION);

	free(referencepi);

	cout<<"Elapsed time :  "<<executiontime<<" seconds "<<setprecision(6)<<fixed<<endl;

}

