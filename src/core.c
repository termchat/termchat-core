#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <curl/curl.h> /* http request for api */

// Own
#include "core.h"

int GPTGetResponse(char *Request, char *Key, char *Buffer)
{
  CURL *curl;
  CURLcode res;

  char Authorization[strlen(Key)+25];
  sprintf(Authorization, "Authorization: Bearer %s", Key);

  char Json[strlen(Request)+20480];
  sprintf(Json, "{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"user\", \"content\": \"%s\"}], \"temperature\": 0.7}", Request);
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/chat/completions");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Headers
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charset: utf-8");
    headers = curl_slist_append(headers, Authorization);

    // Add headers
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Post
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, Json);
 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

        return 1;
    }
 
    /* always cleanup */
    curl_easy_cleanup(curl);

    return 0;
  }

  // Error
  return 1;
}