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
#include "include/tokens.h"



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
        fseek(file,0,SEEK_SET);

        buffer=calloc(length, sizeof(char));
        
        if(buffer)
        {
            fread(buffer, sizeof(char), length, file);
            GetFileStartToken(buffer);
            GetFileExitToken(buffer);
        }

        fclose(file);
        return buffer;
    }
    else
    {
        printf("\033[1m\033[31mIcicle IO Error: File path \"%s\" not found\n",PATH);
    }
}
int GetFileExitToken(char * saux)
{

    char TOKEN_TO_SEARCH_FOR_START[] = "$deff";
    char TOKEN_TO_SEARCH_FOR_END[] = "$endf";

    int dlenstr = strlen(saux);

    if (dlenstr > 0)
{
    char *pfound = strstr(saux, TOKEN_TO_SEARCH_FOR_END); 
    if (pfound != NULL)
    {
        int EXIT_TOKEN_POS = pfound - saux; 
        printf("Exit Token: %i\n", EXIT_TOKEN_POS);
        return EXIT_TOKEN_POS;
    }
    else if (pfound == NULL)
    {
        printf("\033[1m\033[31mIcicle Runtime Error: File exit was not found\n");
    }
    
}


}


int GetFileStartToken(char * saux)
{

    char TOKEN_TO_SEARCH_FOR_START[] = "$deff";
    char TOKEN_TO_SEARCH_FOR_END[] = "$endf";

    int dlenstr = strlen(saux);

    if (dlenstr > 0)
{
    char *sfound = strstr(saux, TOKEN_TO_SEARCH_FOR_END);
    char *pfound = strstr(saux, TOKEN_TO_SEARCH_FOR_START); 
    if (pfound != NULL)
    {
        int START_TOKEN_POS = pfound - saux; 
        printf("Definition Token: %i\n", START_TOKEN_POS);
        return START_TOKEN_POS;
    }
    else if (pfound == NULL)
    {
        printf("\033[1m\033[31mIcicle Runtime Error: File definition was not found\n");
    }
///    else if (sfound == NULL)
 //   {
 //        printf("\033[1m\033[31mIcicle Runtime Error: File exit was not found\n");
    
 //   }
    
}


}

void writeFile(char PATH[])
{
    char EXT[] = ".ici";
    char NEWFILEDATA[] = "# File was successfully created\n# Language written by: Tech Penguineer\n# REPO: https://github.com/TechPenguineer/icicle";
    strcat(PATH,EXT);
    FILE *f;
    if (!f)
    {
        f=fopen(PATH,"w");
        fprintf(f,NEWFILEDATA);
        printf("\033[0;32mSuccessfully created \"%s\"",PATH);
    }
    else if(f)
    {
        printf("\033[1m\033[31mIcicle IO Error: File path exists \"%s\"\n. If you wish to overwrite you can use the -ow flag. (NOT RECOMENDED)\n",PATH);
    }
}


void ForcewriteFile(char PATH[])
{
    char EXT[] = ".ici";
    char NEWFILEDATA[] = "# File was successfully created\n# Language written by: Tech Penguineer\n# REPO: https://github.com/TechPenguineer/icicle";
    strcat(PATH,EXT);
    FILE *f;
    if (!f)
   {
        f=fopen(PATH,"w");
        fprintf(f,NEWFILEDATA);
        printf("\033[0;32mSuccessfully created \"%s\". No data was lost.",PATH); 
    }
    else if (f)
    {
        printf("\033[1m\033[31mFile overwriten. File data has been lost.\n You are unable to restore the lost data due to using the overwrite flag\n",PATH);  
        f=fopen(PATH,"w");
        fprintf(f,NEWFILEDATA);
    }

   
}

