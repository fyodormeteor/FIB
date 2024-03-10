/*  How many sentences after a question with more a's than b's
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    char c;
    int count = 0;
    int a_b_difference = 0;
    bool is_after_question = false;
    while(cin >> c)
    {
        if      (c == 'a')  ++a_b_difference;
        else if (c == 'b')  --a_b_difference;
        else
        {
            if (is_after_question and a_b_difference > 0) ++count;
            
            if (c == '?')   is_after_question = true;
            else            is_after_question = false;

            a_b_difference = 0;
        }           
    }

    cout << count << endl;
}