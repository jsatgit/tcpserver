#include "response.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HTML_SIZE 1000

char header[HTML_SIZE + 50] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
char html[HTML_SIZE];

char* 
response_header()
{
	return header;
}

static
void
load_html()
{
	memset(html, 0, sizeof(html));

	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("/tcpserver/receiver/html/page.html", "r");
	if (fp == NULL) {
		perror("Unable to open file.\n");
		return;
	}

	while((read = getline(&line, &len, fp)) != -1) {
		strcat(html, line);
	}	

	free(line);
	fclose(fp);
}

char*
response_create()
{
	load_html();
	return strcat(header, html);
}
