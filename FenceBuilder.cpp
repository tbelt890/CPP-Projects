#include <iostream>
#include <iomanip>
using namespace std; 

	int main()
	{	
		int nsc, ewc, nsb, ewb; //north/south post count, east/west post count, north/south board count, east/west board count
		//char nsp = '|', ewp = '-', board2= ':'; // fence chars ns post , ew post, board 1 = north south, board 2 = east west
		char board1[10] = "==";
		bool condition = 1;
		
		while (condition == 1)
		{
		
		
		cout<<"TB Agriculture Fence Builder 2024 Variant"<<endl;
		
		
		
		do{cout<<"What is the number of North/South posts? ";
			cin>>nsc;
		if (nsc<2) cout<<"Value must be at least 2 Please try again."<<endl;
		if (nsc > 12) nsc = 12;
		}while (nsc<2 || nsc > 12);
		
		
		do{cout<<"What is the number of East/West posts? ";
			cin>>ewc;
		if (ewc<2) cout<<"Value must be at least 2 Please try again."<<endl;
		if (ewc > 12) ewc = 12;
		}while (ewc<2 || ewc > 12);
		cout<<endl;
		
		int count1, count2, length = nsc -1, height = ewc - 1; //loop counter
			cout<<"|";
		for (count1 = 2; count1 <= nsc; ++count1)
		{
			
			
			
				cout<<"==|";
			
		}
			cout<<endl;
  cout<<":"<<setw((nsc-1)*3)<<":"<<endl;
  		for (int count2 = 2; count2 < ewc ; ++count2)
		{
				
				cout<<"-"<<setw((nsc-1)*3)<<"-"<<endl;
				cout<<":"<<setw((nsc-1)*3)<<":"<<endl;
		}
		
		
		for (int count1 = 1; count1 <= nsc; ++count1)
		{
				cout<<"|";
			
			if (count1 < nsc){
				cout<<board1;
			
		}
	}
		
		cout<<"\n\nCorral Built!!"<<endl;
		
		char again;
		cout<<"\nWould you like to build another (Y/N)? ";
		cin>>again;
			if (again == 'n' || again == 'N') { condition = 0;}
				
	}
			
		
		return 0;
	}
