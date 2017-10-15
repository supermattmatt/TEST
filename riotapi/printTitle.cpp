/*******************************************************************************
  Title          : printTitle.cpp
  Author         : Matthew Li
  Created on     : October 14, 2017
  Description    : Implementation for printTitle
  Purpose        : To provide definitions for the methods to print out a title
  Build with     : Ubuntu/Linux  
  Modifications  : 

*******************************************************************************/
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "printTitle.h"

using namespace std;

/*******************************************************************************
                            PRINTTITLE IMPLEMENTATION
*******************************************************************************/

string get_title(const string tier)
{
    string s;
    vector<string> library;    
    ifstream in;
    in.open("nouns");
    if(in.fail()){
        cerr << "Failed to open file 'nouns' \n";
        exit(1);
    }

    else if(!in.fail()){
        while(getline(in, s)){
            library.push_back(s);
        }
    }

    in.close();
    
    srand( time(NULL)); //seed the RNG 
    int randomIndex = (rand() % library.size()) +1; //get a random number in [1,100]
    string randomNoun = library[randomIndex];

    string status = "";

    if(tier.compare("BRONZE") == 0){
        status = "BRONZE CLIMBING";     
    }

    else if(tier.compare("SILVER") == 0){
        status = "SILVER SURFING";
    }

    else if(tier.compare("GOLD") == 0){
        status = "GOLDEN";
    }

    else if(tier.compare("") == 0){
        status = "UNRANKED-WOOD-V";
    }
    else{
        status = tier;
    }

    string title = "THE " + status + " " + randomNoun + "!";

    makeUpperCase(title);

    return title;

};//end of title function

void makeUpperCase(string &s)
{
    for(int i=0; i<s.length(); ++i){
        if(s[i] >= 'a' && s[i] <='z'){
            s[i] = (char) ((int) s[i] - 32);
        }
    }
};//end of makeUpperCase

