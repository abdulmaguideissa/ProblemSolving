class Solution 
{
public:
     int reverse(int x) 
     {
         int reversed = 0;
        
        while (x != 0)
        {
            int tens = x % 10;
            x /= 10;
            
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && tens > 7))
                return 0;
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && tens < -8))
                return 0;
            reversed = reversed * 10 + tens;
        }
        return (reversed);
    }
};