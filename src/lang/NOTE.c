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

void SKIP_NOTE_LINE(char* saux)
{
    char TOKEN_TO_SEARCH_FOR_NOTE[] = "#";

    int dlenstr = strlen(saux);

    if (dlenstr > 0)
{
    char *pfound = strstr(saux, TOKEN_TO_SEARCH_FOR_NOTE); 
    if (pfound != NULL)
    {
        int START_TOKEN_POS = pfound - saux; 
        printf("[%s] Token: %i\n",TOKEN_TO_SEARCH_FOR_NOTE,START_TOKEN_POS);
        return START_TOKEN_POS;
    }
}
}