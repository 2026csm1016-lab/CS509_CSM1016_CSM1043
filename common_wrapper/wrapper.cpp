#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


// ============================================================
// ASSIGNMENT 3 - BUDDY
// Kruskal MST + Prim MST
// ============================================================

int compileAssignment3()
{
    const string command =
        "g++ -std=c++17 -O2 "
        "assignment_03/src/csr.cpp "
        "assignment_03/src/kruskal.cpp "
        "assignment_03/src/prim.cpp "
        "assignment_03/driver/assignment3_driver.cpp "
        "-o assignment_03.exe";

    const int status = system(command.c_str());

    if (status != 0)
    {
        cerr << "Error: Assignment 3 compilation failed.\n";
        return 1;
    }

    return 0;
}

int runAssignment3(
    const string& algorithm,
    const string& file)
{
    const string command =
        "assignment_03.exe " + algorithm + " \"" + file + "\"";

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

    const int status = system(command.c_str());

    if (status != 0)
    {
        cerr << "Error: Assignment 4 compilation failed.\n";
        return 1;
    }

    return 0;
}

int runAssignment4(
    const string& algorithm,
    const string& file)
{
    const string command =
        "assignment_04.exe " + algorithm + " \"" + file + "\"";

    return system(command.c_str());
}


// ============================================================
// MAIN MENU
// ============================================================

void printMainMenu()
{
    cout << "\n=====================================\n";
    cout << "       CS509 Buddy Assignments\n";
    cout << "=====================================\n";
    cout << "1. Assignment 3 - Buddy\n";
    cout << "2. Assignment 4 - Buddy\n";
    cout << "0. Exit\n";
    cout << "\nEnter your choice: ";
}


// ============================================================
// ASSIGNMENT 3 MENUS
// ============================================================

void printAssignment3Menu()
{
    cout << "\n========== Assignment 3 Buddy ==========\n";
    cout << "1. Kruskal MST\n";
    cout << "2. Prim MST\n";
    cout << "0. Back\n";
    cout << "\nEnter your choice: ";
}

void printKruskalMenu()
{
    cout << "\n============= Kruskal MST =============\n";
    cout << "1. mst_10.txt\n";
    cout << "2. mst_100.txt\n";
    cout << "3. mst_10000.txt\n";
    cout << "4. mst_50000.txt\n";
    cout << "5. mst_100000.txt\n";
    cout << "0. Back\n";
    cout << "\nEnter your choice: ";
}

void printPrimMenu()
{
    cout << "\n=============== Prim MST ===============\n";
    cout << "1. mst_10.txt\n";
    cout << "2. mst_100.txt\n";
    cout << "3. mst_10000.txt\n";
    cout << "4. mst_50000.txt\n";
    cout << "5. mst_100000.txt\n";
    cout << "0. Back\n";
    cout << "\nEnter your choice: ";
}


// ============================================================
// ASSIGNMENT 4 MENUS
// ============================================================

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
        {
            return 0;
        }


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
            {
                continue;
            }


            // ---------------- KRUSKAL ----------------

            if (algorithmChoice == 1)
            {
                printKruskalMenu();

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

                const int sizes[] =
                {
                    10, 100, 10000, 50000, 100000
                };

                if (testChoice >= 1 && testChoice <= 5)
                {
                    const string file =
                        "assignment_03/tests/mst_" +
                        to_string(sizes[testChoice - 1]) +
                        ".txt";

                    if (compileAssignment3() == 0)
                    {
                        runAssignment3("kruskal", file);
                    }
                }
                else
                {
                    cout << "Invalid choice.\n";
                }
            }


            // ---------------- PRIM ----------------

            else if (algorithmChoice == 2)
            {
                printPrimMenu();

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

                const int sizes[] =
                {
                    10, 100, 10000, 50000, 100000
                };

                if (testChoice >= 1 && testChoice <= 5)
                {
                    const string file =
                        "assignment_03/tests/mst_" +
                        to_string(sizes[testChoice - 1]) +
                        ".txt";

                    if (compileAssignment3() == 0)
                    {
                        runAssignment3("prim", file);
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
            {
                continue;
            }


            // ---------------- K-MEANS ----------------

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
                {
                    continue;
                }

                if (testChoice >= 1 && testChoice <= 4)
                {
                    const string file =
                        "assignment_04/tests/km_0" +
                        to_string(testChoice) +
                        ".txt";

                    if (compileAssignment4() == 0)
                    {
                        runAssignment4("kmeans", file);
                    }
                }
                else
                {
                    cout << "Invalid choice.\n";
                }
            }


            // ---------------- FASTMAP ----------------

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
                {
                    continue;
                }

                if (testChoice >= 1 && testChoice <= 4)
                {
                    const string file =
                        "assignment_04/tests/fm_0" +
                        to_string(testChoice) +
                        ".txt";

                    if (compileAssignment4() == 0)
                    {
                        runAssignment4("fastmap", file);
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


        // ====================================================
        // INVALID MAIN MENU CHOICE
        // ====================================================

        else
        {
            cout << "Invalid choice.\n";
        }
    }
}