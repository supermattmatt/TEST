/*******************************************************************************
  Title          : summoner_v3.h
  Author         : Matthew Li
  Created on     : October 7, 2017
  Description    : Interface for summoner_v3
  Purpose        : To provide a class that represents the summoner
  Modifications  : 

*******************************************************************************/

#ifndef SUMMONER_V3_H 
#define SUMMONER_V3_H


#include <curl/curl.h>
#include <string>
#include <iostream>

using namespace std;

/*******************************************************************************
                            SUMMONER_V3 INTERFACE
*******************************************************************************/

class Summoner_v3
{
    private:
        long   id;           //summoner ID
        long   accountId;    //account ID
        string name;         //summoner name   
        long   profileIconId;//icon ID
        long   revisionDate; //date summoner was last modified
        long   summonerLevel;//summoner current level

        string error_message;
        bool exist;
    public: 
        /*Default Constructor*/
        Summoner_v3();

        /* set_summoner  - set the arguments into the private members
         * precondition  - valid object and argument types
         * postcondition - set the arguments to its corresponding members
         * */
        void set_summoner(long   id,           
                          long   accountId,    
                          string name,         
                          long   profileIconId,
                          long   revisionDate, 
                          long   summonerLevel);
        
        /* get_summonerName - returns summonerName;
         * precondition     - valid object
         * postcondition    - returns a string that is the summonerName
         * */    
        string get_summonerName();

        /* get_summonerId - returns summonerId;
         * precondition     - valid object
         * postcondition    - returns a string that is the summonerId
         * */    
        long get_summonerId();
        
        /* get_message - returns the error message and set exist to false*/
        string get_message();

        /* get_exist - returns the boolean variable exist */
        bool get_exist();

        /* print - prints out summoner's information
         * precondition - the object has valid private variables initialized
         * postcondtion - prints out the assumed valid private variables
         * */
        void print();

        /* summoner_v3_parser - Parse and store the data to private members
         * @param const string jsonstring [inout] - string in json format
         * precondition  - Assume the json string is in the correct format
         * postcondition - Stores the correct values into the private members
         * */
        void summoner_v3_parser(const string jsonstring);

};            

#endif 
