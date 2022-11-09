// FCI – Programming 1 – 2022 - Assignment 4
// Program Name: Text Editor.cpp
// Last Modification Date: 16/5/2022
// Author: Belal Ahmed Eid
// Purpose:This program allows user to load a file and choose option to apply on file

#include "text_editor_functions.cpp"



int main() {
    loadFile();
    // Main Loop
    while (true) {
        choice = displayMenu();

        if (choice == "1") {
            addNewText();
        } else if (choice == "2") {
            displayFileContent();
        } else if (choice == "3") {
            emptyFile();
        } else if (choice == "4") {
            encryptFile();
        } else if (choice == "5") {
            decryptFile();
        } else if (choice == "6") {
            MergeAnotherFile();
        } else if (choice == "7") {
            NumberOfWords();
        } else if (choice == "8") {
            NumberOfCharacters();
        } else if (choice == "9") {
            cout << "This file has " << text.size() << " lines\n";
        } else if (choice == "10") {
            searchForWord();
        } else if (choice == "11") {
            countWord();
        } else if (choice == "12") {
            convertToupper();
        } else if (choice == "13") {
            convertTolower();
        } else if (choice == "14") {
            firstCaps();
        } else if (choice == "15") {
            saveFile();
        } else if (choice == "16") {
            cout << "Thanks for using FCAI Text Editor" << endl;
            return 0;
        }
    }
}
