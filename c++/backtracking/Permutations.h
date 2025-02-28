#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <iostream>
#include <vector>

using namespace std;


class Permutation {

    public:

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    
    generatePermute(nums, used, current, ans);
    return ans;
}

void generatePermute(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& ans) {
    if (current.size() == nums.size()) {
        ans.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(nums[i]);
            generatePermute(nums, used, current, ans);
            current.pop_back();
            used[i] = false;
        }
    }
}
};

#endif