#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std; 
//~~~~~~~~~Function Prototype
void coinToss(int games);

		int main()
		{
			int games, t;
			time_t timer;
			srand(time(&timer));
			
			cout<<"How many times will we flip the coin? ";
			cin>>games;
			

				coinToss(games);
			
			return 0;
		}
	void coinToss(int games)
	{
		int tailcnt = 0, headcnt = 0;
		
		for (int t = 0; t < games; ++t)
		{
		int flip = rand() %2;
		if (flip == 0){cout<<"Heads"<<endl;
					headcnt++;}												//display the head and tail count
		else {cout<<"Tails"<<endl;
					tailcnt++;}	
		}
		cout<<headcnt<<" Heads "<<tailcnt<<" Tails";
	}