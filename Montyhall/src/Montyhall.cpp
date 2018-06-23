#include <iostream>
#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;


void simulate(int a, string b, string c ,int d,int e,int f,int g,int w , int z)

{
	string pading;

	if(a>0 && a<10)pading= "  ";
	if(a>9 && a<100)pading=" ";
	if(a>=100)pading="";
	cout<< pading <<  a     << setw(7)<<  d                <<setw(7)<<  e             << setw(7) << f << setw(7)<< g << setw(7) <<b << setw(7) << c << endl;

}
using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

Door hideCar()
{
	return 1 + rand() % 3;
}

Door makeFirstChoice()
{
	return 1 + rand() % 3;
}
Door openDoor(Door hideCar,Door makeFirstChoice)
{
	int a;
	{
		{
			if((a!=hideCar) || (a!=makeFirstChoice)){

				a = rand() % 3+1;
			}
		}
		do
		{
			a=rand() % 3 + 1;
		}

		while (a == hideCar || a == makeFirstChoice);
		return a;
	}
}

Door makeSecondChoice(Door makeFirstChoice,Door openDoor)
{
	int b;
	{
		if((b!=makeFirstChoice) || (b!=openDoor)){

			b = rand() % 3+1;
		}
		{
			do
			{
				b = rand() % 3+1;
			}
			while (b ==makeFirstChoice  || b == openDoor);
		}
	}
	return b;
}


int main()
{

	int count1=0,count2=0;
	double ratio;

	srand( time(0));
	cout<< "  #" << setw(7)<< "Car" <<setw(7)<< "First" << setw(7) << "Opened" << setw(7)<< "Second" << setw(7) << "Win" << setw(7) << "Win" << endl;
	cout<< "   " << setw(7)<< "Here" <<setw(7)<< "Choice" << setw(7) << "door" << setw(7)<< "Choice" << setw(7) << "first" << setw(7) << "second" << endl;
	cout<<endl;
	for (int i = 1; i <= 100; i++)
	{


		int d1=hideCar();
		int d2=makeFirstChoice();
		int tmp1=openDoor(d1,d2);
		int tmp2=makeSecondChoice(d2,tmp1);
		string win1;
		string win2;


		if (tmp2 == d1)  // when choice is changed and door having car is same
		{
			win2="yes";
			win1="";
			count2++;
		}
		if(d2==d1)      // Condition when selected choice and door having car is same
		{
			win1="yes";
			win2="";
			count1++;
		}

		simulate(i,win1,win2,d1,d2,tmp1,tmp2,count1,count2);

	}
	cout<<endl;
	cout<< " "<<count1<<"  wins if stay with the first choice"<<endl;
	cout<< " "<<count2<<"  wins if switch to second choice"<<endl;
	ratio=(count2*1.0/count1);
	cout.precision(2);
	cout<<endl;
	cout<< "Win ratio of switch over stay:  "<<ratio;
	return 0;
}
