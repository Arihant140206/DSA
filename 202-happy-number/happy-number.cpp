class Solution {
public://funtion to get sum
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
//jab tak 1 nahi mil jaata tab tak sum dhundo 
        while (fast != 1) {
            slow = getNext(slow);

            fast = getNext(fast);
            fast = getNext(fast);
//agar loop mil gaya and sum =1 nahi hai toh false nahi toh true
            if (slow == fast && slow != 1) {
                return false;
            }
        }

        return true;
    }
};