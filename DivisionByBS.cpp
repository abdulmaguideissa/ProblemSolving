#include <iostream>

using namespace std;

class Solution {
public:
    long long int divide(long long int dividend, long long int divisor) 
    {
        long long int res = 0;
        unsigned long long int abs_dividend = abs(dividend);
        unsigned long long int abs_divisor = abs(divisor);
                
        if (abs_divisor == 1)
        {
            res = abs_dividend;
            return (((dividend < 0 && divisor < 0) || 
                   (divisor > 0 && dividend > 0)) ? (res) : (-1 * res));
        }
        
        else 
        {
            if (((abs_divisor % 2) != 0) &&
                ((abs_dividend % abs_divisor) != 0) &&
                ((abs_dividend / abs_divisor) >= abs_divisor))
                res++;

            while(abs_dividend >= abs_divisor)
            {
                res++;
                abs_dividend /= 2;
            }
            return (((dividend < 0 && divisor < 0) || 
                   (divisor > 0 && dividend > 0)) ? (res) : (-1 * res));
        }
    }
};


int main()
{
    Solution solution;
    long long int dividend;
    long long int divisor;

    cin >> dividend >> divisor;

    cout << solution.divide(dividend, divisor) << "\n";
}