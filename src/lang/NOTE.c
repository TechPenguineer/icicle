/**
 * Copyright 2021 Tech Penguineer
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lang.h"

void SKIP_NOTE_LINE(char* str)
{
	char NOTE_TOKEN[] = "#";
	 int init_size = strlen(str);
	char delim[] = " ";

	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		ptr = strtok(NULL, delim);
		if (ptr == NOTE_TOKEN)
		{
			printf("COMMENT FOUND");
		}
		
	}

	/* This loop will show that there are zeroes in the str after tokenizing */
	for (int i = 0; i < init_size; i++)
	{
		char TOKEN = str[i];
		if (TOKEN==NOTE_TOKEN)
		{
			printf("COMMENT FOUND");
		}
			
	}
	printf("\n");

	return 0;
}