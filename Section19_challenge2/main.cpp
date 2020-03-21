/*
Section 19
Challenge 2
Automated Grader

Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
as well as student responses for the quiz.

The answer key is the first item in the file.
Student1 name
Student1 responses
Student2 name
Student2 responses
. . .

Here is a sample file.

ABCDE                  
Frank                     
ABCDE                  
Larry
ABCAC
Moe
BBCDE
Curly
BBAAE
Michael
BBCDE

You should read the file and display:
Each student's name and score (#correct out of 5)
At the end, the class average should be displayed
You may assume that the data in the file is properly formatted

Program should output to the console the following:
Student                     Score 
----------------------------
Frank                             5
Larry                              3
Moe                              4
Curly                             2
Michael                         4
---------------------------
Average score            3.6

*/ 
// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>

#include <string>
#include <vector>
#include <numeric>


//using namespace std;

int main() {
    std::ifstream in_file {"../responses.txt"};
    if (!in_file){
        std::cout << "Cannot open file"<<std::endl;
    }else{
        std::string string;
        std::string answer;
        std::string name;
        std::vector<int> score_v;
        int w_n {20};
        
        std::cout<<std::setw(w_n)<<std::left<<"Student"<<"Score"<<std::endl;
        std::cout<<std::setw(30)<<std::setfill('-')<< std::right << "" << std::endl;
        std::cout<< std::setfill(' ');//rest

        in_file >> answer;
        while(in_file >> name >> string){
            int score {0};
            for(size_t i = 0; i<string.size(); i++){
                if (string[i] == answer[i])
                    score++;
            }
            score_v.push_back(score);
            std::cout<<std::setw(w_n)<<std::left<<name<<score<<std::endl;
        }
        in_file.close();
        std::cout<<std::setw(30)<<std::setfill('-')<< std::right << "" <<std::setfill(' ')<< std::endl;
        float average = std::accumulate( score_v.begin(), score_v.end(), 0.0)/score_v.size();     
        std::cout<<std::setw(w_n)<<std::left<<"Average Score"<<average<<std::endl;
        
    }
//    cout << "Hello world" << endl;
    return 0;
}

