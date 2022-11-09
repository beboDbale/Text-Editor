#include "text_editor_header.h"


string displayMenu() {
    // Set of strings user should input
    set<string> inputs = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};
    string option;
    cout << "-------------------------------------------------" << endl;
    cout << "Please select an option to apply or 16 to exit: " << endl;
    cout << "1- Add new text to the end of the file\n2- Display the content of the file\n"
            "3- Empty the file\n4- Encrypt the file content \n5- Decrypt the file content\n"
            "6- Merge another file\n7- Count the number of words in the file\n"
            "8- Count the number of characters in the file\n9- Count the number of lines in the file\n"
            "10- Search for a word in the file\n11- Count the number of times a word exists in the file\n"
            "12- Turn the file content to upper case\n13- Turn the file content to lower case\n"
            "14- Turn file content to 1st caps(1st char of each word is capital)\n15- Save\n16- Exit" << endl;
    cin >> option;
    // Check if input is valid or not
    while (!inputs.count(option) || cin.fail()) {
        cout << "Invalid input. Please select a choice from [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]: ";
        cin.clear();
        cin.sync();
        cin >> option;
    }
    return option;
}

void loadFile() {
    string line;
    cout << "Enter filename you want to deal with: ";
    cin >> filename;
    strcat(filename, ".txt");
    // open file in read mode
    sourceFile.open(filename, ios::in);
    // check if file exists or not ( if not create new file)
    if (sourceFile) {
        cout << "This File Already Exits" << endl;
        // store file content in vector of strings
        while (!sourceFile.eof()) {
            getline(sourceFile, line, '\n');
            text.push_back(line);
        }
    } else {
        cout << "This is a new file. I created it for you" << endl;
        sourceFile.open(filename, ios::out);
    }
    sourceFile.close();
}

void addNewText() {
    // open file in append mode
    sourceFile.open(filename, ios::app);
    cout << "Enter text you want to add to this file: " << endl;
    sourceFile << "\n";
    text.push_back("\n");
    // take the text user want to add until user press (ctrl+z)
    string newText;
    while (getline(cin, newText)) {
        sourceFile << newText;
    }
    sourceFile.close();
    text.clear();

    // open file in read mode to copy the new content to the vector
    sourceFile.open(filename, ios::in);
    string line;
    // loop through each line in file and add it as element in vector
    while (!sourceFile.eof()) {
        getline(sourceFile, line, '\n');
        text.push_back(line);
    }

    sourceFile.close();
}

void displayFileContent() {
    // loop through each element (line of the text) in vector and print it
    for (string line: text) {
        cout << line << endl;
    }
}

void emptyFile() {
    // delete file contents
    sourceFile.open(filename, ios::out | ios::trunc);
    sourceFile.close();
    // delete the copy of text in vector
    text.clear();
    cout << "File is empty !" << endl;
}

void encryptFile() {
    // encrypt the copy of text in vector
    for (int i = 0; i < text.size(); ++i) {
        for (int j = 0; j < text[i].size(); ++j) {
            text[i][j] = char(text[i][j] + 1);
        }
    }
    // open file in write mode and copy vector text to the file after encryption
    sourceFile.open(filename, ios::out);
    for (string line: text) {
        sourceFile << line << endl;
    }
    sourceFile.close();
    cout << "File encrypted" << endl;
}

void decryptFile() {
    // decrypt the copy of text in vector
    for (int i = 0; i < text.size(); ++i) {
        for (int j = 0; j < text[i].size(); ++j) {
            text[i][j] = char(text[i][j] - 1);
        }
    }
    // open file in write mode and copy vector text to the file after decryption
    sourceFile.open(filename, ios::out);
    for (string line: text) {
        sourceFile << line << endl;
    }
    sourceFile.close();
    cout << "File Decrypted !" << endl;
}

void NumberOfWords() {
    int count = 0;
    //looping over the whole words
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < text[i].size(); j++) {
            // if the word is not space or after it space increase the counter
            if (text[i][j] != ' ' && text[1][j + 1] == ' ')
                count++;
            else
                // if not continue program
                continue;
        }
    }
    cout << "This file has " << count + text.size() << " words\n";
}

void NumberOfCharacters() {
    int count = 0;
    //to loop over the whole characters in the file
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < text[i].size(); j++) {
            count++;
        }
    }
    //printing the number of characters
    cout << "This file has " << count << " character\n";

}

