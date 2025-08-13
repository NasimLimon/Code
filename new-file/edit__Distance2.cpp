// C++ program to calculate the minimum edit distance
// between two strings using recursion

#include <cstring>
#include <iostream>
using namespace std;

int min(int a, int b, int c) { return min(min(a, b), c); }

// Recursive function to find the edit distance
int editDistanceRecursive(string str1, string str2, int m,
                          int n)
{
    // If str1 is empty, insert all characters of str2
    if (m == 0)
        return n;
    // If str2 is empty, remove all characters of str1
    if (n == 0)
        return m;

    // If the last characters match, move to the next pair
    if (str1[m - 1] == str2[n - 1])
        return editDistanceRecursive(str1, str2, m - 1,
                                     n - 1);

    // If the last characters don't match, consider all
    // three operations
    return 1 + min(editDistanceRecursive(str1, str2, m,
                                         n - 1), // Insert
                   editDistanceRecursive(str1, str2, m - 1,
                                         n), // Remove
                   editDistanceRecursive(str1, str2, m - 1,
                                         n - 1) // Replace
               );
}

int main()
{
    // Initialize two strings
    string str1 = "GEEXSFRGEEKKS";
    string str2 = "GEEKSFORGEEKS";
    // print the minimum edit distance
    cout << "Minimum edit distance is "
         << editDistanceRecursive(str1, str2, str1.length(),
                                  str2.length())
         << endl;
    return 0;
}