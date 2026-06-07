class Solution {
public:
    unordered_map<string,int> maps;
    int rob(vector<int>& nums) {
            return dfs(0,true,nums);
    }
    int dfs(int i,bool canrob, vector<int>& nums){
              if(i>=nums.size()) return 0;
              string key = to_string(i)+ "-" + to_string(canrob);
              if(maps.find(key)!=maps.end()){
                   return maps[key];
              }
              if(canrob) maps[key] = max(dfs(i+2,true,nums)+nums[i],dfs(i+1,true,nums));
              else maps[key] = dfs(i+1,true,nums) ;
              return maps[key];
    }
};