void searchForWord() {
    string word;
    string word2;
    bool found = false;
    cout << "Enter word you want to search for : " << endl;
    cin >> word;
    sourceFile.open(filename, ios::in);
    for (int i = 0; i < word.size(); ++i) {
        word[i] = tolower(word[i]);
    }
    while (sourceFile >> word2) {
        for (int i = 0; i < word2.size(); ++i) {
            word2[i] = tolower(word2[i]);
        }
        if (word2 == word) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Word is found in file (:" << endl;
    } else {
        cout << "Word is not found file ): " << endl;
    }
    sourceFile.close();
}

void MergeAnotherFile() {
    fstream mergeFile;
    char Mergename[100];
    string line;
    cout << "Enter filename you want to merge: ";
    cin >> Mergename;
    strcat(Mergename, ".txt");
    //if the file is not found we enter the correct name
    while (!mergeFile) {
        cout << "Invalid File Name. Choose valid one\n";
        cin >> Mergename;
        strcat(Mergename, ".txt");
    }
    cout << "This File Already Exits" << endl;
    //opening  main file in append mode &  merge file in read mode
    sourceFile.open(filename, ios::app);
    mergeFile.open(Mergename, ios::in);
    sourceFile << endl;
    //add contents in the same file
    while (getline(mergeFile, line)) {
        sourceFile << line;
        text.push_back(line);
        sourceFile << endl;
    }
    sourceFile.close();
    mergeFile.close();
    cout << "done\n";
}

void countWord() {
    sourceFile.open(filename, ios::in);
    int times = -1;
    char word2;
    //to recieve the word from the user
    cout << "Enter the word you want to count: \n";
    cin >> word2;
    //to loop over the whole words
    for (int i = 0; i < text.size(); ++i) {
        for (int j = 0; j < text[i].size(); ++j) {
            // reding each word
            sourceFile << text[i][j];
            //comparing the word from user by each word
            if (toupper(word2) == toupper(text[i][j])) {
                //if the word is the same increase the counter
                times++;
            }
        }
    }
    cout << "The word is repeated for " << times << " times." << endl;
    cin.clear();
    cin.sync();
    sourceFile.clear();
    sourceFile.close();
}

void convertToupper() {
    //to loop over the whole lines
    for (int i = 0; i < text.size(); i++) {
        //to loop over the whole words
        for (int j = 0; j < text[i].size(); j++) {
            //if word = space don't do any thing
            if (text[i][j] == ' ') {
                text[i][j] = text[i][j];
            }
                // if it was a word convert it to uppercase
            else {
                text[i][j] = toupper(text[i][j]);
            }
        }
    }
    // open file in write mode and write each line in the file
    sourceFile.open(filename, ios::out);
    for (string line: text) {
        sourceFile << line << endl;
    }
    sourceFile.close();
}

void convertTolower() {
    //to loop over the whole lines
    for (int i = 0; i < text.size(); i++) {
        //to loop over the whole words
        for (int j = 0; j < text[i].size(); j++) {
            text[i][j] = tolower(text[i][j]);
        }
    }
    // open file in write mode and write each line in the file
    sourceFile.open(filename, ios::out);
    for (string line: text) {
        sourceFile << line << endl;
    }
    sourceFile.close();
}

void firstCaps() {
    //to loop over the whole lines
    for (int i = 0; i < text.size(); i++) {
        //to loop over the whole words
        for (int j = 0; j < text[i].size(); j++) {
            // if it is the first character in the  file or the first in a line
            // or it after space convert the charcter to upper case
            if (j == 0 || text[i][j - 1] == '\n' || text[i][j - 1] == ' ') {
                text[i][j] = toupper(text[i][j]);
                //else make it in a lower case
            } else {
                text[i][j] = tolower(text[i][j]);
            }
        }
    }
    sourceFile.open(filename, ios::out);
    for (string line: text) {
        sourceFile << line << endl;
    }
    sourceFile.close();
}

void saveFile() {
    char newFile[100];
    int command;
    //to save in the same file or under a different name
    cout
            << "Enter \n 1- to save the file content in the same file \n 2- to save the file content under different name: \n";
    cin >> command;
    // if saving under a different name
    if (command == 2) {
        // take the name from user and rename the file
        cout << "Enter new filename: ";
        cin >> newFile;
        strcat(newFile, ".txt");
        rename(filename, newFile);
    }
}