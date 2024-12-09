#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

	int main()
	{
		char pass[24];
		
		int count;
		
		bool condition = true;
		
		
		while (condition){
		int lengthscore = 0, punctscore = 0, digitscore = 0;
		int whitescore = 0, charscore = 0;
		cout<<"What is your password? ";
		cin.getline(pass, 24);
		
		int const length = strlen(pass);
		
		if (length < 8 || length > 15){
			lengthscore -= 5;
		}										
		else {
			lengthscore -= 8 - length;
		}
		

		
		for (int count = 0; count < length; count++){
		if (ispunct(pass[count])){ punctscore++;}
		if (isdigit(pass[count])){ digitscore++;}
		if (isspace(pass[count])){ whitescore -= 5;}
		if (isalpha (pass[count])){ charscore++;}
	}
		
		if (digitscore == 0){ digitscore -= 5;} 
		if (punctscore == 0){ punctscore -= 5;}
		if (charscore == 0){ charscore -= 5;}
			
			
		int total = lengthscore + punctscore + digitscore + whitescore;
		
		//cout<<lengthscore<<"  "<<punctscore<<"  "<<digitscore<<"  "<<whitescore<<"  "<<charscore<<endl;
				if (lengthscore < 0){cout<<"Under performing in the area of Length"<<endl;}
				if (digitscore < 0){ cout<<"Under performing in the area of Digits"<<endl;}	
				if (punctscore < 0){cout<<"Under performing in the area of Punctuation"<<endl; }
				if (whitescore < 0){ cout<<"Under performing in the area of White Space"<<endl;}
				if (charscore < 0){ cout<<"Under performing in the area of Alphabet Characters"<<endl;}
		
		
		cout<<"\nTotal password score is "<<total<<endl;
			if (total < 4){cout<<"Not high enough try again !"<<endl;}
			else {			cout<<"This password has passed !!"<<endl;
							condition = false;}
		}
		
		
		return 0;
	}