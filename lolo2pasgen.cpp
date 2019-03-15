/**
 ************************************************************************************************************************
 *
 *  @file                   lolo2passgen.cpp
 *  @brief                  Adventures of Lolo 2 Password Generator
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   March 15th, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   For use with the N.E.S. Version
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    int level = 0;
    int temp = 0;
    wchar_t tempArray[4];
    string input = "";

    cout << "Adventures of Lolo 2 password generator v 1.0" << endl;
    cout << "For use with the N.E.S." << endl;
    cout << "Coded by: sleepy9090" << endl;
    cout << "======================================" << endl;
    cout << endl;

    while (true) {
        cout << "Enter level number (0..51): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> level)
        {
            if (level >= 0 && level <= 51)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    if (level > 0)
    {
        level--;
    }

    temp = (level ^ 255) + 17;
    tempArray[0] = level >> 4 & 15;
    tempArray[1] = level & 15;
    tempArray[2] = temp >> 4 & 15;
    tempArray[3] = temp & 15;

    string password;
	for(int i = 0; i < 4; i++)
    {
        password += "PHQVRBLCGZYMJTDK"[tempArray[i]];
    }

    cout << endl;
    cout << "Generated password: " << password << endl;

    return(0);
}

