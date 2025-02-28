#include <iostream>
#include "Subsets.h"

int main(){
    Subset* s = new Subset();
    vector<int> nums = {1,2,3};
    s->createSubset(nums);
    return 0;
}