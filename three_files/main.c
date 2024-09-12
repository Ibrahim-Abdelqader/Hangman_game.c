#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "project.h"

int main() {
    int attempts,timesRepeated,rightCharIndexs[4],spaces,userWordSize;
    bool charExist=false;
    char userChar,userOption; // (y/n)
    char randWord[20];
    char userWord[20];
    do
    {
        strcpy(randWord,getRandomWord());
        printf("%s\n",randWord);
        userWordSize=getWordSz(randWord);
        resetWord(userWord,userWordSize);
        attempts=8;      // set the attmepts
        spaces=true;    // set the spaces if the player play again

        while(attempts!=0 && spaces!=0)
            {
                printf("\n\t%s\n",userWord);
                printf("you have %i attempts.\n",attempts);
                printf("please write a char: ");
                scanf(" %c",&userChar);
                charExist= checkCharExist(randWord,userChar);
                if(charExist)
                    { 
                        timesRepeated=howMany(randWord,userChar);
                        getIndexes(randWord,timesRepeated,userChar,rightCharIndexs);
                        writeChars(userWord,userChar,rightCharIndexs,timesRepeated);
                    }    
                else
                    attempts--;
                spaces=checkSpaces(userWord);   
            }
        // check if user win?
        if(spaces==0) 
            {
                printf("\nYeah, It's %s\n",randWord);
                printf("Congratulations, you won!\n");
            }
           
        else
            {
                printf("\nyou lose!\n");
                printf("the word is : %s\n",randWord);
            }
            

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c",&userOption);
    } while (tolower(userOption)=='y');
    
    
return 0;    
}
