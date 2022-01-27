//This Code is edited by Lalise Gizaw 
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
//using namespace std;

//MAIN PROGRAM
int main(int argc, char *argv[]){
        // Declare the variables 
		std::string first_string;
        std::string filename;
        std::ifstream file;
        char temp;

        //The following is to store the numbers as unsigned 32-bit number
        uint32_t first_num, second_num, sum;
        std::string number;

		// Assign the filname to the second command line argument
		filename = argv[1];

        //Open the file 
        file.open(filename);

        //Execute the following code if the file exist 
        if(file){
				//Take in the data from the files and continue
                while(file.good()){
                        std::stringstream string1, string2;

                        //Remove thr 0x from the hex values
                        file >> first_string >> temp >> temp >> number;
                        string1 << std::hex << number;
                        file >> temp >> temp >> number;

                    string2 << std::hex << number;

                        //Store them in an uint32_t variable in here number 1
                    string1 >> first_num;

                    //storing in an uint32_t variable in second number
                    string2 >> second_num;

                    //If the first string is "ADD", then add the rest of the strings in the line
                        if(first_string == "ADD"){
                                sum = first_num + second_num;
                                std::cout<< "0x" << std::hex << sum << std::endl;
                        }
                }
                //Close the file
                file.close();   
        }
        else{
                std::cout<< "The file you entered does not exist. Try the following command." << std::endl;
				std::cout << "./a.out filename.txt" << std::endl;
	    }
        return 0;

}