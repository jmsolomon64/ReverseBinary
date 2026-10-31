#include <iostream>
#include <thread>
#include <string>

using namespace std;

/**
 * @brief Prints header for neatly seeing where new number starts
 * @param number  
 * @param size 
 */
void PrintStartHeader(int number, int size) {
    char header = '-';

    for(int i = 0; i < size/2; ++i) 
        cout << header;

    cout << " " << number << " ";

    for(int i = 0; i < size/2; ++i) 
        cout << header;
    
    cout << endl;
}

/**
 * @brief Create a Binary String object
 * @param size how many bits to represent
 * @return string containing 0s equal to the number of size
 */
string CreateBinaryString(int size) {
    char empty = '0';
    string binary = "";
    
    for(int i = 0; i < size; ++i) 
        binary += empty;

    return binary;
}

/**
 * @brief Updates binary string being displayed to UI from newly computed binary
 * @param binary UI String
 * @param computed String with new binary data
 */
void UpdateBinaryString(string &binary, string computed) {
    int difference = binary.size() - computed.size();
    binary.replace(difference, computed.size(), computed);
}

/**
 * @brief Handle math operations for finding next binary digit
 * @param input reference to number to have math operation done on 
 * @return 1 or 0
 */
int GetNextBinaryDigit(int &input) { // this takes a reference to input so value changes persist outside function
    int result = input % 2;
    input /= 2;
    return result;
}

/**
 * @brief Convert number to binary version
 * @param input number to be converted 
 */
void convertbinary(int input, int size) {
    string binary = CreateBinaryString(size);
    string computed = "";

    while(input > 0) {
        computed = to_string(GetNextBinaryDigit(input)) + computed;
        UpdateBinaryString(binary, computed);
        cout << binary << endl;
        this_thread::sleep_for(150ms);
    }
}

int main(int argc, char* argv[]) {
    int size = 32; //How many bits to show
    int input;

    if(argc > 1) {
        string argument = argv[1];
        if (argument == "-loop") {
            while(true) { // This can run indefinitely, expects user to interupt with ctrl + c
                input = rand();
                PrintStartHeader(input, size);
                convertbinary(input, size);
            }
        } 
    } else {
        cout << "Please enter a number to convert" << endl;
        cin >> input;
        PrintStartHeader(input, size);
        convertbinary(input, size);
    }

    return 0;
}