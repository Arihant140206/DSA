class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n ;
        int start =0,end=arr.size()-1,mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(arr[mid]==target)
            return mid;
            else if(arr[mid]<=target)
            start=mid+1;
            else
            end=mid-1;
        }
        return start;
    }
};