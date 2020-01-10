#include <string>
#include <checkUrl.h>
using namespace std;

int check_url(string url){
    
    const char* p = url.c_str();  
    void* ptr = (void*)curl_easy_init();
    CURLcode response;

    if(ptr) {
        curl_easy_setopt(ptr, CURLOPT_URL, p);

        /* don't write output to stdout */
        curl_easy_setopt(ptr, CURLOPT_NOBODY, 1);

        /* Perform the request */
        response = curl_easy_perform(ptr);

        /* always cleanup */
        curl_easy_cleanup(ptr);
    }

    return (response == CURLE_OK) ? 1 : 0;
}