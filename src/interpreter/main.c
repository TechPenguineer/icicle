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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/io.h"

int IsInDevMode=0;
char version[] = "0.0.0.1";
char publisher[] = "Tech Penguineer";
char line_pointer[] = "\033[34m=>\033[32m";
void LoadPlayground(char LINE_POINTER[])
{

      printf("\033[1m\033[36m\n\n$$$$$$\\  $$$$$$\\  $$$$$$\\  $$$$$$\\  $$\\       $$$$$$$$\\ \n");
      printf("\\_$$  _|$$  __$$\\ \\_$$  _|$$  __$$\\ $$ |      $$  _____|\n");
      printf("  $$ |  $$ /  \\__|  $$ |  $$ /  \\__|$$ |      $$ |      \n");
      printf("  $$ |  $$ |        $$ |  $$ |      $$ |      $$$$$\\    \n");
      printf("  $$ |  $$ |        $$ |  $$ |      $$ |      $$  __|   \n");
      printf("  $$ |  $$ |  $$\\   $$ |  $$ |  $$\\ $$ |      $$ |      \n");
      printf("$$$$$$\\ \\$$$$$$  |$$$$$$\\ \\$$$$$$  |$$$$$$$$\\ $$$$$$$$\\ \n");
      printf("\\______| \\______/ \\______| \\______/ \\________|\\________|\n");
      printf("\n\n\033[1m\033[32mVersion: %s\n\033[1m\033[31mMade by: %s\n\n", version, publisher);
}

void Data()
{
    if (IsInDevMode==0)
    {
        printf("Icicle: You must be in dev mode to do that!\n");
    }
    else if(IsInDevMode==1)
    {
        printf("Version: %s\nPublisher: %s\nRelease Date: 8/23/2021\nDeveloper mode permission level: %i",version,publisher,IsInDevMode);
    }
    
}
void DevMode(int DevmodeVAL, int DevVAL)
{
    IsInDevMode=DevVAL;
}

void LoadPrompt(char LOADING_ITEM[], char LOADING_TYPE[])
{
    char LOADING_STATUS_EMJ[]="⌛";
    char COMPLETE_STATUS_EMJ[] ="✅";
    char FAILED_STATUS_EMJ[] = "❌";
    int LOADING_STATUS = 0;
}

int main(int argc, char* argv[])
{

  if(argc==1)
  { 
      LoadPlayground(line_pointer);
  }

  if (strcmp(argv[1], "devmode")==0 && strcmp(argv[2],"enable")==0)
  {
      printf("Toggling Developer Mode\n");
      DevMode(IsInDevMode,1);
  }

  if (strcmp(argv[1], "devmode")==0 && strcmp(argv[2],"unenable")==0)
  {
      printf("Untoggling Developer Mode\n");
      DevMode(IsInDevMode,0);
  }

  if (strcmp(argv[1], "data")==0)
  {
      Data();
  }

if (strcmp(argv[1], "dev")==0 &&strcmp(argv[2], "reader")==0 && strcmp(argv[3], "-p")==0)
  {
      GetFileData(argv[4]);
  }

if (strcmp(argv[1], "sys")==0 &&strcmp(argv[2], "write")==0)
  {
      writeFile(argv[3]);
  }

if (strcmp(argv[1], "sys")==0 &&strcmp(argv[2], "-ow")==0&&strcmp(argv[3], "write")==0)
  {
      ForcewriteFile(argv[4]);
  }

  
  return 0;  
}