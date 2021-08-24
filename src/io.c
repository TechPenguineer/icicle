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

#include "include/io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void GetFileData(char PATH[])
{

    #define CHUNK 1024
    char* buffer;
    int c;
    long length;
    char EXT[] = ".ici";

    strcat(PATH,EXT);
    
    FILE *file;
    file = fopen(PATH, "r");

    if (file)
    {
        fseek(file,0,SEEK_END);
        length = ftell(file);
        fseek(file,0,SEEK_CUR);

        buffer=calloc(length, sizeof(char));
        
        if(buffer)
        {
            fread(buffer, sizeof(char), length, file);
            printf("\n\n%s\n\n",buffer);
        }

        fclose(file);
    }
    else
    {
        printf("\033[1m\033[31mIcicle IO Error: File path \"%s\" not found\n",PATH);
    }
}