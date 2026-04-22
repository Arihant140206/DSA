class Solution {
public:
    string makeGood(string s) {
          int i;
        stack<char>st;
        string res;
        int n=s.size();

        for(i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(abs(st.top() - s[i]) == 32){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        //answer banana
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();

        }
        reverse(res.begin(),res.end());
        return res;
    }
};