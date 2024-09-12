#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


const char* getRandomWord();
void resetWord(char word[],int sz);
void printWord(char word[]);
int checkSpaces(char word[]);
bool checkCharExist(char word[],char playerChar);
void writeChar(char word[],char rightChar,int index);
int getWordSz(char word[]);
int howMany(char word[],char userChar);
void getIndexes(char word[],int times,char userChar,int indexes[]);
void writeChars(char word[],char userChar,int indexes[],int times);



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
// "=================================================="

const char* getRandomWord() {
    const char* words[] = {
        "apple", "banana", "cat", "dog", "elephant",
        "fish", "grape", "hat", "ice", "jelly","ramy","ibrahim",
        "kite", "lion", "monkey", "notebook", "orange"
    };

    // Get the size of the array
    int wordCount = sizeof(words) / sizeof(words[0]);

    // Seed the random number generator
    srand(time(NULL));

    // Pick a random index
    int randomIndex = rand() % wordCount;

    // Return the word at the random index
    return words[randomIndex];

};
// "=================================================="
void resetWord(char word[],int sz) {
    for(int i=0;i<sz;i++)
        word[i]='-';  
    word[sz]='\0';
}   
// "=================================================="
void writeChars(char word[],char userChar,int indexes[],int times) {
    for(int i=0;i<times;i++)
        {
            word[indexes[i]]=userChar;
        }
}
// "=================================================="
int checkSpaces(char word[]) {
    int spaces=0;
    for(int i=0;word[i];i++)
        if(word[i]=='-') spaces++;
return spaces;
}
// "=================================================="
bool checkCharExist(char word[],char playerChar) {
    bool exist;
    for(int i=0;word[i];i++)
        {
            if(word[i]==playerChar)
                {

                    return true;
                }
        }
    // printf("it enter here\n");
    return false;
}
// "=================================================="
int howMany(char word[],char userChar) {
    int count=0;
        for(int i=0;word[i];i++)
            if(word[i]==userChar)
                count++;
    return count;            
}
// "=================================================="
int getWordSz(char word[]) {
    int wordsz=0;
    for(int i=0;word[i];i++) wordsz++;
    return wordsz;
}
void printWord(char word[]) {
    for(int i=0;word[i];i++)
        printf("%c",word[i]);
}
// "=================================================="

void getIndexes(char word[],int times,char userChar,int indexes[]) {
    for(int i=0;i<times;i++)
        for(int j=0;word[j];j++)
            if(word[j]==userChar)
                {
                    indexes[i]=j;
                    word[j]= toupper(word[j]);
                    break;
                }
    for(int i=0;i<times;i++)
        word[indexes[i]]=tolower(word[indexes[i]]);
}
