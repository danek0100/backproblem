#include "header.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 255




int main(int argc, char* argv[])
{
	FILE* fr = fopen(argv[1], "rb");
	if (!fr)
		return;
	fseek(fr, 0L, SEEK_END);
	long length = ftell(fr);
	fseek(fr, 0, SEEK_SET);

	unsigned char* res;
	res = (unsigned char*)malloc(sizeof(unsigned char) * (length + 1));
	for (int i = 0; i < length; i++)
	{
		res[i] = fgetc(fr);
	}
	res[length] = '\0';
	fclose(fr);

	char* cstr = strtok(res, " ,.-\n\r\t");
	

	int k = 0;
	int nump = 0;
	int m = k;
	while ((res[m] != ' ') && (res[m] >= '0') && (res[m] <= '9') && (m < length))
		m++;
	m = m - k;
	int s = 1;
	for (int i = 0; i < m - 1; i++)
		s *= 10;
	for (int i = k; i < k + m; i++)
	{
		nump += (res[i] - '0') * s;
		s /= 10;
	}


	k = k + m + 1;
	int maxw = 0;
	m = k;
	while ((res[m] != ' ') && (res[m] >= '0') && (res[m] <= '9') && (m < length))
		m++;
	m = m - k;
	s = 1;
	for (int i = 0; i < m - 1; i++)
		s *= 10;
	for (int i = k; i < k + m; i++)
	{
		maxw += (res[i] - '0') * s;
		s /= 10;
	}

	int* array = (int*)calloc(nump * 2, sizeof(int));

	cstr = strtok(NULL, " ,.-\n\r\t");
	cstr = strtok(NULL, " ,.-\n\r\t");

	int i = 0;
	while (cstr != 0)
	{
		int len = strlen(cstr);
		int s = 1;
		for (int j = 0; j < len - 1; j++)
			s *= 10;
		for (int j = 0; j < len; j++)
		{
			array[i] += (cstr[j] - '0') * s;
			s /= 10;
		}
		i++;
		cstr = strtok(NULL, " ,.-\n\r\t");
	}

	for (int i = 0; i < nump * 2; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}