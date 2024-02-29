#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <Windows.h> // We include this to allow the program to play a sound when an answer is correct
using namespace std;

const int NUM_MATH_OPERATIONS = 4; // Utilize 4 math operations
const int NUM_ATTEMPTS = 3; // 3 Attempts for each question

// Enum for Math Operations
enum MathOperation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

struct Student {
    string name;
    int grade;
    string teacherName;
    int additionRight;
    int additionWrong;
    int subtractionRight;
    int subtractionWrong;
    int multiplicationRight;
    int multiplicationWrong;
    int divisionRight;
    int divisionWrong;
};

int displayMenu();
bool isValid(int num, int min, int max);
void inputStudentInfo(Student& student);
void addition(Student& student);
void subtraction(Student& student);
void multiplication(Student& student);
void division(Student& student);
void showStats(const Student& student);
void playCorrectSound();
void displayBackground();
MathOperation randomMathOperation();
void randomMode(Student& student);

int main()
{
    string name;
    int seed = time(0);
    srand(seed);
    int choice;

    Student student;
    student.name = "Unknown";
    student.grade = 0;
    student.teacherName = "Unknown";
    student.additionRight = 0;
    student.additionWrong = 0;
    student.subtractionRight = 0;
    student.subtractionWrong = 0;
    student.multiplicationRight = 0;
    student.multiplicationWrong = 0;
    student.divisionRight = 0;
    student.divisionWrong = 0;
    // User inputs their name here which is part of the student info
    cout << "What's your name? \n";
    getline(cin, name);
    student.name = name;
   // void inputStudentInfo is utiized here where the student inputs their name, grade, and their teacher's name
    inputStudentInfo(student);
    displayBackground();
    cout << "Welcome to Supreme Math Tutor " << student.name << endl;
    // The choices the user is offered
    do
    {
        choice = displayMenu();

        switch (choice)
        {
        case 1:
            addition(student);
            break;
        case 2:
            subtraction(student);
            break;
        case 3:
            multiplication(student);
            break;
        case 4:
            division(student);
            break;
        case 5:
            randomMode(student);
            break;
        case 6:
            showStats(student);
            cout << "You will now be exiting the program.\n\n";
            break;
        default:
            cout << "An Error has occurred. Invalid Input.\n\n";
            break;
        }
    } while (choice != NUM_MATH_OPERATIONS + 2);

    cout << "Thank you for using the Math Tutor!\n\n";

    return 0;
}

int displayMenu() // The menu that will be shown to the user
{
    int c;

    cout << "Choose a selection" << endl
        << "-----------------------------------------\n"
        << "1. Addition" << endl
        << "2. Subtraction" << endl
        << "3. Multiplication" << endl
        << "4. Division" << endl
        << "5. Random Mode" << endl
        << "6. Show Stats" << endl
        << NUM_MATH_OPERATIONS + 2 << ". Quit" << endl;

    cin >> c;

    while (!isValid(c, 1, NUM_MATH_OPERATIONS + 2)) // Code will keeep running until the student puts a valid number
    {
        cin >> c;
    }

    return c;
}

bool isValid(int num, int min, int max) // This will check if a given integer falls in the range set by "min" and max"
{
    return num >= min && num <= max;
}

/* inputStudentInfo function allows the student to input their name, grade, and teacher name.When the show stats option is selected this
information will also be displayed along with the statistics in regards to questions answered correctly and incorrectly
*/

void inputStudentInfo(Student& student)
{
    cout << "Enter student's grade: ";
    cin >> student.grade;

    cin.ignore(); // Ignore the newline character left in the input buffer after entering grade.

    cout << "Enter student's teacher name: ";
    getline(cin, student.teacherName);
}

// The addition function

void addition(Student& student)
{
    int num1, num2, min, max, answer, result, attempts;     /* With all the void functions with the mathematical operation
                                        there will be ranges that defined such as 1 being the minimum and 99 being the max*/
    attempts = NUM_ATTEMPTS;

    min = 2, max = 500,
        num1 = min + (rand() % (max - min + 1));

    min = 1, max = 99;
    num2 = min + (rand() % (max - min + 1));

    while (num2 >= num1)
    {
        num2 = min + (rand() % (max - min + 1));
    }

    result = num1 + num2;

    cout << "Addition: you have 3 attempts\n";
    cout << setw(5) << num1 << endl
        << "+  " << num2 << endl
        << "______\n";
    cin >> answer;
    attempts--;

    while (answer != result && attempts > 0)
    {
        cout << "Sorry that's incorrect.\n";
        cout << attempts << " attempts remaining.\n";
        cout << "Addition: you have 3 attempts\n";
        cout << setw(5) << num1 << endl
            << "+  " << num2 << endl
            << "______\n";
        cin >> answer;
        attempts--;
    }

    if (answer == result)
    {
        cout << "Congratulations!\n";
        playCorrectSound();
        student.additionRight++;
    }
    else
    {
        cout << "Sorry, the answer is " << result << endl;
        student.additionWrong++;
    }
}

