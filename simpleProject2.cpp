#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void listcontacts();
bool isString(string &input);

int main()
{
    bool loop = true;
    bool charcheck = true;
    int number;
    string input;
    printf("Welcome to your contacts, please use the following commands to navigate the menu:\n");
    printf("1: list contacts\n2: create a contact\n3: edit a contact\n4: exit the program.\n");
    printf("Your input: ");
    cin >> input;

    while (loop)
    {
        while (charcheck)
        {
            if (isString(input))
            {
                printf("Characters are not allowed, please input an integer: ");
                cin >> input;
            }
            else
            {
                charcheck = false;
            }
        }
        number = stoi(input);
        switch (number)
        {
        case 1:
            printf("You have inputted 1, you will now be sent to your contacts.\n");
            sleep(3);
            listcontacts();
            loop = false;
            break;
        case 2:
            printf("You have inputted 2, you will now be sent to your create a contact.\n");
            loop = false;
            break;
        case 3:
            printf("You have inputted 3, you will now be sent to your edit a contact.\n");
            loop = false;
            break;
        case 4:
            printf("You have inputted 4, you will now exit the contacts.\n");
            exit(0);
            break;
        default:
            printf("That was not an option please select another option: ");
            charcheck = true;
            cin >> input;
            break;
        }
    }
    return 0;
}

void listcontacts()
{
    fstream contacts;
    string output;
    contacts.open("Contacts.txt");
    if (contacts.is_open())
    {
        while (getline(contacts, output))
            ;
        {
            cout << output << " ";
        }
        contacts.close();
    }
    else
    {
        printf("Unable to open contacts, this may be due to there being no contacts, please create a contact\n");
        printf("To create a contact, please select '2' when returning to the menu\nyou will be sent there shortly\n");
        sleep(2);
        main();
    }
}
bool isString(string &input)
{
    for (char c : input)
    {
        if (isalpha(c))
        {
            return true;
        }
    }
    for (char c : input)
    {
        if (!isdigit(c))
        {
            return true;
        }
    }
    return false;
}