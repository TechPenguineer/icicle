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


void LoadPlayground(char LINE_POINTER[])
{
      char version[] = "0.0.0.1";
      char publisher[] = "Tech Penguineer";
      char line_pointer[] = "\033[34m=>\033[32m";
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

void LoadPrompt(char LOADING_ITEM[], char LOADING_TYPE[])
{
    char LOADING_STATUS="⌛";
    char COMPLETE_STATUS="✅";
    int LOADING_STATUS = 0;
    char * LOADING_STATUS_VIEW = LOADING_STATUS;
    
    printf("[%c] %s %s...\n", LOADING_STATUS_VIEW,LOADING_TYPE,LOADING_ITEM);
}

int main(int argc, char* argv[])
{

  if(argc==1)
  {
     
      LoadPrompt("PLAYGROUND","INITALIZING");
  }
  return 0;  
}