//displayBackground function allows this amazing art to be displayed after student inputs the info 

void displayBackground()
{
    // Clear the console
    system("cls");

    // The cool image that shows after the user inputs their data
    cout << "====================================================\n";
    cout << "|                                                  |\n";
    cout << "|          SUPREME MATH TUTOR                      | \n";
    cout << "|                                                  |\n";
    cout << "====================================================\n";
}

// Subtraction function

void subtraction(Student& student)
{
    int num1, num2, min, max, answer, result, attempts;

    attempts = NUM_ATTEMPTS;

    min = 2, max = 500,
        num1 = min + rand() % (max - min + 1);

    min = 1, max = 500;
    num2 = min + rand() % (max - min + 1);

    while (num2 >= num1)
    {
        num2 = min + rand() % (max - min + 1);
    }

    result = num1 - num2;

    cout << "Subtraction: you have 3 attempts\n";
    cout << setw(5) << num1 << endl
        << "-  " << num2 << endl
        << "______\n";
    cin >> answer;
    attempts--;

    while (answer != result && attempts > 0)
    {
        cout << "Sorry that's incorrect.\n";
        cout << attempts << " attempts remaining.\n";
        cout << "Subtraction: you have 3 attempts\n";
        cout << setw(5) << num1 << endl
            << "-  " << num2 << endl
            << "______\n";
        cin >> answer;
        attempts--;
    }

    if (answer == result)
    {
        cout << "Congratulations!\n";
        playCorrectSound();
        student.subtractionRight++;
    }
    else
    {
        cout << "Sorry, the answer is " << result << endl;
        student.subtractionWrong++;
    }
}

// The multiplication function

void multiplication(Student& student)
{
    int num1, num2, min, max, answer, result, attempts;

    attempts = NUM_ATTEMPTS;

    min = 1, max = 12,
        num1 = min + (rand() % (max - min + 1));

    min = 1, max = 12;
    num2 = min + (rand() % (max - min + 1));

    while (num2 >= num1)
    {
        num2 = min + (rand() % (max - min + 1));
    }

    result = num1 * num2;

    cout << "Multiplication: you have 3 attempts\n";
    cout << setw(5) << num1 << endl
        << "*  " << num2 << endl
        << "______\n";
    cin >> answer;
    attempts--;

    while (answer != result && attempts > 0)
    {
        cout << "Sorry that's incorrect.\n";
        cout << attempts << " attempts remaining.\n";
        cout << "Multiplication: you have 3 attempts\n";
        cout << setw(5) << num1 << endl
            << "*  " << num2 << endl
            << "______\n";
        cin >> answer;
        attempts--;
    }

    if (answer == result)
    {
        cout << "Congratulations!\n";
        playCorrectSound();
        student.multiplicationRight++;
    }
    else
    {
        cout << "Sorry, the answer is " << result << endl;
        student.multiplicationWrong++;
    }
}

// Division Function

void division(Student& student)
{
    int num1, num2, min, max, answer, result, attempts;

    attempts = NUM_ATTEMPTS;

    min = 1, max = 999,
        num1 = min + rand() % (max - min + 1);

    min = 1, max = 9;
    num2 = min + rand() % (max - min + 1);

    while ((num1 % num2) != 0)
    {
        num2 = (rand() % (max - min + 1)) + min;
    }

    result = num1 / num2;

    cout << "Division: you have 3 attempts\n";
    cout << setw(5) << num1 << endl
        << "/  " << num2 << endl
        << "______\n";
    cin >> answer;
    attempts--;

    while (answer != result && attempts > 0)
    {
        cout << "Sorry that's incorrect.\n";
        cout << attempts << " attempts remaining.\n";
        cout << "Division: you have 3 attempts\n";
        cout << setw(5) << num1 << endl
            << "/  " << num2 << endl
            << "______\n";
        cin >> answer;
        attempts--;
    }

    if (answer == result)
    {
        cout << "Congratulations!\n";
        playCorrectSound();
        student.divisionRight++;
    }
    else
    {
        cout << "Sorry, the answer is " << result << endl;
        student.divisionWrong++;
    }
}

