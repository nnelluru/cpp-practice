#include<iostream>
#include<vector>
#include<map>

using namespace std;

/*
   [3,2,1]
   [1,7,6]
   [2,7,7]

Grid: (I, J): (0,0) Value:3
Grid: (J, I): (0,0) Value:3
Grid: (I, J): (1,0) Value:1
Grid: (J, I): (0,1) Value:2
Grid: (I, J): (0,1) Value:2
Grid: (J, I): (1,0) Value:1
Grid: (I, J): (0,2) Value:1
Grid: (J, I): (2,0) Value:2
Count:0
 */

class Solution {
	public:
		int nwEqualPairs(vector<vector<int>>& grid) {
			int vec1Size = grid.size();

			int count = 0;
			for(int ou = 0; ou < vec1Size; ou++) {
				for(int in = 0; in < vec1Size; in++) {
					cout << "Grid: (I, J): (" << in <<"," << ou << ") Value:" << grid[in][ou]<< endl;
					cout << "Grid: (J, I): (" << ou <<"," << in << ") Value:" << grid[ou][in]<< endl;
					if(grid[in][ou] != grid[ou][in]) {
						continue;
					}
					if (in == vec1Size -1) {
						count++;
					}
				}
			}

			return count;
		}

		int equalPairs(vector<vector<int>>& grid) {
			map<vector<int>, int> counter;
			int row = grid.size(), col = grid[0].size(), ans = 0;
			for (vector<int> row : grid) {
				counter[row] += 1;
			}
			for (int i = 0; i < row; i++) {
				vector<int> column_list = {};
				for (int j = 0; j < col; j++) {
					column_list.push_back(grid[j][i]);
				}
				ans += counter[column_list];
			}
			return ans;
		}
};


int main() {
	Solution s;

	vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
	int count = s.equalPairs(grid);
	cout << "Count:" << count << endl;

	grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
	count = s.equalPairs(grid);
	cout << "Count:" << count << endl;

	grid = {{13,13},{13,13}};
	count = s.equalPairs(grid);
	cout << "Count:" << count << endl;
	return 0;
}
