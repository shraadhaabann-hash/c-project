#include <iostream>
using namespace std;

// Function for Addition
float add(float a, float b)
{
    return a + b;
}

// Function for Subtraction
float subtract(float a, float b)
{
    return a - b;
}

// Function for Multiplication
float multiply(float a, float b)
{
    return a * b;
}

// Function for Division
float divide(float a, float b)
{
    if (b == 0)
    {
        cout << "Error! Division by zero is not allowed." << endl;
        return 0;
    }
    else
    {
        return a / b;
    }
}

int main()
{
    float num1, num2;
    int choice;

    cout << "====================================" << endl;
    cout << "        SIMPLE CALCULATOR" << endl;
    cout << "====================================" << endl;

    // Taking input from user
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Displaying menu
    cout << "\nChoose an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;

    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // Performing calculation
    switch (choice)
    {
        case 1:
            cout << "\nResult: " << num1 << " + " << num2 
                 << " = " << add(num1, num2) << endl;
            break;

        case 2:
            cout << "\nResult: " << num1 << " - " << num2 
                 << " = " << subtract(num1, num2) << endl;
            break;

        case 3:
            cout << "\nResult: " << num1 << " * " << num2 
                 << " = " << multiply(num1, num2) << endl;
            break;

        case 4:
            cout << "\nResult: " << num1 << " / " << num2 
                 << " = " << divide(num1, num2) << endl;
            break;

        default:
            cout << "\nInvalid choice! Please select between 1 to 4." << endl;
    }

    cout << "\nThank you for using the Simple Calculator!" << endl;
    cout << "====================================" << endl;

    return 0;
}