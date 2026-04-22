class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> st;  // stores current path
        
        for(int i = 0; i < logs.size(); i++) {
            
            if(logs[i] == "../") {
                // go to parent → pop if possible
                if(!st.empty()) {
                    st.pop();
                }
            }
            else if(logs[i] == "./") {
                // stay in same folder → do nothing
                continue;
            }
            else {
                // go into a folder → push
                st.push(logs[i]);
            }
        }
        
        // number of folders deep = operations needed to go back
        return st.size();
    }
};