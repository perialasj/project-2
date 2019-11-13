#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string; 
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;  
#include <algorithm>
using std::sort; 

//vector<string>
void password_similars(string inputPassowrd){
    vector<string> outputVect; 
    int difference_count = 1000; 
    int temp_diff_count = 0; 
    string filePassword; 

    ifstream inputFile("common_passwords.txt");
    while(!inputFile.eof()){
        inputFile >> filePassword;
        int file_pass_size = filePassword.size()-1;
        int input_pass_size = inputPassowrd.size()-1;
        int i; 
        if (input_pass_size > file_pass_size){
            for(i=0; i <= file_pass_size; i++){
                if(inputPassowrd[i]!=filePassword[i]) {
                    temp_diff_count += 1; 
                }
    
            }
            temp_diff_count += (input_pass_size - file_pass_size);
            
            if(temp_diff_count < difference_count){
                outputVect.clear();
                outputVect.push_back(filePassword);
                difference_count = temp_diff_count;
            }
            else if(temp_diff_count == difference_count){
                outputVect.push_back(filePassword);
            }
            temp_diff_count = 0;
        }   

        else if (input_pass_size <= file_pass_size) {
            for(i=0; i <= input_pass_size; i++){
                
                if(inputPassowrd[i]!=filePassword[i]) {
                    temp_diff_count += 1; 
                }
            }
            temp_diff_count += (file_pass_size - input_pass_size);

            if(temp_diff_count < difference_count){
                outputVect.clear();
                outputVect.push_back(filePassword);
                difference_count = temp_diff_count;
            }
            else if(temp_diff_count == difference_count){
                outputVect.push_back(filePassword);
            }
            temp_diff_count = 0;
        }
        
         
    }
    //vect check
    int vectsize = outputVect.size();
    int j;
    sort(outputVect.begin(), outputVect.end());
    for (j=0; j < vectsize; j++){
        cout << outputVect[j] << ", "; 
    }
    cout << endl;
    cout << "All of which are " << difference_count << "  character(s) different." << endl;

}

int main(){
    string inputPassword;
    cout << "Give me a password: "; 
    cin >> inputPassword; 
    cout << "You provided a password of " << inputPassword << endl;
    cout << "The most similar passwords to "<< inputPassword << " are:" << endl; 
    password_similars(inputPassword);
}
