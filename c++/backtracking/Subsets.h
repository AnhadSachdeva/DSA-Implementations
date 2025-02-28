#ifndef SUBSET_H
#define SUBSET_H


#include <iostream>
#include <vector>

using namespace std;

class Subset{
    void generateSubset(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans){
        ans.push_back(current);


        for(int i = start; i < nums.size(); i++){
            current.push_back(nums[i]);
            generateSubset(i+1,nums,current,ans);
            current.pop_back();
        }
    }

    public:

    vector<vector<int>> createSubset(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> current;
        generateSubset(0,nums,current,ans);
        for(auto sub : ans){
            for(auto num : sub){
                cout << num << ' ';
            }
            cout << endl;
        }
        return ans;
    }



};




#endif