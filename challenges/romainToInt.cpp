class Solution {
public:
    std::map<const char, int> base {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int sum = 0;
        int lastAddition = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int currentAddition = base[s[i]];
            if (lastAddition > 0 && currentAddition < lastAddition) {
                lastAddition = 0;
                sum -= currentAddition;
            } else {
                lastAddition = currentAddition;
                sum += currentAddition;
            }           
        }
        return sum;
    }
};
