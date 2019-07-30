/*
  Challenges of leetCode
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        string str_window;    // Sliding window of strings
        int i = 0;
        int j = 0;
        int n = s.length();
        
        int max_counter = 0;
        
        if(s.empty()){
            return 0;
        }
        
        while(j < n && i < n){
            if(str_window.find(s.at(j)) == string::npos){
                str_window.push_back(s.at(j++));
                max_counter = max(max_counter, j - i);  // Window length = j - i
            }
            else{
                char ch = s.at(i++);
                int pos = str_window.find(ch);
                str_window.erase(str_window.begin() + pos);
               
            }
        }
        return max_counter;
    }
};
