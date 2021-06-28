class Solution {
	public:
		vector<vector<int>> combinationSum(vector<int>&  candidates, int target) {
			vector<int> combination;
			vector<vector<int>> result;
			backtrack(candidates, combination, result, target, 0);
			return result;
		}
	private:
		void backtrack(vector<int>& candidates, vector<int>& combination, vector<vector<int>& result, int target, int i) {
			if(target <= 0) {
				if(target == 0)  
					result.push_back(combination); 
				return;
			}
			for(int j = i; j < candidates.size(); j ++ ) {
				combination.push_back(candidates[j]);
				backtrack(candidates, combination, result, target - candidates[j], j);
				combination.pop_back();
			}
		}
};