class Solution {
    public:
        vector<vector<int>> powerset;
        vector<int> sets;
        
        void generateSets(vector<int>& nums, int index){
            powerset.push_back(sets);
            for(int i=index; i< nums.size(); i++){
                sets.push_back(nums[i]);
                generateSets(nums, i+1);
                sets.pop_back();
            }
        }
        
        vector<vector<int>> subsets(vector<int>& nums) {
            generateSets(nums, 0);
            return powerset;
        }
};