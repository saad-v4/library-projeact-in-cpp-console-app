#include<iostream>
#include<string>
#include <algorithm>
#include <fstream>
#include "books.h"

using namespace std;

int main()
{

    library lib;
    int choice;
    do
    {
        cout << "==========================================================" << endl;
        cout << "Library Management System" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. search book" << endl;
        cout << "4. Exit" << endl;
        cout << "==========================================================" << endl;
        cout << "Enter your choice: ";
        cout << "\n==========================================================" << endl;
        cin >> choice;
        cin.ignore(); // To ignore the newline character left in the input buffer
        switch (choice)
        {
        case 1:
            lib.input();
            break;
        case 2:
            lib.Show_all_Books();
            break;
        case 3:
        {
            string searchTitle;
            cout << "Enter the title of the book to search: ";
            getline(cin, searchTitle);
            lib.searchBook(searchTitle);
        }
        break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
    return 0;

}