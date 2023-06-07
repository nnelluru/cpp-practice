#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s = "123432678889";
	vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	cout << "String:" << s << endl;
	int count = 0;

	cout << "char at index 5:" << s[5] << endl;
	while(s[count] != '\0') {
		if(s[count] >= 48 && s[count] <= 57) {
			arr[s[count] - '0']++;
			count++;
		}
	}

	for(int i = 0;i < 10; i++) {
		cout << i << "-" << arr[i] << endl;
	}
	return 0;
}
