#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for(int i=0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    indices.push_back(i);
                    indices.push_back(j);
                    break;
                } else {
                    cout << i << ":[" << nums[i] << "], " << j << ":[" << nums[j] << "]" << endl;
                }
            }
        }

        return indices;
    }

    vector<int> oTwoSum(vector<int>& nums, int target) {
	    unordered_map<int, int> ump;
	    for(int i = 0; i < nums.size(); i++) {
		if(ump.find(target - nums[i]) == ump.end()) {
			ump[nums[i]] = i;
		} else {
			return {ump[target-nums[i]], i};
		}
	    }

	    return {-1, -1};
    }
};

int main() {
	vector<int> nums{2,7, 11, 15};
	int target = 18;
	Solution s;
	vector<int> indices = s.oTwoSum(nums, target);
	cout << "[" << indices[0] << "," << indices[1] << "]" << endl;
	return 0;
}
