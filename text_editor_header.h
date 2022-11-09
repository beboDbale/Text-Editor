#ifndef MAIN_CPP_TEXT_EDITOR_HEADER_H
#define MAIN_CPP_TEXT_EDITOR_HEADER_H

#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>

using namespace std;

//------------- Variables  -------------
fstream sourceFile;
char filename[100];
string choice;
vector<string> text;


//------------- Functions  -------------

string displayMenu();
void loadFile();
void addNewText();
void displayFileContent();
void emptyFile();
void encryptFile();
void decryptFile();
void NumberOfWords();
void NumberOfCharacters();
void searchForWord();
void MergeAnotherFile();
void countWord();
void convertToupper();
void convertTolower();
void firstCaps();
void saveFile();

#endif //MAIN_CPP_TEXT_EDITOR_HEADER_H