/*******************************************************************************
  Title          : league_v3.cpp
  Author         : Matthew Li
  Created on     : October 7, 2017
  Description    : Implementation for league_v3
  Purpose        : To provide a class that inherits the summoner_v3 class
                   and it contains the information of that summoner's league
  Build with     : Ubuntu/Linux 
  Modifications  : 

*******************************************************************************/

#include <curl/curl.h>
#include <string>
#include <vector>
#include <iostream>

#include "read_url.h"
#include "summoner_v3.h"
#include "league_v3.h"

using namespace std;

/*******************************************************************************
                            LEAGUE_V3 IMPLEMENTATION
*******************************************************************************/

/*Default Constructor*/
League_v3::League_v3(){/*BLANK*/};

void League_v3::league_v3_parser(const string jsonstring)
    {
        /*parsing the json string buffer and store it in vector*/

        int pos = 0;
        int length = jsonstring.length();
        string type = "";
        vector<string> lib;

        for(pos; pos<length; ++pos)
        {    
            while(jsonstring[pos] == '[' ||
                  jsonstring[pos] == ']' ||
                  jsonstring[pos] == '{' ||
                  jsonstring[pos] == '}' ||
                  jsonstring[pos] == '"' ||
                  jsonstring[pos] == ':' ||
                  jsonstring[pos] == ',')
             {
                pos  = pos + 1;
             }


             for(pos; pos<length && jsonstring[pos] != '[' &&
                                    jsonstring[pos] != ']' &&
                                    jsonstring[pos] != '{' &&
                                    jsonstring[pos] != '}' &&
                                    jsonstring[pos] != '"' && 
                                    jsonstring[pos] != ':' &&
                                    jsonstring[pos] != ','; ++pos)
             {
                type = type + jsonstring[pos];
             }
                
             lib.push_back(type);
             type = "";

        }//end of forloop   
        

       /*all the odd indexes in lib are the value*/

       for(int i=0; i<lib.size(); ++i)
       {    
            if(i%2 == 0)
            { 
               if(lib[i].compare("tier")==0)
               {tier = lib[i+1];}

               else if(lib[i].compare("queueType")==0)
               {queueType = lib[i+1];}

               else if(lib[i].compare("rank")==0)
               {
                   rank = lib[i+1];
                   break;
               }

            } 

       }//end of forloop    

    };

void League_v3::print()
    {
        cout << "tier: " << tier << endl
             << "rank: " << rank << endl
             << "queueType: " << queueType << endl;   
    };

string League_v3::get_soloRank()
    {
        return rank;
    };

string League_v3::get_soloTier()
    {
        return tier;
    };
