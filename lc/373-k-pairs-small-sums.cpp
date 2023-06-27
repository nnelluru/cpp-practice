#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int nums1Len = nums1.size();
        int nums2Len = nums2.size();

        multimap<int, vector<int>, less<int>> myMap;

        for(int n1:nums1) {
            for(int n2: nums2) {
                myMap.insert({n1+n2, {n1, n2}});
            }
        }

        vector<vector<int>> output;
        int count = 1;
        for(auto m: myMap) {
            if(count > k) {
                break;
            }
            output.push_back(m.second);
            count++;
        }

        return output;
    }
};

int main() {
	Solution s;
	vector<int> nums1 = {1, 7, 11};
	vector<int> nums2 = {2, 4, 6};

	vector<vector<int>> output = s.kSmallestPairs(nums1, nums2, 3);

	for(auto v: output) {
		cout << "[" << v[0] << "," << v[1] << "]" << endl;
	}

	return 0;
}
