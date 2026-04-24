class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        
        //nums2 ke saare lemenets ko hashmap =me store karo
        for(int i=0;i<nums2.size();i++){
            while(!st.empty()&&nums2[i]>st.top()){
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        //hashmap ban gaya ab answer 
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};