// Function for playing correct sound
void playCorrectSound()
{
    PlaySound(TEXT("Correct.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

// void showStats shows the user's personal info (name, teacher name, and grade) along with the amount of problems right and wrong in each operation

void showStats(const Student& student)
{
    cout << "Student Information:" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Grade: " << student.grade << endl;
    cout << "Teacher's Name: " << student.teacherName << endl;

    cout << "Math Operation Statistics:" << endl;
    cout << setw(20) << "Math Operation" << setw(20) << "Correct" << setw(20) << "Incorrect" << setw(20) << "Percentage" << endl;

    // Addition statistics
    cout << setw(20) << "Addition" << setw(20) << student.additionRight << setw(20) << student.additionWrong;
    if (student.additionRight + student.additionWrong != 0)
    {
        double additionPercentage = static_cast<double>(student.additionRight) / (student.additionRight + student.additionWrong) * 100.0;
        cout << setw(20) << fixed << setprecision(2) << additionPercentage << "%" << endl;
    }
    else
    {
        cout << setw(20) << "N/A" << endl;
    }

    // Subtraction statistics
    cout << setw(20) << "Subtraction" << setw(20) << student.subtractionRight << setw(20) << student.subtractionWrong;
    if (student.subtractionRight + student.subtractionWrong != 0)
    {
        double subtractionPercentage = static_cast<double>(student.subtractionRight) / (student.subtractionRight + student.subtractionWrong) * 100.0;
        cout << setw(20) << fixed << setprecision(2) << subtractionPercentage << "%" << endl;
    }
    else
    {
        cout << setw(20) << "N/A" << endl;
    }

    // Multiplication statistics
    cout << setw(20) << "Multiplication" << setw(20) << student.multiplicationRight << setw(20) << student.multiplicationWrong;
    if (student.multiplicationRight + student.multiplicationWrong != 0)
    {
        double multiplicationPercentage = static_cast<double>(student.multiplicationRight) / (student.multiplicationRight + student.multiplicationWrong) * 100.0;
        cout << setw(20) << fixed << setprecision(2) << multiplicationPercentage << "%" << endl;
    }
    else
    {
        cout << setw(20) << "N/A" << endl;
    }

    // Division statistics
    cout << setw(20) << "Division" << setw(20) << student.divisionRight << setw(20) << student.divisionWrong;
    if (student.divisionRight + student.divisionWrong != 0)
    {
        double divisionPercentage = static_cast<double>(student.divisionRight) / (student.divisionRight + student.divisionWrong) * 100.0;
        cout << setw(20) << fixed << setprecision(2) << divisionPercentage << "%" << endl;
    }
    else
    {
        cout << setw(20) << "N/A" << endl;
    }

    // Overall statistics from the user's time in the program

    int totalRight = student.additionRight + student.subtractionRight + student.multiplicationRight + student.divisionRight;
    int totalWrong = student.additionWrong + student.subtractionWrong + student.multiplicationWrong + student.divisionWrong;
    cout << setw(20) << "Overall" << setw(20) << totalRight << setw(20) << totalWrong;
    if (totalRight + totalWrong != 0)
    {
        double overallPercentage = static_cast<double>(totalRight) / (totalRight + totalWrong) * 100.0;
        cout << setw(20) << fixed << setprecision(2) << overallPercentage << "%" << endl;
    }
    else
    {
        cout << setw(20) << "N/A" << endl;
    }
}

//This selects a random math operation that can be selected from the menu

MathOperation randomMathOperation()
{
    return static_cast<MathOperation>(rand() % NUM_MATH_OPERATIONS);
}

// The void randomMode is the proper Random Mode function of the program

void randomMode(Student& student)
{
    MathOperation operation = randomMathOperation(); /* Allows the void uses the function where we select a random math operation that the menu
                                                        offers and give the user a random math problem from any math operation */
    switch (operation)
    {
    case ADDITION:
        addition(student);
        break;
    case SUBTRACTION:
        subtraction(student);
        break;
    case MULTIPLICATION:
        multiplication(student);
        break;
    case DIVISION:
        division(student);
        break;
    }
}