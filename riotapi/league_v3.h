/*******************************************************************************
  Title          : league_v3.h
  Author         : Matthew Li
  Created on     : October 7, 2017
  Description    : Interface for league_v3
  Purpose        : To provide a class that inherits the summoner_v3 class
                   and it contains the information of that summoner's league
  Modifications  : 

*******************************************************************************/

#ifndef LEAGUE_V3_H 
#define LEAGUE_V3_H


#include <curl/curl.h>
#include <string>
#include <iostream>

using namespace std;

/*******************************************************************************
                             LEAGUE_V3 INTERFACE
*******************************************************************************/

class League_v3 : public Summoner_v3
{
    private:
        string rank;      //I,II,III,IV,V
        string tier;      //Bronze, Silver, Gold, etc.
        string queueType; //RANKED_SOLO_5x5
    public: 
        /*Default Constructor*/
        League_v3();

        /* get_soloRank - returns rank;
         * precondition     - valid object
         * postcondition    - returns a string rank
         * */    
        string get_soloRank();

        /* get_soloTier - return tier;
         * precondition     - valid object
         * postcondition    - returns a string tier
         * */    
        string get_soloTier();

        /*prints private members*/            
        void print();

        /* league_v3_parser - Parse and store the data to private members
         * @param const string jsonstring [inout] - string in json format
         * precondition  - Assume the json string is in the correct format
         * postcondition - Stores the correct values into the private members
         * */
        void league_v3_parser(const string jsonstring);

};            

#endif 
