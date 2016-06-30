#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

int main ()
{

cout << "Welcome to the DnD random character generator.\n\n";

srand (time(NULL));
//Current Arrays are Attbonuses, AttributeMax (The value of the attribute), and AttNames.


const int ATTCAP = 6;
int AttributeMax[ATTCAP];
for (int i = 0; i < ATTCAP; i++ )
// This generates 4 six sided dice rolls and drops the lowest die, then assigns them to random abilities.
{

const int ATTRIBUTE = 4;
int playerscore[ATTRIBUTE];
int total = 0;

    for (int i = 0; i < ATTRIBUTE; i++ )
    {
        int dsixroll = (rand () % 6) + 1;
        playerscore[i] = dsixroll;
        total += playerscore[i];
    }

int minimum = playerscore[0];
    for (int i = 0; i < ATTRIBUTE; i++)
        {
            if (playerscore[i] < minimum)
            minimum = playerscore[i];
        }


int totalAttribute = total - minimum;

AttributeMax[i] = totalAttribute;
}


//This outputs the charactes starting scores and their character modifiers.
string AttNames[ATTCAP] = {"Strength","Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma" };
int AttBonuses[ATTCAP];
for (int i = 0; i < ATTCAP; i++)
{
cout << AttNames[i] << ":  \t" << AttributeMax[i];
                            if (AttributeMax[i] == 3)
                            {
                            cout << "\t-4 ability modifier";
                            AttBonuses[i] = (-4);
                            }
                            if (AttributeMax[i] == 4 || AttributeMax[i] == 5)
                            {
                            cout << "\t-3 ability modifier";
                            AttBonuses[i] = (-3);
                            }
                            if (AttributeMax[i] == 6 || AttributeMax[i] == 7)
                            {
                            cout << "\t-2 ability modifier";
                            AttBonuses[i] = (-2);
                            }
                            if (AttributeMax[i] == 8 || AttributeMax[i] == 9)
                            {
                            cout << "\t-1 ability modifier";
                            AttBonuses[i] = (-1);
                            }
                            if (AttributeMax[i] == 10 || AttributeMax[i] == 11)
                            {
                            cout << "\t 0 ability modifier";
                            AttBonuses[i] = (0);
                            }
                            if (AttributeMax[i] == 12 || AttributeMax[i] == 13)
                            {
                            cout << "\t+1 ability modifier";
                            AttBonuses[i] = 1;
                            }
                            if (AttributeMax[i] == 14 || AttributeMax[i] == 15)
                            {
                            cout << "\t+2 ability modifier";
                            AttBonuses[i] = 2;
                            }
                            if (AttributeMax[i] == 16 || AttributeMax[i] == 17)
                            {
                            cout << "\t+3 ability modifier";
                            AttBonuses[i] = 3;
                            }
                            if (AttributeMax[i] == 18)
                            {
                            cout << "\t+4 ability modifier";
                            AttBonuses[i] = 4;
                            }

cout << endl;
}


//cout << "Would you like to reroll your character?  Type 'y' for yes.\n";
//cin >> Reroll;
//}

enum att {HP, BAB, FORT, REF, WILL, DEF, REP, ATT_NUM};
enum classes {STRONG, FAST, TOUGH, SMART, DEDICATED, CHAR, CLASS_NUM};

int charbonus[CLASS_NUM][ATT_NUM] =
{

    {8,1,1,0,0,1,0},
    {8,0,0,1,0,3,0},
    {10,0,1,0,0,1,0},
    {6,0,0,0,1,0,1},
    {6,0,1,0,1,1,1},
    {6,0,1,1,0,0,2},
};

cout << endl << "Based on your character's abilities, what class would you like to play?\n";
cout << endl << "1. Strong -\t Medium health, higher attack and defense, low skill levels.";
cout << endl << "2. Fast -\t Medium health, excellent defense, average skill levels.";
cout << endl << "3. Tough -\t Highest health, good defense, low skill levels.";
cout << endl << "4. Smart -\t Lowest health, highest skill levels, higher reputation.";
cout << endl << "5. Dedicated -\t Lowest health, average skill, good defense and reputation.";
cout << endl << "6. Charismatic - Medium health, highest reputation, medium skills.";
cout << endl;

 // How to get a number.
 int myNumber = 0;
 string input = "";
 while (myNumber < 1 || myNumber > 6)
 {
        while (true) {
        cout << "What is your selection?: ";
        getline(cin, input);

   // This code converts from string to number safely.
        stringstream myStream(input);
        if (myStream >> myNumber)
        break;
   cout << "Invalid number, please try again" << endl;
                    }
 }
 cout << "You entered: " << myNumber << endl << endl;

int wealth = ((rand () % 4) + 1) * 2;

switch (myNumber)
{
case 1:
    cout << "Your starting HP is: " << charbonus[STRONG][HP] << endl;
    cout << "Your starting defense is: " << 10 + charbonus[STRONG][DEF] + AttBonuses[1] << ".  Class Bonus: " << charbonus[STRONG][DEF] << " Dex Modifier: " << AttBonuses[1] << endl << endl;
    cout << "Initiative Total: " << AttBonuses[1] << " Dex Bonus: " <<  AttBonuses[1] << endl << endl;
    cout << "Base Attack Bonus: " << charbonus[STRONG][BAB] << endl << endl;
    cout << "Wealth Bonus: " << wealth << endl;
    cout << "Skill Points " << ((3 + AttBonuses[3])*4) << endl;
    break;
case 2:
    cout << "Your starting HP is: " << charbonus[FAST][HP] << endl;
    cout << "Your starting defense is: " << 10 + charbonus[FAST][DEF] + AttBonuses[1] << ".  Class Bonus: " << charbonus[FAST][DEF] << " Dex Modifier: " << AttBonuses[1] << endl << endl;
    cout << "Initiative Total: " << AttBonuses[1] << " Dex Bonus: " <<  AttBonuses[1] << endl << endl;
    cout << "Base Attack Bonus: " << charbonus[FAST][BAB] << endl << endl;
    cout << "Wealth Bonus: " << wealth << endl;;
    cout << "Skill Points " << ((5 + AttBonuses[3])*4) << endl;

    break;
case 3:
    cout << "Your starting HP is: " << charbonus[TOUGH][HP] << endl;
    cout << "Your starting defense is: " << 10 + charbonus[TOUGH][DEF] + AttBonuses[1] << ".  Class Bonus: " << charbonus[TOUGH][DEF] << " Dex Modifier: " << AttBonuses[1] << endl << endl;
    cout << "Initiative Total: " << AttBonuses[1] << " Dex Bonus: " <<  AttBonuses[1] << endl << endl;
    cout << "Base Attack Bonus: " << charbonus[TOUGH][BAB] << endl << endl;
    cout << "Wealth Bonus: " << wealth << endl;
    cout << "Skill Points " << ((3 + AttBonuses[3])*4) << endl;
    break;

case 4:
    cout << "Your starting HP is: " << charbonus[SMART][HP] << endl;
    cout << "Your starting defense is: " << 10 + charbonus[SMART][DEF] + AttBonuses[1] << ".  Class Bonus: " << charbonus[SMART][DEF] << " Dex Modifier: " << AttBonuses[1] << endl << endl;
    cout << "Initiative Total: " << AttBonuses[1] << " Dex Bonus: " <<  AttBonuses[1] << endl << endl;
    cout << "Base Attack Bonus: " << charbonus[SMART][BAB] << endl << endl;
    cout << "Wealth Bonus: " << wealth << endl;
    cout << "Skill Points " << ((9 + AttBonuses[3])*4) << endl;
    break;
case 5:
    cout << "Your starting HP is: " << charbonus[DEDICATED][HP] << endl;
    cout << "Your starting defense is: " << 10 + charbonus[DEDICATED][DEF] + AttBonuses[1] << ".  Class Bonus: " << charbonus[DEDICATED][DEF] << " Dex Modifier: " << AttBonuses[1] << endl << endl;
    cout << "Initiative Total: " << AttBonuses[1] << " Dex Bonus: " <<  AttBonuses[1] << endl << endl;
    cout << "Base Attack Bonus: " << charbonus[DEDICATED][BAB] << endl << endl;
    cout << "Wealth Bonus: " << wealth << endl;
    cout << "Skill Points " << ((5 + AttBonuses[3])*4) << endl;
    break;
case 6:
    cout << "Your starting HP is: " << charbonus[CHAR][HP] << endl;
    cout << "Your starting defense is: " << 10 + charbonus[CHAR][DEF] + AttBonuses[1] << ".  Class Bonus: " << charbonus[CHAR][DEF] << " Dex Modifier: " << AttBonuses[1] << endl << endl;
    cout << "Initiative Total: " << AttBonuses[1] << " Dex Bonus: " <<  AttBonuses[1] << endl << endl;
    cout << "Base Attack Bonus: " << charbonus[CHAR][BAB] << endl << endl;
    cout << "Wealth Bonus: " << wealth << endl;
    cout << "Skill Points " << ((7 + AttBonuses[3])*4) << endl;
    break;
}
cout << endl;
char finish;
cout << "\nHit any letter to quit." << endl;
cin >> finish;

return 0;
}
