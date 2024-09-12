#ifndef PROJECT_H
#define PROJCET_H

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

#endif