//Runtime: 316 ms, faster than 42.86% of C++ online submissions for Construct K Palindrome Strings.
//Memory Usage: 12.2 MB, less than 100.00% of C++ online submissions for Construct K Palindrome Strings.
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        if(s.size() == k) return true;
        map<char, int> count;
        
        for(char c : s){
            count[c]++;
        }
        
        int odd = 0;
        for(auto it = count.begin(); it != count.end(); it++){
            if(it->second % 2 == 1){
                odd++;
            }
        }
        return odd <= k;
    }
};

//speed up with vector
//Runtime: 88 ms, faster than 42.86% of C++ online submissions for Construct K Palindrome Strings.
//Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Construct K Palindrome Strings.
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        if(s.size() == k) return true;
        vector<int> count(26);
        
        for(char c : s){
            count[c-'a']++;
        }
        
        int odd = 0;
        for(int i = 0; i < 26; i++){
            if(count[i] % 2 == 1){
                odd++;
            }
        }
        return odd <= k;
    }
};
