/*  Number of happy and sad subsequences in a string with three sections
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

// Pre: string is of the format c1..c1c2..c2c3..c3. c (character search) is to be c1.
// Post: Finds index of last occurence of the character counting from the left before the string has another one. (finds last occurence of c1)
int binarySearchLastFromLeft(char c, const string& str)
{
    int left = 0;
    int right = str.size() - 1;
    int i;

    while (left <= right)
    {
        i = (left + right)/2;

        if (str[i] == c)
        {
            if (str[i+1] != c) return i;
            left = i+1;
        }
        else right = i-1;
    }
    return -1;
}

// Pre: string is of the format c1..c1c2..c2c3..c3. c (character search) is to be c3.
// Post: Finds index of last occurence of the character counting from the right before the string has another one. (finds first occurence of c3)
int binarySearchLastFromRight(char c, const string& str)
{
    int left = 0;
    int right = str.size() - 1;
    int i;

    while (left <= right)
    {
        i = (left + right)/2;

        if (str[i] == c)
        {
            if (str[i-1] != c) return i;
            right = i-1;
        }
        else left = i+1;
    }
    return -1;
}

// Pre: s is formed with three different characters c1,c2,c3, and is of the form c1...c1c2...c2c3...c3.
// Post: n1, n2, n3 are the number of occurrences of c1, c2, c3 in s, respectively.
void numberOccurrences(const string &s, int &n1, int &n2, int &n3)
{
    int size = s.size();
    char c1 = s[0];
    char c3 = s[size-1];

    n1 = binarySearchLastFromLeft(c1, s) + 1; // +1 since function returns index (index is counted from 0)
    n2 = binarySearchLastFromRight(c3, s) - n1;
    n3 = size - n1 - n2;
}

// Pre: s begins with one or more occurrences of a character c1, followed by one or more
//      occurrences of a character c2, followed by one or more occurrences of a character c3,
//      and there are no more characters in s.
//      moreover, either c1c2c3 = ":-)" or c1c2c3 = "(-:" or c1c2c3 = ":-(" or c1c2c3 = ")-:".
// Post: If c1c2c3 = ":-)" or c1c2c3 = "(-:", the function returns the number of happy subsequences.
//       If c1c2c3 = ":-(" or c1c2c3 = ")-:", the function returns the number of sad subsequences.
int numberHappyOrSadSubsequences(const string &s)
{
    int n1, n2, n3;
    numberOccurrences(s, n1, n2, n3);
    int total = n1*n2*n3;
    return total;
}

int main()
{
    
}