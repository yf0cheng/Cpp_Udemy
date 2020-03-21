/*
Section 19
Challenge 4
Copy Romeo and Juliet with line numbers

This challenge should be pretty easy.
I have provided the text to Romeo and Juliet in a file named romeoandjuliet.txt

For this challenge you have to make copy of the Romeo and Juliet file and save it to another file.
This new copy should have line numbers at the beginning of each line in the play.
Please format the numbers nicely so everything lines up.

Feel free to extend this challenge in any way you like.
For example, you may want to provide line numbers only for lines that actually have text

Have fun!
*/ 
#include <iostream>
#include <fstream>
#include <iomanip>

int main(){
    std::ifstream in_file {"../romeoandjuliet.txt"};
    std::ofstream out_file {"../romeoandjuliet_copy.txt"};
    if (!in_file){
        std::cout <<"fail to open input file" << std::endl;
        return 1;
    }
    if (!out_file){
        std::cout <<"fail to open output file" << std::endl;
        return 1;
    }
    std::string line {};
    int n_line {0};
    while(std::getline(in_file, line)){
        if ( line.find_first_not_of(" ")  != std::string::npos)
            out_file << std::setw(10) <<std::left << ++n_line << line << std::endl;
        else
            out_file << line << std::endl;
    }
    in_file.close();
    out_file.close();


    std::cout <<"finished copy file" << std::endl;
    return 0;
}