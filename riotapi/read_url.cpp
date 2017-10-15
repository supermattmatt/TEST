/*******************************************************************************
  Title          : read_url.cpp
  Author         : Matthew Li
  Created on     : October 6, 2017
  Description    : Implementation for read_url
  Purpose        : To provide a method to read contents in URL
  Build with     : Ubuntu/Linux 
  Modifications  : 

*******************************************************************************/

#include <curl/curl.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

/*******************************************************************************
                            READ_URL IMPLEMENTATION
*******************************************************************************/

/*callback function that is called by curl_easy_perform(curl)*/
size_t writeCallback(void  *contents, 
                     size_t size,
                     size_t nmemb,
                     void  *stream)
{   

    //append each char in contents into the stream, for that file size
    ((string *)stream)->append((char *)contents, size*nmemb);

    return size*nmemb;
}

string read(const string &url)
{   
    CURL* curl = curl_easy_init();
    
    string buffer;

    if(curl)
    {
        //Tell libcurl the URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        //Tell libcurl what function to call when it has data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

        //Reads URL and writes it in the address of the 3rd arg
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        CURLcode results = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(results != 0)
        {
            cerr <<"USAGE: read(const string &url "
                 <<"Error: " << results << endl;
        }
    }
    
    //the contents should be stored in the return string
    return buffer;
}
