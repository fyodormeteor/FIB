/*  Schedule of teachers and subjects
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<string> VecString;

struct Slot
{
    VecString listsubjects;
    VecString listteachers;
};
typedef vector<vector<Slot>> TableSlots;

int convertWeekdayToInt(const string& weekday)
{
    int day;
    if      (weekday == "monday")       day = 0;
    else if (weekday == "tuesday")      day = 1;
    else if (weekday == "wednesday")    day = 2;
    else if (weekday == "thursday")     day = 3;
    else                                day = 4;

    return day;
}

void updateSlot(Slot& slot, const string& subject, const string& teacher)
{
    slot.listsubjects.push_back(subject);
    slot.listteachers.push_back(teacher);
}

void processConflicts(VecString& vec, int& conflicts)
{
    int size = vec.size();
    if (size == 0) return;

    sort(vec.begin(), vec.end());
    
    VecString vec_new;

    string entry_before = "-1";
    string entry;

    for(int i = 0; i < size; ++i)
    {
        entry = vec[i];
        if (entry == entry_before) conflicts++;
        else vec_new.push_back(entry);
        entry_before = entry;
    }

    vec = vec_new;
}

void drawJustifiedRightString(const string text, const int width)
{
    int text_width = text.size();
    for(int i = 0; i < width-text_width; ++i)
        cout << ' ';
    cout << text;
}

void drawJustifiedRightInt(const int text, const int width)
{
    int text_width = 0;
    int text_aux = text;
    if (text == 0) text_width = 1;
    while(text_aux != 0)
    {
        text_aux /= 10;
        text_width++;
    }
    for(int i = 0; i < width-text_width; ++i)
        cout << ' ';
    cout << text;
}

void drawOutput(const TableSlots& table, const int& min_h, const int& max_h, const int& conflicts)
{
    cout << "number of subjects per slot:" << endl;
    drawJustifiedRightString("h", 2);
    drawJustifiedRightString("monday", 10);
    drawJustifiedRightString("tuesday", 10);
    drawJustifiedRightString("wednesday", 10);
    drawJustifiedRightString("thursday", 10);
    drawJustifiedRightString("friday", 10);
    cout << endl;

    for(int i = min_h; i < max_h; ++i)
    {
        drawJustifiedRightInt(i, 2);
        for(int j = 0; j < 5; ++j)
        {
            drawJustifiedRightInt(table[j][i].listsubjects.size(), 10);
        }
        cout << endl;
    }

    cout << "number of teachers per slot:" << endl;
    drawJustifiedRightString("h", 2);
    drawJustifiedRightString("monday", 10);
    drawJustifiedRightString("tuesday", 10);
    drawJustifiedRightString("wednesday", 10);
    drawJustifiedRightString("thursday", 10);
    drawJustifiedRightString("friday", 10);
    cout << endl;

    for(int i = min_h; i < max_h; ++i)
    {
        drawJustifiedRightInt(i, 2);
        for(int j = 0; j < 5; ++j)
        {
            drawJustifiedRightInt(table[j][i].listteachers.size(), 10);
        }
        cout << endl;
    }

    cout << "number of replacements needed to avoid conflicts:" << endl;
    cout << conflicts << endl;
}

int main()
{
    Slot emptySlot;
    TableSlots table(5, vector<Slot>(24, emptySlot)); //5 days, each day with 24 hours
    
    int min_h = 24;
    int max_h = -1;

    string subject, teacher, weekday;
    int h1, h2;
    while(cin >> subject >> teacher >> weekday >> h1 >> h2)
    {
        if (h1 < min_h) min_h = h1;
        if (h2 > max_h) max_h = h2;
        
        int day = convertWeekdayToInt(weekday);
        for(int i = h1; i < h2; ++i)
            updateSlot(table[day][i], subject, teacher);
    }

    int conflicts = 0;
    for(int i = min_h; i < max_h; ++i)
    {
        for(int j = 0; j < 5; ++j)
            processConflicts(table[j][i].listteachers, conflicts);
    }

    drawOutput(table, min_h, max_h, conflicts);
}