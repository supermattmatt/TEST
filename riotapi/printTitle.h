/*******************************************************************************
  Title          : printTitle.h
  Author         : Matthew Li
  Created on     : October 14, 2017
  Description    : Interface for printTitle
  Purpose        : To provide methods to print out a title
  Modifications  : 

*******************************************************************************/

#ifndef PRINTTITLE_H 
#define PRINTTITLE_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

/*******************************************************************************
                             PRINTTITLE INTERFACE
*******************************************************************************/

/* title - returns a random sentence or title
 * @param string tier [in] - a constant string 
 * precondition  - the ifstream for 'nouns' is able to open to retrieve words
 *                 and the tier is either BRONZE/SILVER/GOLD/ etc.
 * postcondition - returns a random sentence or title
 * */
string get_title(const string tier);

/* makeUpperCase - returns an upper case version of the string
 * @param string s [inout] - a string passed by reference
 * precondition  - pass in a vaild string by reference
 * postcondition - returns the all uppercase string
 * */
void makeUpperCase(string &s);

#endif
