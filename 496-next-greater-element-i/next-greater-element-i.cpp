class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<nums2.size();i++)
        {
            while(!st.empty()&&nums2[i]>nums2[st.top()])
            {
                mp[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
            mp[nums2[st.top()]]=-1;
        }
        //jo back gaye , jinka nahi mil paaya greater element unk0 -1 dedo
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }return ans;
    }
};