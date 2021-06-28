class Solution {
public:
    int titleToNumber(string s) {
        int cnum = 0;
        for(int i = 0; i < s.length(); i++){
            cnum *= 26;
            cnum += s[i] - 'A' + 1;
        }
        return cnum;
    }
};