#include <iostream>
#include <cstring>
#include <curl/curl.h>


int main() 
{
  CURL *curl = curl_easy_init();
  if(curl) 
  {
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_NOBODY, true);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_URL, "https://google.com/");
    res = curl_easy_perform(curl);
    if(res == CURLE_OK) 
    {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      std::cout << "Responce code of https://google.com/ "<< response_code << '\n';
    }
    curl_easy_cleanup(curl);
  }
}