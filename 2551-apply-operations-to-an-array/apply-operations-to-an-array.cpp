class Solution {
public:
    vector<int> applyOperations(vector<int>& nums)
 {
        int n= nums.size(); 

        for (int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i+1]) {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;  // keep only non-val elements
            
            }
        }

        vector<int> result;//whichever element is nonzero is put in the starting of the new vector called result which will be printed later
        for(int num:nums){
            if(num!=0)
            result.push_back(num);
        }  

        while(result.size()<n)
        result.push_back(0);
        return result; 
    
    }
};
