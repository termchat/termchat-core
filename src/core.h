/*!
 * \file
 * \brief Core communication tool for bilateral connection between AI server API and client
 * \author @ZhengLinLei
 * \copyright YEAR: 2023 LICENSE: Mozilla Public License Version 2.0
 * 
 *
 * Core communication tool for bilateral connection between AI server API and client
*/

#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#define PORT        80
#define PROTOCOL    "http"
#define HOST        "api.openai.com"
#define VERSION     "v1"
#define CHAT_URL    '/v1/chat/completions'


#endif


int GPTGetResponse(char *Request, char *Key, char *Buffer);