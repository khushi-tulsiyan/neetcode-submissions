class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinChanges(amount + 1, amount + 1);
        coinChanges[0] = 0;
        for(int i = 1; i<=amount; i++){
            for(int j = 0; j<coins.size(); j++){
                if(coins[j] <= i){
                    coinChanges[i] = min(coinChanges[i], coinChanges[i-coins[j]] + 1);
                }
            }
        }
        return coinChanges[amount] != amount+1 ? coinChanges[amount]: -1;
    }
};
