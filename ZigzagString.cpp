
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1)
            return s;

        vector<string> rows(min(numRows, int(s.length())));
        string res;
        bool down_dir = false;
        bool up_dir = false;
        int cur_row = 0;

        for (char ch : s) 
        {
            rows[cur_row].push_back(ch);

            if (cur_row == 0 cur_row == numRows - 1)
                down_dir = !down_dir;
            cur_row += down_dir ? 1 : -1;
        }

        for (string row : rows)
        {
            res += row;
        }
        return res;
    }
};