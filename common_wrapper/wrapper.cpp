#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int compileAssignment()
{
    const string command =
        "g++ -std=c++17 -O2 "
        "assignment_03/src/csr.cpp "
        "assignment_03/src/gradient_descent.cpp "
        "assignment_03/src/maxflow.cpp "
        "assignment_03/driver/assignment3_driver.cpp "
        "-o assignment_03.exe";

    const int status = system(command.c_str());

    if (status != 0)
    {
        cerr << "Error: Compilation failed.\n";
        return 1;
    }

    return 0;
}

int runOne(const string& algorithm, const string& file)
{
    const string command =
        "assignment_03.exe " + algorithm + " \"" + file + "\"";

    return system(command.c_str());
}

void printMainMenu()
{
    cout << "\n=====================================\n";
    cout << "       CS509 Assignment 3\n";
    cout << "=====================================\n";
    cout << "1. Gradient Descent\n";
    cout << "2. Maxflow-Mincut\n";
    cout << "0. Exit\n";
    cout << "\nEnter your choice: ";
}

void printGradientDescentMenu()
{
    cout << "\n========== Gradient Descent ==========\n";
    cout << "1. gd_01.txt\n";
    cout << "2. gd_02.txt\n";
    cout << "3. gd_03.txt\n";
    cout << "4. gd_04.txt\n";
    cout << "5. gd_05.txt\n";
    cout << "0. Back\n";
    cout << "\nEnter your choice: ";
}

void printMaxflowMenu()
{
    cout << "\n========== Maxflow-Mincut ==========\n";
    cout << "1. maxflow_10.txt\n";
    cout << "2. maxflow_100.txt\n";
    cout << "3. maxflow_1000.txt\n";
    cout << "4. maxflow_10000.txt\n";
    cout << "5. maxflow_50000.txt\n";
    cout << "0. Back\n";
    cout << "\nEnter your choice: ";
}

int main()
{
    while (true)
    {
        printMainMenu();

        int choice;
        cin >> choice;

        if (!cin)
        {
            cerr << "Error: Invalid menu input.\n";
            return 1;
        }

        if (choice == 0)
        {
            return 0;
        }

        if (choice == 1)
        {
            printGradientDescentMenu();

            int testChoice;
            cin >> testChoice;

            if (!cin)
            {
                cerr << "Error: Invalid menu input.\n";
                return 1;
            }

            if (testChoice == 0)
            {
                continue;
            }

            if (testChoice >= 1 && testChoice <= 5)
            {
                const string file =
                    "assignment_03/tests/gd_0" +
                    to_string(testChoice) + ".txt";

                if (compileAssignment() == 0)
                {
                    runOne("gd", file);
                }
            }
            else
            {
                cout << "Invalid choice.\n";
            }
        }
        else if (choice == 2)
        {
            printMaxflowMenu();

            int testChoice;
            cin >> testChoice;

            if (!cin)
            {
                cerr << "Error: Invalid menu input.\n";
                return 1;
            }

            if (testChoice == 0)
            {
                continue;
            }

            const int sizes[] = {
                10, 100, 1000, 10000, 50000
            };

            if (testChoice >= 1 && testChoice <= 5)
            {
                const string file =
                    "assignment_03/tests/maxflow_" +
                    to_string(sizes[testChoice - 1]) +
                    ".txt";

                if (compileAssignment() == 0)
                {
                    runOne("maxflow", file);
                }
            }
            else
            {
                cout << "Invalid choice.\n";
            }
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
}