/*******************************************************************************
  Title          : main.cpp
  Author         : Matthew Li
  Created on     : October 15, 2017
  Description    : Main Program takes in a NA Summoner Name in the command line
  Purpose        : To print out a random "title" based on a summoner's tier/rank
  Build on       : Ubuntu/Linux 
  Modifications  : 

*******************************************************************************/
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <iostream>

#include "read_url.h"
#include "summoner_v3.h"
#include "league_v3.h"
#include "printTitle.h"

using namespace std;

/*******************************************************************************
                             MAIN PROGRAM 
*******************************************************************************/
int main(int argc, char *argv[])
{   
    if(argc < 2){
        cerr << "Please enter your <NA Summoner Name>\n";
        exit(1);
    }

    string api = "";

    string summonerName = argv[1];
    
    /*url to get summoner information*/
    string summonerv3_url = "https://na1.api.riotgames.com/lol/summoner/v3/summoners/by-name/"
                            + summonerName + "?api_key=" + api;

    /*get json data from url and return it as a string*/
    string summonerInfo = read(summonerv3_url);
    
    //cout << summonerInfo << endl;
    //cout << "*******************************************************************\n"; 

    Summoner_v3 X;
    X.summoner_v3_parser(summonerInfo); //stores data in the object
    //X.print();
    
    /*check if summoner exist or not*/
    if(X.get_exist() == false){
        cerr<< X.get_message() << " Please enter valid NA Summoner Name\n";
        exit(1);
    }

    /*convert long id to a string*/
    long id = X.get_summonerId();
    stringstream ss;
    ss << id;
    string summonerId = ss.str();
    
    /*url to get league information*/
    string leaguev3_url = "https://na1.api.riotgames.com/lol/league/v3/positions/by-summoner/"
                           + summonerId + "?api_key=" + api;
    
    /*get json data from url and return it as a string*/
    string leagueInfo = read(leaguev3_url);

    //cout << leagueInfo << endl;
    //cout << "*******************************************************************\n"; 

    League_v3 Y;
    Y.league_v3_parser(leagueInfo); //stores data in the object
    //Y.print();
    string tier = Y.get_soloTier();
    string title = X.get_summonerName() + " (" + Y.get_soloTier() + " " + Y.get_soloRank() 
                   + ")" + ", " + get_title(tier);
    
    cout << title << endl;
    return 0;
}


