/*
Section 19
Challenge 3
Word finder

Ask the user to enter a word
Process the Romeo and Juliet file and determine how many total words there are
and how many times the word the user entered appears as a substring of a word in the play.

For example.
If the user enters: love
Then the words love, lovely, and beloved will all be considered matches.
You decide whether you want to be case sensitive or not. My solution is case sensitive

Sample are some sample runs:

Enter the substring to search for: love
25919 words were searched...
The substring love was found 171 times

Enter the substring to search for: Romeo
25919 words were searched...
The substring Romeo was found 132 times

Enter the substring to search for: Juliet
25919 words were searched...
The substring Juliet was found 49 times

Enter the substring to search for: Frank
25919 words were searched...
The substring Frank was found 0 times

Have fun!
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
    ifstream in_file {"../romeoandjuliet.txt"};
    if (!in_file){
        cerr << "problem to open file" << endl;
        return 1;
    }
    string targetword;
    cout << "input the word you want to search : ";
    cin >> targetword;
    int totalwords {0};
    int findwords {0};
    string textword;
    while (in_file >> textword){
        totalwords++;
        if (textword.find(targetword) != string::npos)
            findwords ++;
    }
    in_file.close();
    cout << "found " << findwords << " " << targetword << " in " << totalwords << " words." <<endl;
//    std::cout <<"Hello World" << std::endl;
    return 0;
}