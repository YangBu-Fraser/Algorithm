/**
 * 859. Buddy Strings
 * 
 * Given two strings s and goal, return true if you can swap two letters in s 
 * so the result is equal to goal, otherwise, return false.
 * 
 * Swapping letters is defined as taking two indices i and j (0-indexed) 
 * such that i != j and swapping the characters at s[i] and s[j].
 * 
 * For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 * 
 */

class Solution {
public:
    bool has_rep(string a) {
        int cnt[26] = {0};
        for (int i=0; a[i]; i++) {
            cnt[a[i] - 'a'] += 1;
            if(cnt[a[i] - 'a'] == 2) { return true;}
        }
        return false;
    }

    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) { return false; }
        if(s == goal) { return has_rep(s);}
        int i = 0, j;
        while(s[i] == goal[i]) { ++i; }
        j = i + 1;
        while(j < s.size() && s[j] == goal[j]) { ++j; }
        if( j == s.size()) { return false;}  
        if(s[i] != goal[j] || s[j] != goal[i]) { return false; }
        j += 1;
        while (j < s.size()) {
            if (s[j] != goal[j]) { return false;}
            j += 1;
        }
        return true;
    }
};