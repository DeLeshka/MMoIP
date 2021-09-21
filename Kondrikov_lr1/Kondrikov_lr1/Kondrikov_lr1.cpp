#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


inline std::string getString(std::string message)
{
    std::cout << "Please, enter " << message << ": ";
    std::string key;
    //std::cin.clear();
    //std::cin.ignore(32767, '\n');
    std::getline(std::cin, key);
   /* if (key == "") 
        key = getString(message);*/
    return key;
}

unsigned char encode(int letter, int codeLetter)
{
    if (codeLetter < 0) codeLetter += 256;
    //chars are stored in memory as integers, so we can calculate a new one by ascii codes of original and current key letter
    letter += codeLetter - 1;

    //if letter's code will be > 254 we'll reduce it by 223 to insert it in [32, 254] interval
    if (letter > 255) letter -= 224;
    return letter;
}

unsigned char decode(int letter, int codeLetter)
{
    if (codeLetter < 0) codeLetter += 256;
    //chars are stored in memory as integers, so we can calculate a new one by ascii codes of original and current key letter
    letter -= codeLetter - 1;

    //if letter's code will be > 254 we'll reduce it by 223 to insert it in [32, 254] interval
    if (letter < 32) letter += 224;
    return letter;
}

int getAnswer()
{
    int answer;
    std::cout << "Select an operation: ";
    while ((std::cin >> answer).fail() || !(answer >= 0 && answer < 3))
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Please, input a valid answer: ";
    }
    return answer;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        std::cout << "1. Encrypt a file.\n" << "2. Decrypt a file\n" << "0. Exit\n";

        //указатель на функцию (де)кодирования
        unsigned char (*codePtr)(int letter, int codeLetter) = encode;

        switch (getAnswer())
        {
        case 1:
        {
            codePtr = encode;
            break;
        }
        case 2:
        {
            codePtr = decode;
            break;
        }
        case 0:
            return 0;
        }

        std::string key{ getString("key") };
        std::string inFName{ getString("an input file name (without \".txt\")") + ".txt" };
        std::ifstream inFile(inFName);
        assert(inFile && "Output file couldn't be opened");

        std::string outFName{ getString("an output file name (without \".txt\")") + ".txt" };
        std::ofstream outFile(outFName);
        assert(outFile && "Output file couldn't be opened");

        int letter;
        int i = 0;
        int key_length = key.length();

        while ((letter = inFile.get()) != EOF) {
            if (letter != '\n')
            {

                //for checking in console
                //std::cout << letter << ' ' << (char)letter << ' ' << (int)(*codePtr)(letter, static_cast<int>(key[i])) << ' ' << (*codePtr)(letter, static_cast<int>(key[i])) << std::endl; 

                outFile << (*codePtr)(letter, static_cast<int>(key[i]));
                i++;
                if (i == key_length) i = 0;
            }
            else
                outFile << std::endl;
        }

        std::cout << "\nEncryption was succesfull.\n";
        inFile.close();
        outFile.close();
    }














    //checking prowed that symbol codes in output file are the same, so decrypting is real

    /*std::ifstream in2File(outFName);
    while ((letter = in2File.get()) != EOF) {
        if (letter != '\n')
        {

            std::cout << letter << ' ' << (char)letter << std::endl;
        }
    }*/
   
}

