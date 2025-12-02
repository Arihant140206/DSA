class Solution {
public:
    void perms(int index,vector<vector<int>>& ans,vector<int>& arr){
        if(index==arr.size()){
            ans.push_back(arr);
            return;
        }

        for(int i=index;i<arr.size();i++){
            swap(arr[i],arr[index]);
            perms(index+1,ans,arr);
            swap(arr[i],arr[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;
        perms(0,ans,arr);
        return ans ;
    }
};