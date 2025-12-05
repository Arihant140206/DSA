class Solution {
public:
    bool isPalindrome(string s) {
        string final;
        for(char c :s){
            if(isalnum(c)){
                final+=tolower(c);
            }
        }
        int left=0;
        int right=final.size()-1;
        while(left<right){
            if(final[left]!=final[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};