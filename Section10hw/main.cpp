#include <iostream>
#include <string>
using namespace std;


int main(){
    string input_msg;
    cout <<"Input the message:" ;
    getline(cin,input_msg);
    for (size_t i{1}; i<=input_msg.length(); i++){
        string output_msg_space ( (input_msg.length()-i ) , ' ');
        string part_string {input_msg,0,i};
//        cout << part_string <<endl;
        string invert_part {};
        if (i>1){
            for (size_t j {i}; j>1;j--){
                invert_part += part_string.at(j-2);
            }
        }
//        cout << invert_part <<endl;
        string output_msg_full;
        output_msg_full = output_msg_space + part_string + invert_part;
        cout << output_msg_full << endl;
    }
    
    cout << endl;
    return 0;
}