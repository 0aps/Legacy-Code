#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <curl/curl.h>

void print_help()
{
	printf("usage: ./main.bin -g http://...\n");
}

void get_page(char *url)
{
	CURL *curl = curl_easy_init();
	FILE *fp = fopen("index.xhtml", "w");
	double fsize;
	
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	curl_easy_perform(curl);
	
	curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &fsize);
	curl_easy_perform(curl);
	
	printf("size: %d bytes\n", (int)fsize);

	curl_easy_cleanup(curl);
	fclose(fp);
}

int main(int argc, char *argv[])
{
	int next_option;
	const char *short_options = "hg:";
	const struct option long_options[] =
	{
		{ "help",  0, NULL, 'h' },
		{ "get",   1, NULL, 'g' },
		{ NULL,	   0, NULL,  0  }
	};
	
	do
	{
		next_option = getopt_long(argc, argv, short_options,
					  long_options, NULL);
		switch(next_option)
		{
			case 'h': print_help();	break;
			case 'g': get_page(optarg);	break;
			case '?': perror("Invalid argument\n"); break;
			case  -1: break;
			default: abort();
		}
	} while (next_option != -1);
	
	return 0;
}
