#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

	int main()
	{
		string userstnc;
		
		cout<<"Enter a phrase: ";
		getline(cin,userstnc);
		
		int last = userstnc.length()- 1;
		
		for (int count = last; count >= 0; count--)
		{
			cout<<userstnc[count];
		}
		
		return 0;
	}