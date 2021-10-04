/*
Dillon van Rensburg
CS 221 Spring 2019
Program #2

This program will get information on two character and will put them through a turn based fight. It will get the information from characterInfo.txt and output it battleResults.txt
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

/*Random Number will be generated from the maxium and minium  numbers from the information. Parameters : two Int varibales 
Return : a Random number between the maxium and minium
*/
int rand (int max, int min){
  int random;
  random = rand() % max + min;
  return random;
}

/* Menu generated for each turn based play. Parameters: string
Returns : void 
*/
int menu (string x){
  int menu;
  int choice;
  cout << "\n1: Attack\n"<< "2: Use "<< x << "\n3: Use a Potion "<< endl;
  cout << "\nchoose an action 1-3: ";
  cin>> choice;
  return choice;
}

int main(){ 
  ofstream outFile; 
  outFile.open("battleResults.txt");
  ifstream inFile("characterInfo.txt");

  //declare varibles 
  string goodName, badName;
  int goodHP,badHP;
  string goodAbility,badAbility;
  int maxAttack,minAttack;
  int maxAbility,minAbility;
  int maxPotion,minPotion;
  int choice;
  int amountGood = 0;
  int amountBad = 0;

  if(inFile.is_open()){
    
    // Inporting the characterInfo
    inFile >> goodName >> goodHP >> goodAbility >> badName >> badHP >> badAbility >> maxAttack >> minAttack >> maxAbility >> minAbility >> maxPotion >> minPotion;
      
    // starting the Battle Statement 
    outFile << goodName << "("<<goodHP<<") will battle "<< badName<<"("<<badHP<<")\n\n"<< endl;
    
    // The while loop will carry on untill one of the HP reaches 0
    while(goodHP > 0 & badHP > 0){
      
      //GOOD GUYS TURN-------------------------------    
      cout << "\nIts " << goodName << " turn. Current HP = "<< goodHP;
      
      choice = menu(goodAbility);
      
      
			while (choice <1 || choice > 3) {
			cout << "=INVALID INPUT= Please enter a value 1,2 or 3\n";
			choice = menu(goodAbility);
			}
      //if the input is right, it will  tests it agaisnt each case and carries of the command
    	switch (choice) {
      case (1):
          //Use Attack
      	int damage;
        damage = rand(maxAttack,minAttack);
        badHP = badHP - damage;
        outFile << goodName << " attacks " << badName << " for " <<damage<<"! New hp = "<< badHP << endl;

        cout << goodName << " attacks " << badName << " for " <<damage<<"! New hp = "<< badHP << endl;
        break;

      case (2):
          //Use Ability
        
        damage = rand(maxAbility,minAbility);
        badHP = badHP - damage;
        outFile << goodName << " Heroicly Strikes " << badName << " for " <<damage<<"! New hp = "<< badHP << endl;

        cout << goodName << " Heroicly Strikes " << badName << " for " <<damage<<"! New hp = "<< badHP << endl;
        break;

      case (3):
          // Use Potion
        int heal;
            //Has a max number of potions(3)
        if (amountGood < 3){
          heal = rand(maxPotion,minPotion);
          goodHP = goodHP + heal;
					// if health is already full or heal goes over max HP then will keep it at max HP
          if (goodHP>200)
              goodHP = 200;
            
					outFile << goodName << " slups a potion and heals for " << heal <<"! New hp = "<< goodHP << endl;

          cout << goodName << " slups a potion and heals for " << heal <<"! New hp = "<< goodHP << endl;
          amountGood= amountGood+1;
          }
          else
          cout << goodName << "is out of potions"<< endl;
          break;
        }
      
      
      
    
//BAD GUYS TURN -----------------------------------
    	if (badHP>0){
      	cout << "\nits " << badName << " turn. Current HP = "<< badHP;
      
      	choice = menu(badAbility);
      
			while (choice <1 || choice > 3) {
				cout << "=INVALID INPUT= Please enter a value 1,2 or 3\n";
				choice = menu(badAbility);
				}
      
      switch (choice) {
          case (1):
          // Use Attack
            int damage;
            damage = rand(maxAttack,minAttack);
            goodHP = goodHP - damage;

            outFile << badName << " attacks " << goodName << " for " <<damage<<"! New hp = "<< goodHP << endl;

            cout << badName << " attacks " << goodName << " for " <<damage<<"! New hp = "<< goodHP << endl;
          
            break;
          case (2):
          //Use Ability
            
            damage = rand(maxAbility,minAbility);
            goodHP = goodHP - damage;

            outFile << badName << " Savagely Cleaves " << goodName << " for " <<damage<<"! New hp = "<< goodHP << endl;

            cout << badName << " Savagely Cleaves " << goodName << " for " <<damage<<"! New hp = "<< goodHP << endl;

            break;
          case (3):
          //Use Potion
            int heal;
						//Has a max number of potions(3)
            if (amountBad < 3){
              heal = rand(maxPotion,minPotion);
              badHP = badHP + heal;
							// if health is already full or heal goes over max HP then will keep it at max HP
                if (badHP>200)
                  badHP = 200;

							outFile << badName << " slups a potion and heals for " << heal <<"! New hp = "<< badHP << endl;
            
              cout << badName << " slups a potion and heals for " << heal <<"! New hp = "<< badHP << endl;
              amountBad= amountBad+1;
            	}
            else
              cout << badName << "is out of potions"<< endl;

              break;
				
          	}
					}
		  	} 
		}
     
  else{
    outFile << "ERROR: Unable to open file!\n";}

// Declare who wins
if ( goodHP <= 0 )
  outFile << badName << " Savagely kills " << goodName << endl;
if( badHP <= 0 )
  outFile << goodName << " Triumphs over " << badName << endl;

return 0;
}
