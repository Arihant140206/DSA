class Solution {
public:
    string add(string num1 , string num2){
        string ans;
        int index1 = num1.size()-1, index2 = num2.size()-1;
        int carry = 0;

        while(index1 >= 0 || index2 >= 0 || carry){
            int sum = carry;

            if(index1 >= 0){
                sum += num1[index1] - '0';
                index1--;
            }
            if(index2 >= 0){
                sum += num2[index2] - '0';
                index2--;
            }

            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addStrings(string num1, string num2) {
        if(num1.size() > num2.size())
            return add(num1, num2);
        else
            return add(num2, num1);
    }
};
