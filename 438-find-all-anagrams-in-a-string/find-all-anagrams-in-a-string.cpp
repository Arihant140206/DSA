class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int l=0,r=0;
        unordered_map<char,int>pfreq;
        for(int i=0;i<p.size();i++)
        pfreq[p[i]]++;
        unordered_map<char,int>wfreq;
        for(r=0;r<s.size();r++)
        {
            wfreq[s[r]]++;

            if(r-l+1>p.size()){
                    wfreq[s[l]]--;
                    if(wfreq[s[l]]==0)
                    wfreq.erase(s[l]);

                    l++;
                }
            if(r-l+1==p.size())
            {
                if(wfreq==pfreq){
                ans.push_back(l);
                }
            }
        }return ans;



    }
};