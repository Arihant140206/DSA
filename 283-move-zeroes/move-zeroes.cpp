class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int left = 0;

    for(int right = 0; right < n; right++) {
    if(arr[right] != 0) {
        // do something with left a
        swap(arr[left],arr[right]);
        left++;
    }
}
    }
};