#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			double ans = 0;
			vector<int> mergedArray;

			merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(mergedArray));
			/*set<int> s;
			for(auto & n: mergedArray)
				s.insert(n);
			mergedArray.assign(s.begin(), s.end());
			*/
			/*
			cout << "merged and printing" << endl;
			
			for(auto &n: mergedArray) {
				cout << n;
			}*/

			int mLen = mergedArray.size();

			if(mLen%2 == 0) {
				ans = ((double)mergedArray[mLen/2] + (double)mergedArray[(mLen/2)-1])/2;
			} else {
				ans = mergedArray[mLen/2];
			}

			cout << ans << endl;

			return ans;
		}
};

int main() {
	Solution s;
	
	vector<int> nums1 = {1, 2, 3};
	vector<int> nums2 = {2};
	double median = s.findMedianSortedArrays(nums1, nums2);
	cout << "Median:" << median << endl;

	nums1 = {1, 2};
	nums2 = {3, 4};
	median = s.findMedianSortedArrays(nums1, nums2);
	cout << "Median:" << median << endl;


	return 0;
}
