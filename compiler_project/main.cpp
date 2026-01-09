#include <iostream>
using namespace std;

// Option 1: Lexical Analyzer and Validation
void runOption1();

// Option 2: 3-Address Code Generation
void runOption2();

int main()
{
    int choice;
    do
    {
        cout << "\n===== MiniLang Compiler Menu =====\n";
        cout << "1. Lexical Analyzer and Statement Validator\n";
        cout << "2. Three Address Code Generator\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice)
        {
        case 1:
            runOption1();
            break;
        case 2:
            runOption2();
            break;
        case 0:
            cout << "Exiting MiniLang Compiler. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}