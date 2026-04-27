class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        // Step 1: XOR all elements → gives a ^ b
        long long xorAll = 0;
        for(int x : nums){
            xorAll ^= x;
        }
        
        // Step 2: get rightmost set bit
        int diff = xorAll & (~(xorAll - 1));
        
        // Step 3: split into two groups
        int a = 0, b = 0;
        
        for(int x : nums){
            if(x & diff){
                // group 1
                a ^= x;
            } else {
                // group 2
                b ^= x;
            }
        }
        
        // Step 4: return result
        return {a, b};
    }
};