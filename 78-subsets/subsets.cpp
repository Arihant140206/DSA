class Solution {
public:

void sequence(vector<int>& arr,int index, int n , vector<vector<int > >&ans,vector<int>temp)
{
    if(index==n)
    {
        ans.push_back(temp);
        return;
    }
    //not inculded (no)
    sequence(arr, index+1, n , ans,temp);
    //included
    temp.push_back(arr[index]);
    sequence(arr, index+1, n , ans,temp);

}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sequence(nums,0,nums.size(),ans,temp);

        return ans;
    }
};