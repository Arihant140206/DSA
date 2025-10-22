class Solution {
public:
    bool checkString(string s) {
        bool seenB = false;

        for(char ch : s){
            if(ch== 'b')
            seenB = true ;

            else if(ch=='a'&& seenB==true)
            return false ;

        }
        return true;
        
    }
};