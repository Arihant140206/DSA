class Solution {
public:
//using recursion
    void helper(vector<char>&s,int start,int end){
        //base case
        if(start>=end)
        return;

        swap(s[start],s[end]);//working

        helper(s,start+1,end-1);


    }
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
};