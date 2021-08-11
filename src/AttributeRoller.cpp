#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

enum att {HP, BAB, FORT, REF, WILL, DEF, REP, SKLL_PTS, ATT_NUM};
enum classes {STRONG, FAST, TOUGH, SMART, DEDICATED, CHAR, CLASS_NUM};

int charbonus[CLASS_NUM][ATT_NUM] =
{

    {8,1,1,0,0,1,0,3},
    {8,0,0,1,0,3,0,5},
    {10,0,1,0,0,1,0,3},
    {6,0,0,0,1,0,1,9},
    {6,0,1,0,1,1,1,5},
    {6,0,1,1,0,0,2,7},
};


const int ATTCAP = 6;  //The number of attributes a character posesses.
string AttNames[ATTCAP] = {"Strength","Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma" };  //The names of those attributes.
int AttBonuses[ATTCAP];  //Bonuses for each attribute

int wealth = ((rand () % 4) + 1) * 2;

void displayStats(int classpick) {
    cout << "Your starting HP is: " << charbonus[classpick][HP] << endl;
    cout << "Your starting defense is: " << 10 + charbonus[classpick][DEF] + AttBonuses[1] << ".  Class Bonus: " << charbonus[classpick][DEF] << " Dex Modifier: " << AttBonuses[1] << endl << endl;
    cout << "Initiative Total: " << AttBonuses[1] << " Dex Bonus: " <<  AttBonuses[1] << endl << endl;
    cout << "Base Attack Bonus: " << charbonus[classpick][BAB] << endl << endl;
    cout << "Wealth Bonus: " << wealth << endl;
    cout << "Skill Points " << ((charbonus[classpick][SKLL_PTS] + AttBonuses[3])*4) << endl;
}

int main ()
{

cout << "Welcome to the DnD random character generator.\n\n";

srand (time(NULL));
//Current Arrays are Attbonuses, AttributeMax (The value of the attribute), and AttNames.


float AttributeMax[ATTCAP];
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
for (int i = 0; i < ATTCAP; i++)
{
    cout << AttNames[i] << ":  \t" << AttributeMax[i];
    float attValue = floor((AttributeMax[i] - 10) / 2);
    if (AttributeMax[i] >= 12 ? cout << "\t+" << attValue << " ability modifier" : cout << "\t" << attValue << " ability modifier");
    AttBonuses[i] = attValue;
    cout << endl;
}

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

displayStats (myNumber - 1);

cout << endl;
char finish;
cout << "\nHit any letter to quit." << endl;
cin >> finish;

return 0;
}
