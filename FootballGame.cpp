
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

	int main(){
		
		char event;
		int quarter = 1;
		char poss, poss1;
		string home, away;
		bool condition = true;
		
		while (condition == true){			//game loop
		
		cout<<"American Football Scorekeeper's Assistance "
                   "\n                    Fall 2024 Version-1230"<<endl;
                   
        cout<<"\nWhat is the Home team mascot name? ";
        getline(cin,home);
        cout<<"\nWhat is the visiting team mascot name? ";									// states once, re outputs if Y is put at end
        getline(cin,away);
        cout<<endl;															// seems to output asking for home team without allowing any input, skipping to next line
																			// only asking for away team
		do{
		cout<<"\nWhich Team will begin with possession of the Ball (H/V)? ";
		cin>>poss1;
		if (toupper(poss1) != 'H' && toupper (poss1) != 'V') cout<<"Possession must begin with team 'H' or 'V'. Enter again: "<<endl;
	}while (toupper(poss1) != 'H' && toupper (poss1) != 'V');																			//thought it could be an issue
																															// if users could input any letter
		cout<<endl;
		
		poss = poss1;
		
		cout<<"\nEvent Code Description             Event Code Description"
			"\ny 	   Yardage made on play       t	      Ball turned Over "					//^^^^^
			"\nf 	   Field Goal                 q	      Quarter is Over "
			"\ng 	   Goal(touchdown)            p	      Penalty "
			"\ns 	   Safety                     C	      Game Canceled "<<endl<<endl;
			
			

			int yleft = 10, gain, td, hscore = 0, down = 1, flagyrd; // yards left to first, yards gained, touchdown extra points amount, game score, quarter number, down number
			int vscore = 0;
			char flagtm, flgdwn;
			
			while (condition && quarter <= 4 && event != 'C' && event != 'c'){			// in-game event loop
			
			cout<<"\nCurrent Status: "<<quarter;
			if (quarter==1) cout<<"st";
			else if (quarter==2) cout<<"nd";
			else if (quarter==3) cout<<"rd";
			else                 cout<<"th";
			cout<<" Quarter            Ball Possession: "<<poss<<" [";

			if (poss=='H' || poss== 'h')	cout<<home;
			else                            cout <<away;
			cout<<"]"<<endl;
				cout<<"Home ["<<home<<"]   "<<hscore<<"     Visitors ["<<away<<"]          "<<vscore<<"       Down "<<down<<"   "<<yleft<<" Yards to first down"<<endl;
		
			//^^^^^ everything up to here looks to be working 
		
		
			cout<<"What event ?  ";
			cin>>event;
			if (event == 'y' || event == 'Y')			//event y
			{cout<<"How many yards gained? ";
			cin>>gain; {yleft = yleft - gain;} 							//$$$
			if (yleft <= 0){	
				down = 0;
				yleft = 10;
			}
			if (down == 5 && yleft > 0){
					
					if (poss == 'h' || poss == 'H'){
					poss = 'v';
				}
				else 
				{
					poss = 'h';
				}
				down = 0;
				yleft = 10;
			}
			}
			else if (event == 'g' || event == 'G')		//event g
			{	do{cout<<"How many extra points? ";
					cin>>td;
					if (td < 0) {td = 0;}
					else if (td >= 3) {cout<<"Extra points cannot be higher than 2."<<endl;}				// ensures no values higher than 2 can be input
				}while (td < 0 || td >= 3 );
				
				if (poss == 'h' || poss == 'H'){ 
				hscore += 6 + td;}
				else 										//looks to work well and hold variables 
					vscore += 6 + td;
					
				if (poss == 'h' || poss == 'H'){
					poss = 'v';
				}
				else 
				{
					poss = 'h';
				}
				
				down = 0;
				yleft = 10;
			}
			else if (event == 'q' || event == 'Q')		//event Q
			{
				quarter++;							//adds quarter and once 4th ends the game ends 
				down = 0;
				if (quarter == 3){
				poss = (poss1 == 'H' || poss1 == 'h') ? 'V' : 'H';	
				cout<<"\nEnd of 1st Half!    Home ["<<home<<"]  "<<hscore<<"   Away ["<<away<<"]  "<<vscore<<endl;
				}
				
			}
			else if (event == 't' || event == 'T')		//event t
			{
				poss = (poss == 'H' || poss == 'h') ? 'V' : 'H';		//tried ternary operator for if else of what team has possession in event of 
				down = 0;
				yleft = 10;
			}
			else if (event == 'c' || event == 'C')		//event c
			{
				condition = false;					// if c is put in, sets boolean to false which stops our loop
			}
			else if (event == 's' || event == 'S')		//event s
			{	if (poss == 'H' || poss == 'h'){
					vscore += 2;
					poss = 'v';}
				else { hscore += 2;
						poss = 'h';
						
				}
				down = 0;
				yleft = 10;
			}
			else if (event == 'f' || event == 'F')		//event f
			{
				if (poss == 'h' || poss =='H'){
					hscore += 3;
					poss = (poss == 'H' || poss == 'h') ? 'V' : 'H';
				}
				else{
					vscore += 3;
					poss = (poss =='V'|| poss == 'v') ? 'H' : 'V';
				}
				down= 0;
				yleft = 10;
			}
			 
			
			else if (event == 'p' || event == 'P')
			{
				cout<<"Which team (H/V)? ";
				cin>>flagtm;
				
				cout<<"\nRepeat of down(Y/N)? ";
				cin>>flgdwn;
				
				if (toupper(flgdwn) == 'Y'){		// was trying to have it only ask yards penalized if N was input
					down--;
				}
				else{
				cout<<"\nYards penalized? ";				// unintentional infinite loop, not sure why it is looping, seems to be all i am stuck on.12/8
				cin>>flagyrd;
															// FINALLY figured out the loop, had flagdwn variable as an int instead of char, so was not testing properly
					if (toupper(flagtm) == toupper(poss)){		// looks to be working right now, give or take a few errors
					yleft += flagyrd;}
				
				else {
					yleft -= flagyrd;
					}	
				}
			}
			down++;
		}									// end of the inner gameplay loop
		
			cout<<"\nGAME OVER      Home ["<<home<<"]  "<<hscore<<"    Away ["<<away<<"]  "<<vscore<<endl;
		
			char again;
			cout<<"Is there another game Y/N? ";
			cin>>again;
			if (again == 'n' || again == 'N') {condition = false;}
			else{	condition = true;}
		}
	
	
		
		return 0;
		
		
	}
	
		
	//	game loop and inner game loop work, outputs status based on possession put in by user, adjusts quarter ending (st, nd) based on quarter number
	// events all work, need to switch ball at end of 2nd quarter, need to change possession if 4th down is over and did not get a 1st down, report halftime score and end score 
	// need to do S, F, and P, -- 11/29
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// tweaked a few issues with the down starting at 2 due to the increment at the end of the event. It now works as it should. Added ternary operator to a 
	// few events to make it look cleaner. Also tried to use the toupper() function for less typing. 
	// added all events so far, just need to fix P, and go in and test for anymore issues. Almost Done! -- 12/3
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Added score display at halftime & end of game. Also fixed a bug where you could choose any number for extra points which allowed for cheating. 
	//Tried a couple more ideas with P, the event loops no matter what I type in. Going to reapproach it tomorrow and see if I can at least break the infinite loop. 12/8.
	
	// figured out issues with data types being typed wrong and leading to testing not working as it should. Finally removed the infinite loop, works without the
	// issue, however, not 100% perfect. Almost! Just needs a few tweaks and I am happy with it :) 12/9
	
