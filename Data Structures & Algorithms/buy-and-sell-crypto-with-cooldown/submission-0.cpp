class Solution {
public:
    unordered_map<string,int> maps;
    int maxProfit(vector<int>& prices) {
                    return dfs(0,true,prices);
    }
    int dfs(int i, bool buying,vector<int>& prices){
             if(i>= prices.size()) return 0;
             string key = to_string(i) + '-' + to_string(buying);
             if(maps.find(key)!=maps.end()) return maps[key];
             int cool = dfs(i+1,buying,prices);
             if(buying) {
                   int maxi1 = dfs(i+1,false,prices) - prices[i];
                   maps[key] = max(maxi1,cool);
             }
             else{
                 int maxi2 = dfs(i+2,true,prices) + prices[i];
                 maps[key] = max(maxi2,cool);
             }
             return maps[key];
    }
};
