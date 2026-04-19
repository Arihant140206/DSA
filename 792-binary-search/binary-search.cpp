/*class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==target)
             {return mid;}
            else if(nums[mid]<target)
            left=mid+1;
            else
            right=mid-1;
        }
        return -1;
    }
};*///normal way abv , recursion way below

class Solution {
public:
    
    // recursive function
    int binarysearch(vector<int>& arr, int start, int end, int target) {
        // base case
        if(start>end)
        return -1;

        // find mid
        int mid=start+(end-start)/2;

        // check mid == target
        if(arr[mid]==target)
        return mid;
        else if(arr[mid]<target)
        return binarysearch(arr,mid+1,end,target);
        else
        return binarysearch(arr,start,mid-1,target);


    }

    int search(vector<int>& arr, int target) {
        // call helper with full range
        return binarysearch(arr,0,arr.size()-1,target);
    }
};
