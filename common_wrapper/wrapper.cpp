#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifdef _WIN32
const string EXEC_PREFIX = ".\\";
#else
const string EXEC_PREFIX = "./";
#endif

// ============================================================
// ASSIGNMENT 3 - BUDDY
// Gradient Descent + Maxflow-Mincut
// ============================================================

int compileAssignment3()
{
    const string command =
        "g++ -std=c++17 -O2 "
        "assignment_03/src/csr.cpp "
        "assignment_03/src/gradient_descent.cpp "
        "assignment_03/src/maxflow.cpp "
        "assignment_03/driver/assignment3_driver.cpp "
        "-o assignment_03.exe";

    return system(command.c_str()) == 0 ? 0 : 1;
}

int runAssignment3(const string& algorithm, const string& file)
{
    const string command =
        EXEC_PREFIX + "assignment_03.exe " + algorithm + " \"" + file + "\"";

    return system(command.c_str());
}

// ============================================================
// ASSIGNMENT 4 - BUDDY
// K-Means + FastMap
// ============================================================

int compileAssignment4()
{
    const string command =
        "g++ -std=c++17 -O2 "
        "assignment_04/src/kmeans.cpp "
        "assignment_04/src/fastmap.cpp "
        "assignment_04/driver/assignment4_buddy.cpp "
        "-o assignment_04.exe";

    return system(command.c_str()) == 0 ? 0 : 1;
}

int runAssignment4(const string& algorithm, const string& file)
{
    const string command =
        EXEC_PREFIX + "assignment_04.exe " + algorithm + " \"" + file + "\"";

    return system(command.c_str());
}

// ============================================================
// MENUS
// ============================================================

void printMainMenu()
{
    cout << "\n=====================================\n";
    cout << "       CS509 Buddy Assignments\n";
    cout << "=====================================\n";
    cout << "1. Assignment 3\n";
    cout << "2. Assignment 4\n";
    cout << "0. Exit\n";
    cout << "\nEnter your choice: ";
}

void printAssignment3Menu()
{
    cout << "\n========== Assignment 3 Buddy ==========\n";
    cout << "1. Gradient Descent\n";
    cout << "2. Maxflow-Mincut\n";
    cout << "0. Back\n";
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

void printAssignment4Menu()
{
    cout << "\n========== Assignment 4 Buddy ==========\n";
    cout << "1. K-Means Clustering\n";
    cout << "2. FastMap\n";
    cout << "0. Back\n";
    cout << "\nEnter your choice: ";
}

void printKMeansMenu()
{
    cout << "\n========== K-Means Clustering ==========\n";
    cout << "1. km_01.txt\n";
    cout << "2. km_02.txt\n";
    cout << "3. km_03.txt\n";
    cout << "4. km_04.txt\n";
    cout << "0. Back\n";
    cout << "\nEnter your choice: ";
}

void printFastMapMenu()
{
    cout << "\n=============== FastMap ===============\n";
    cout << "1. fm_01.txt\n";
    cout << "2. fm_02.txt\n";
    cout << "3. fm_03.txt\n";
    cout << "4. fm_04.txt\n";
    cout << "0. Back\n";
    cout << "\nEnter your choice: ";
}

// ============================================================
// MAIN
// ============================================================

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
            return 0;

        // ====================================================
        // ASSIGNMENT 3 - BUDDY
        // ====================================================
        if (choice == 1)
        {
            printAssignment3Menu();

            int algorithmChoice;
            cin >> algorithmChoice;

            if (!cin)
            {
                cerr << "Error: Invalid menu input.\n";
                return 1;
            }

            if (algorithmChoice == 0)
                continue;

            if (algorithmChoice == 1)
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
                    continue;

                if (testChoice >= 1 && testChoice <= 5)
                {
                    const string file =
                        "assignment_03/tests/gd_0" +
                        to_string(testChoice) + ".txt";

                    if (compileAssignment3() == 0)
                        runAssignment3("gd", file);
                    else
                        cerr << "Error: Assignment 3 compilation failed.\n";
                }
                else
                {
                    cout << "Invalid choice.\n";
                }
            }
            else if (algorithmChoice == 2)
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
                    continue;

                const int sizes[] = {10, 100, 1000, 10000, 50000};

                if (testChoice >= 1 && testChoice <= 5)
                {
                    const string file =
                        "assignment_03/tests/maxflow_" +
                        to_string(sizes[testChoice - 1]) + ".txt";

                    if (compileAssignment3() == 0)
                        runAssignment3("maxflow", file);
                    else
                        cerr << "Error: Assignment 3 compilation failed.\n";
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

        // ====================================================
        // ASSIGNMENT 4 - BUDDY
        // ====================================================
        else if (choice == 2)
        {
            printAssignment4Menu();

            int algorithmChoice;
            cin >> algorithmChoice;

            if (!cin)
            {
                cerr << "Error: Invalid menu input.\n";
                return 1;
            }

            if (algorithmChoice == 0)
                continue;

            if (algorithmChoice == 1)
            {
                printKMeansMenu();

                int testChoice;
                cin >> testChoice;

                if (!cin)
                {
                    cerr << "Error: Invalid menu input.\n";
                    return 1;
                }

                if (testChoice == 0)
                    continue;

                if (testChoice >= 1 && testChoice <= 4)
                {
                    const string file =
                        "assignment_04/tests/km_0" +
                        to_string(testChoice) + ".txt";

                    if (compileAssignment4() == 0)
                        runAssignment4("kmeans", file);
                    else
                        cerr << "Error: Assignment 4 compilation failed.\n";
                }
                else
                {
                    cout << "Invalid choice.\n";
                }
            }
            else if (algorithmChoice == 2)
            {
                printFastMapMenu();

                int testChoice;
                cin >> testChoice;

                if (!cin)
                {
                    cerr << "Error: Invalid menu input.\n";
                    return 1;
                }

                if (testChoice == 0)
                    continue;

                if (testChoice >= 1 && testChoice <= 4)
                {
                    const string file =
                        "assignment_04/tests/fm_0" +
                        to_string(testChoice) + ".txt";

                    if (compileAssignment4() == 0)
                        runAssignment4("fastmap", file);
                    else
                        cerr << "Error: Assignment 4 compilation failed.\n";
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
        else
        {
            cout << "Invalid choice.\n";
        }
    }
}
