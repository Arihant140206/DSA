class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // Track minimum price so far (to buy)
        int maxProfit = 0;        // Track maximum profit

        for (int price : prices) {
            // Update minimum price
            if (price < minPrice)
                minPrice = price;

            // Update max profit if selling today gives more profit
            else if (price - minPrice > maxProfit)
                maxProfit = price - minPrice;
        }

        return maxProfit;
    }
};
