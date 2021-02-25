/*
 * cache.h - cache functionalities for proxy server of SNU proxy lab
 * Author: Jiwong Ko
 * Email: jiwong@csap.snu.ac.kr
 */

#include <stdio.h>

#define MAX_OBJECT_SIZE 200000 // 200kB is maximum for one requests
#define MAX_CACHE_SIZE 1000000 // MAX CACHE SIZE should be 1MB
#define URI_SIZE 1024
#define RESP_SIZE 1024 

typedef struct cache_block{
   /* 
    * cache block needs to contain 
    * 1. URI (recommend to use key value)
    * 2. response header
    * 3. contents
    * 4. size of contents
    * 5. next pointer.
    */
   char uri[URI_SIZE];
   char response[RESP_SIZE];
   char content[MAX_OBJECT_SIZE];
   int contentLength;
   struct cache_block *next;
}cache_block;

/// cache function prototypes 
cache_block* find_cache_block(char* uri);
void cache_replacement_policy();
int add_cache_block(char* uri,char* content,char* response,int contentLength);

//header for linked list. it stores the total size of cache
//cache linkedlist starts after header
struct linkedlistcache{
	int totallength;
	cache_block *next;
}header;

