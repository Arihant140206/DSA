class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int left=0;
        int right=n-1;
        while(left<right){
            while(!isalnum(s[left])&&left<right)
            left++;
            while(!isalnum(s[right])&&left<right)
            right--;
            if(tolower(s[left])==tolower(s[right]))
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }return true;
    }
};