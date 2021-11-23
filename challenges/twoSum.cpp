#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> x {}; 
    	for (int i = 0, curr = 0; i < nums.size() &&  curr < nums.size(); i++ ) {
    	    if (i == curr) continue;
    	    if (nums[curr] + nums[i] == target) {
    	        x.push_back(curr);
    	        x.push_back(i);
    	        break;
    	    }   
    	    if (i == nums.size() - 1) {
    	        curr += 1;
    	        i = 0;
    	    }    
    	}   
    	return x;
    }
};

int main () {
	int t = 5;
	vector<int> v { 5, 4, 3, 1, 10 };
	Solution s{};
	for ( auto value : v ) {
		cout << value;
		cout.width(3);
	}
	cout << endl;
	vector<int> result = s.twoSum(v, t);
	cout << "Target: " << t << endl;
	cout << "Indexes: " << "[" << result.front() << "," << result.back() << "]" << endl;
}
