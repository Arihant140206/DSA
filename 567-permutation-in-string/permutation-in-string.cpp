class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
        return false; 

        int l=0,r;
        unordered_map<char,int>s1freq;
        for(int i=0;i<s1.size();i++)
        {
            s1freq[s1[i]]++;
        }
        unordered_map<char,int>s2freq;
        for(r=0;r<s2.size();r++)
        {
            s2freq[s2[r]]++;
            if(r-l+1>s1.size())
            {
                s2freq[s2[l]]--;
                if(s2freq[s2[l]]==0)
                s2freq.erase(s2[l]);
                l++;
            }
            if(r-l+1==s1.size())
            {
                if(s1freq==s2freq)
                return true;
            }
        }return false;
    }
};