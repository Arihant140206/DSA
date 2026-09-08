class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;
        int ans=0;
        int l=0,r;
        for(r=0;r<s.size();r++)
        {
            freq[s[r]]++;
            while(freq[s[r]]>1)
            {
                freq[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }return ans;
    }
};