class Solution {
public:
//stack ko use karke question kana hai (pratyush video 37 ),simply ek ek karke stack me push karo and keep checking the top elememt with the upcoming element of the string , if they are same pop the on e from the stack and keep moving ahead in string , keep doing it until the end ,. fin ally store the answer in res and reverse it in the end as stack will give ulta ans on popping and we want in form of string 
    string removeDuplicates(string s) {
        int n=s.size();
        stack<char>st;
        int i;
        string res;

        for(i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);

            //finmal ans me dalna and reverse karna 
        }
            while(!st.empty()){
                res.push_back(st.top());
                st.pop();
            }
            reverse(res.begin(),res.end());
            //

        return res;
    }
};