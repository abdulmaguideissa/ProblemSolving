#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) 
    {
        int start = 0;
        int end = 0;

        if (s.empty())
        {
            return "";
        }

        if (s.length() == 1)
        {
            return s;
        }
        
        for (int i = 0; i < s.length() - 1; i++)
        {
            int len_right = expand_from_middle(s, i, i);
            int len_left = expand_from_middle(s, i, i + 1);
            int len = max(len_right, len_left);

            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end);
    }

private:
    int expand_from_middle(string s, int left, int right)
    {
        if(s.empty() || left > right)
        {
            return 0;
        }

        while (right >= 0 && left < s.length() && (s.at(left) == s.at(right)))
        {
            right--;
            left++;
        }
        return (left - right - 1);
    }
};


int main()
{
    Solution solution;
    string s("a");
    cout << solution.longestPalindrome(s) << "\n";
}