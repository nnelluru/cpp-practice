#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		bool isPalindromeWithStringConversion(int x) {
			string s = to_string(x);

			int idx = 0;
			int strLen = s.length();
			while(idx < strLen/2) {
				if(idx == strLen - 1 - idx) {
					break;
				} else if(s[idx] != s[strLen - 1 - idx]) {
					return false;
				}
				idx++;
			}

			return true;
		}

		bool isPalindrome(int x) {

		}
};

int main() {
	Solution sol;

	//int number = 121;
	int number = 123;
	bool isPalindrome = sol.isPalindrome(number);

	cout << "Number:" << number << " is " << (isPalindrome ? "" : "not ") << "a palindrome" << endl;
	return 0;
}
