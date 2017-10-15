/*******************************************************************************
  Title          : summoner_v3.cpp
  Author         : Matthew Li
  Created on     : October 7, 2017
  Description    : Interface for summoner_v3
  Purpose        : To provide a class that represents the summoner
  Build with     : Ubuntu/Linux 
  Modifications  : 

*******************************************************************************/

#include <curl/curl.h>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

#include "summoner_v3.h"
using namespace std;

/*******************************************************************************
                           SUMMONER_V3 IMPLEMENTATION
*******************************************************************************/

/*Default Constructor*/
Summoner_v3::Summoner_v3()
    {
        exist = true;
    };

/*set given arguments to private member variables*/
void Summoner_v3::set_summoner(long   sum_id,           
                     long   acc_id,    
                     string sum_name,         
                     long   icon_id,
                     long   revision, 
                     long   sum_level)
    {
        id = sum_id;
        accountId = acc_id;
        name = sum_name;
        profileIconId = icon_id;
        revisionDate = revision;
        summonerLevel = sum_level;

    };

string Summoner_v3::get_summonerName()
    {
        return name;  
    };

long Summoner_v3::get_summonerId()
    {
        return id;  
    };

string Summoner_v3::get_message()
    {
        return error_message;
    };

bool Summoner_v3::get_exist()
    {
        return exist;
    };

void Summoner_v3::print()
    {
        cout << "Summoner ID: "     << id << endl
             << "Account ID: "      << accountId << endl
             << "Summoner Name: "   << name << endl
             << "Profile Icon ID: " << profileIconId << endl
             << "Revision Date: "   << revisionDate << endl
             << "Summoner Level: "  << summonerLevel << endl;
    };


/*Parse and stores summoner data to private members*/
void Summoner_v3::summoner_v3_parser(const string jsonstring)
    {
        /*parsing the json string buffer and store it in vector*/

        int pos = 0;
        int length = jsonstring.length();
        string type = "";
        vector<string> lib;

        for(pos; pos<length; ++pos)
        {    
            while(jsonstring[pos] == '{' ||
                  jsonstring[pos] == '}' ||
                  jsonstring[pos] == '"' ||
                  jsonstring[pos] == ':' ||
                  jsonstring[pos] == ',')
             {
                pos  = pos + 1;
             }


             for(pos; pos<length && jsonstring[pos] != '{' &&
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
            if(lib[i].compare("message")==0)
            {
                error_message = lib[i+1];
                exist = false;
            }

            if(i%2 == 0)
            {
               if(lib[i].compare("id")==0)
               {id = atol(lib[i+1].c_str());}

               else if(lib[i].compare("accountId")==0)
               {accountId = atol(lib[i+1].c_str());}

               else if(lib[i].compare("name")==0)
               {name = lib[i+1];}

               else if(lib[i].compare("profileIconId")==0)
               {profileIconId = atol(lib[i+1].c_str());}
                        
               else if(lib[i].compare("revisionDate")==0)
               {revisionDate = atol(lib[i+1].c_str());}

               else if(lib[i].compare("summonerLevel")==0)
               {summonerLevel = atol(lib[i+1].c_str());}
           
            } 

       }//end of forloop    

    };

