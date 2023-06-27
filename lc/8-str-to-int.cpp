#include<limits.h>
#include<iostream>
#include<string>

using namespace std;

class Solution {
	public:
		int myAtoi(string s) {
			int len = s.length();
			long int output = 0;
			bool isNegative = false;
			bool isPositive = false;
			bool hasDecimal = false;
			long int decimalDivisor = 1;
			for(int i = 0; i < len; i++) {
				if(s[i] == ' ') continue;
				else if( s[i] == '+') {
					if(isNegative) break;
					isPositive = true;
				} else if(s[i] == '-') {
					if(isPositive) break;
					isNegative = true;
				} else if(s[i] == '.') break;//hasDecimal = true; 
				else if(s[i] >= 48 && s[i] <= 57) {
					int d = s[i] - '0';
					cout << "d:" << d << endl;
					if(hasDecimal) 
						decimalDivisor = decimalDivisor * 10;
					output = output * 10 + d;

				}
				else if((s[i] < 48 || s[i] > 57) && output == 0) break;
			}

			if(isNegative) output = output * -1;

			if(hasDecimal) output = output / decimalDivisor;

			if(output < INT_MIN) {
				output = INT_MIN;
			} else if (output > INT_MAX) {
				output = INT_MAX;
			}

			return (int)output;
		}
};

int main() {
	Solution s;
	string str = "-42";
	int val = s.myAtoi(str);
	cout << "Output:" << val << endl;

	str = "99";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;

	str = "+88";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;

	str = "  -2299";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;

	str = "   99abc";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;

	str = "words 987";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;

	str = "3.141";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;
	
	str = "=-987";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;
	
	str = "-+987";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;
	
	str = "words 987";
	val = s.myAtoi(str);
	cout << "Output:" << val << endl;
	return 0;
}
