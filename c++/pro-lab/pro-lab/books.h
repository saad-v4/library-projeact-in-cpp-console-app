//هذا فاينل الكلاسات
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class library
{
private:

    string NameOfBook;
    string Author;
    short int YearOfPublication;

public:

    library() {};
    library(string name, string author, short int year) : NameOfBook(name), Author(author), YearOfPublication(year)
    {

    }
    void input()
    {
        cout << "Enter the name of the book: ";
        getline(cin, NameOfBook);
        cout << "Enter the author of the book: ";
        getline(cin, Author);
        cout << "Enter the year of publication: ";
        cin >> YearOfPublication;
        cin.ignore(); // To ignore the newline character left in the input buffer

        ofstream Data("Books.txt", ios::app);
        if (!Data.is_open())
        {
            cout << "Error opening file!" << endl;
        }
        else
        {
            Data << NameOfBook << " | " << Author << " | " << YearOfPublication << endl;
            Data.close();
            cout << "Book details saved successfully!" << endl;
        }
    }

    void display()
    {
        cout << "Name of Book: " << NameOfBook << " | " << "Author: " << Author << " | " << "Year of Publication: " << YearOfPublication << endl;
    }

    void Show_all_Books()
    {
        string line;
        ifstream Data("Books.txt");

        if (!Data.is_open())
        {
            cerr << "Error opening file!" << endl;
            return;
        }
        cout << "Books in the library:" << endl;
        // Read and display each line from the file
        while (getline(Data, line))
        {
            cout << line << endl;
        }

        Data.close();
    }

    void searchBook(const string& bookName)
    {
        ifstream Data("Books.txt");
        if (!Data.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        string line;
        bool found = false;


        string lowerBookName = bookName;
        transform(lowerBookName.begin(), lowerBookName.end(), lowerBookName.begin(), ::tolower);

        while (getline(Data, line))
        {
            string lowerLine = line;
            transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);

            if (lowerLine.find(lowerBookName) != string::npos)
            {
                cout << "Book found: " << line << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Book not found: " << bookName << endl;
        }

        Data.close();
    }

};