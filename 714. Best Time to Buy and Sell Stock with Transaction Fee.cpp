//TLE
//20 / 44 test cases passed.
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int N = prices.size();
        vector<int> profits(N, 0);
        int last = -1;
        
        for(int i = 0; i < N; i++){
            int notUseBefore = prices[i] - fee - 
                *min_element(prices.begin(), prices.begin()+i);
            int noOp = (i > 0) ? profits[i-1] : 0;
            
            // int useBefore =  prices[i] - fee - 
                // *min_element(prices.begin()+last+1, prices.begin()+i) + 
                // ((last > 0) ? profits[last] : 0);
            int useBefore = 0;
            for(int last = 0; last < i; last++){
                 useBefore = max(useBefore, 
                    prices[i] - fee - 
                    *min_element(prices.begin()+last+1, prices.begin()+i) +
                    ((last > 0) ? profits[last] : 0)
                    );
            }
            
            if(max(notUseBefore, useBefore) > noOp){
                last = i;
            }
            profits[i] = max({notUseBefore, useBefore, noOp});
            
            // cout << profits[i] << endl;
        }
        
        return profits[N-1];
    }
};

//Approach #1: Dynamic Programming
//Runtime: 148 ms, faster than 32.31% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
//Memory Usage: 13 MB, less than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
//time: O(N), space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            /*
            cash[i] = cash[i-1]: do nothing
            cash[i] = hold+prices[i]-fee: sell the stock held in last day
            */
            cash = max(cash, hold + prices[i] - fee);
            /*
            hold[i] = hold[i-1]: do nothing
            hold = cash[i-1] - prices[i]: buy stock today
            */
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};
