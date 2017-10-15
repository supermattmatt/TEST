/*******************************************************************************
  Title          : read_url.h
  Author         : Matthew Li
  Created on     : October 6, 2017
  Description    : Interface of methods for read_url
  Purpose        : To provide methods to read contents in URL
  Modifications  : 
*******************************************************************************/

#ifndef READ_URL_H 
#define READ_URL_H


#include <curl/curl.h>
#include <string>
#include <iostream>

using namespace std;

/*******************************************************************************
                            READ_URL INTERFACE
*******************************************************************************/

/** writeCallback()- function that is called by curl_easy_perform(curl)
 *                   this callback gets called by libcurl as soon as there is
 *                   data received that needs to be saved.
 *  @param void  *contents [in/out] pointer points to the delivered data 
 *  @param size_t size     [in]     size*nmemb = size of the data
 *  @param size_t nmemb    [in]     nmemb*size = size of the data
 *  @param void  *stream   [in/out] this argument is set with CURLOPT_WRITEDATA
 *  precondition  : Assume the function have the correct arguments 
 *  postcondition : return the size of the data 
 * */
size_t writeCallback(void  *contents, 
                     size_t size,
                     size_t nmemb,
                     void  *stream);

/** read() - function reads in a valid url and returns a string of data
 *  @param const string &url [inout] a valid url address
 *  precondition  : Assume the url is valid and writeCallback is functional
 *  postcondition : Return a string of data from the given url
 *  */
string read(const string &url);
   
#endif
