#include <iostream>
#include <iomanip>
using namespace std;

void const gameBoard(char TicTac[3][3]);									// function just to display the board instead of typing
bool winCheck (char TicTac[3][3], char playersym);							//wincheck calls our array, since gameboard passes by reference and changes it. playersym passes either X or O
bool gameTie (char TicTac[3][3]);											// gametie which will pass the board alongside every win check
																				//alter it back to the default '*' essentially restarting the game.

		int main()
		{
			char TicTac[3][3] = {											// Rows , Columns
			{'*', '*', '*'},
			{'*', '*', '*'},
			{'*', '*', '*'}
			};
			
			
			int i, j;														// loop counters for array 
			bool winner = false, gametie = false;
			bool validinput = false;						
			bool win1 = false, gametie1 = false;												// bool to track winner for player 1 - initally false, same with gametie
			bool player1 = true, player2 = false;
			
			do {										// loop will keep repeating until 
			
			int row = 0, col = 0;
			char playersym;													//char var which will switch X and O and used as parameter for wincheck
			
			
			do{																// do while loop for player 1
					if (winner == true || gametie == true)
					{break;}
					else if (winner == false) 
					{gameBoard(TicTac);}										
			
				cout<<"\nPlayer 1 is X, What will be your move? ";			// to let user play 
				cin>>row>>col;
				
			if (row < 0 || row >= 3 || col < 0 || col >= 3)
					{ cout<<"This is an invalid placement. Input again."<<endl;}
			else if (TicTac[row][col] != '*') {cout<<"	  This spot is already Taken!"<<endl;}			//if the space is not a *, it is not available thus, no placement
			
			else if (TicTac[row][col] != '*' && TicTac[row][col] != 'X' || TicTac[row][col] != 'O')																						 
			{
				TicTac[row][col] = 'X';
				validinput = true;
				playersym = 'X';																		// playersym for parameter to winCheck
			}
			
				
																									
				win1 = winCheck(TicTac, playersym);
				gametie = gameTie(TicTac);
					if (win1 == true)
					{
						cout<<"\nPlayer 1 is the WINNER!!"<<endl;
							gameBoard(TicTac);									// to output board demonstrating win.
						 	winner = true;
							 break;												// I found this in the book and I couldn't think of another way to ensure the loop is exited			 	
					}
				else if (gametie == true)
				{	
				 cout<<"Game Tie! Resetting Game Board..."<<endl;
					for (int g = 0; g < 3; g++)
					{
						for (int t = 0; t < 3; t++)
						{
						TicTac[g][t] = '*';																			//same theory as above, just tests if the index is '*'
						}

					}
					winner = false;
					player1 = true;
					player2 = false;
			}
				
				}while (validinput == false && player1 == true);
			

				
				
				
				
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PLAYER 2 TURN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~				
				
				row = 0;																				//reset the variables in between loops and after outputting the gameboard
				col = 0;																				// so now it is easily set by player 2
				
						// tests validinput from above, if wincheck set to true it wont run through the loop
			
			
			do{							//repeat of do while loop for player 2
				if (winner == true)
					{break;}
				else if (winner == false) 
					{gameBoard(TicTac);}
				else if (gametie == true)
				{	
				cout<<"Game Tie! Resetting Game Board..."<<endl;
					for (int g = 0; g < 3; g++)
					{
						for (int t = 0; t < 3; t++)
						{
						TicTac[g][t] = '*';																			//same theory as above, just tests if the index is '*'
						}

					}
					winner = false;
					player1 = true;
					player2 = false;
			}
				
				validinput = false;																		// set the variable back to 0, the first loop will set it to true which allows
																											// overwriting																				
				cout<<"Player 2 is O, What will be your move? ";
				cin>>row>>col;

				if (row < 0 || row >= 3 || col < 0 || col >= 3){ cout<<"This is an invalid placement. Input again.";}
				else if (TicTac[row][col] != '*') {cout<<"	  This spot is already Taken!"<<endl;}
				else if (TicTac[row][col] != '*' && TicTac[row][col] != 'X' || TicTac[row][col] != 'O')
				{
					TicTac[row][col] = 'O';
					validinput = true;
					playersym = 'O';																// sets the playersym to 'O' ONLY after a validinput is true
				}
			
				bool win2 = winCheck(TicTac, playersym);
				bool gametie2 = gameTie(TicTac);
					if (win2 == true)
					{
						cout<<"\nPlayer 2 is the WINNER!!"<<endl;
						winner = true;
						break;
																								// does the same here, if wincheck using playersym is true, player 2 is winner and
					}
					else if (gametie2 == true)
					{
						cout<<"Board is Filled! No Winner Detected"<<endl;
						gameBoard(TicTac);
						winner = true;
						break;
					}																							// breaks the loop effectively
			
			}while(validinput == false && player2 == true);
			
				
				
			
																							
			}while (winner == false);
			
			return 0;
		}
		
		
//----------------------------FUNCTIONS---------------------------------------------------------------------------------------------------------------------------
		
		void const gameBoard (char TicTac[3][3])
		{
			int i, j;
			
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					cout<<TicTac[i][j];
					if (j < 3 - 1) {cout<<" | ";}
				}
				cout<<endl;
				if (i < 3 - 1){cout<<"---------"<<endl;}
			}
			
		}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		bool winCheck (char TicTac[3][3], char playersym)
		{
			int w, c;
			bool result = false;
			
			for (w = 0; w < 3; w++)																				//For loop that goes through each part of the array: tests the rows first
			{
				if (TicTac[w][0] == playersym && TicTac[w][1] == playersym && TicTac[w][2] == playersym)		//we passed playersym which will either be assigned X or O, then tests
				{result = true;}																					//possible wins
			}
				for (c = 0; c < 3; c++)
				{
					if (TicTac[0][c] == playersym && TicTac[1][c] == playersym && TicTac[2][c] == playersym)	//then tests columms
					{result = true;}																			// if any of the possible wins work, sets our boolean result to true
				}
				
				if (TicTac[0][0] == playersym && TicTac[1][1] == playersym && TicTac[2][2] == playersym)	//diagonals 
					{result = true;}
				
				if (TicTac[0][2] == playersym && TicTac[1][1] == playersym && TicTac[2][0] == playersym)
					{result = true;}																			

				
			return result;																						// returns the result, if no win it will be zero/false and game will continue
		}
		
		bool gameTie(char TicTac[3][3])
		{
			int g, t;
			
			for (g = 0; g < 3; g++)
			{
				for (t = 0; t < 3; t++)
				{
					if (TicTac[g][t] == '*')
					{return false;}																			//same theory as above, just tests if the index is '*'
				}

			}
			return true; 
		}