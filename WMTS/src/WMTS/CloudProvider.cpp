#include "CloudProvider.h"
#include <curl/curl.h>
#include <iostream>

CloudProvider::CloudProvider( const char* layer, int level, int x, int y, SingleBufNode *node) 
	: layer(layer), level(level), x(x), y(y), node(node)
{
}


CloudProvider::~CloudProvider(void)
{
}

void CloudProvider::process()
{
	getTile();
}

DataNode* CloudProvider::GetDataNode()
{
	return node;
}

void CloudProvider::getTile()
{
	char url[100];
	memset(url, 0, sizeof(url));
	sprintf_s(url, "http://t1.tianditu.com/DataServer?T=vec_c&x=%d&y=%d&l=%d", x, y, level);

	/*sprintf_s(url, "http://192.168.1.175:8080/GISManagement/getTile.do?LAYERS=%s&REQUEST=GetMap&WIDTH=%d&HEIGHT=%d&zoom=%d&row=%d&col=%d", 
		layer, width, height, level, y, x);*/
	CURL *curl_handle;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);
	/* init the curl session */ 
	curl_handle = curl_easy_init();
 
	/* specify URL to get */ 

	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
 
	/* send all data to this function  */ 
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
 
	/* we pass our 'chunk' struct to the callback function */ 
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)node);
 
	/* some servers don't like requests that are made without a user-agent
		field, so we provide one */ 
	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
 
	/* get it! */ 
	res = curl_easy_perform(curl_handle);
 
	/* check for errors */ 
	if(res != CURLE_OK) {
	fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));
	}
	else {
	/*
		* Now, our chunk.memory points to a memory block that is chunk.size
		* bytes big and contains the remote file.
		*
		* Do something nice with it!
		*/ 
		if(node->GetBuf() != NULL)
		{
#ifdef DEBUG
			char name[50];
			memset(name, 0, sizeof(name));
			sprintf_s(name, "F:\\temp\\%s#%d#%d.png", layer.c_str(), y, x);
			FILE *fout = fopen(name, "wb");
			fwrite(node->GetBuf(), node->GetLen(), 1, fout);
			fclose(fout);
#endif
		}
	}
 
	/* cleanup curl stuff */ 
	curl_easy_cleanup(curl_handle);
 
	/* we're done with libcurl, so clean it up */ 
	curl_global_cleanup();
}

size_t CloudProvider::WriteMemoryCallback( void *contents, size_t num, size_t nmemb, void * userp)
{
	size_t realsize = num * nmemb;
	SingleBufNode *node = (SingleBufNode *)userp;

	node->AllocateMem(realsize);
	if(node->GetBuf() == NULL) {
		/* out of memory! */ 
		std::cout << "not enough memory (realloc returned NULL)" << std::endl;
		return 0;
	}

	memcpy(node->GetBuf() + node->GetLen(), contents, realsize);
	node->SetLen(node->GetLen() + realsize);

	return realsize;
}
