class Solution {
public:
    string build(string s){
        stack<char>st;
        for(char c:s){
            if(c!='#'){
                st.push(c);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
};