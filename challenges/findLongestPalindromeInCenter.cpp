#include <iostream>
#include <string>

// find a palindrome in the centers up to 2 space left or right of center
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string::iterator front = s.begin();
        std::string::iterator back = --s.end();
        std::string::iterator start = s.end();
        std::string::iterator end = start;

        while ((front != back) && ((front + 1) != back && front != s.end() && back != s.end())) {
            // does front match back
            if (*front == *back) {
                std::cout << "front = back" << std::endl;
                // if so then set start and end and increment both pointers
                if (start == s.end()) {
                    std::cout << "front = end so saving" << std::endl;
                    start = front;
                }
                if (end == s.end()) {
                    std::cout << "back = end so saving" << std::endl;
                    end = back;
                }
                std::cout << "increment fornt and decrementing back since match" << std::endl;
                front++;
                back--;
            } else {
                std::cout << *front << " doesn't match " << *back << std::endl;
                // if left has match
                if (*(front + 1) == *back) {
                    std::cout << "front matches back so increment front" << std::endl;
                    front++;
                    // save pointers and advance
                    if (start == s.end()) {
                        std::cout << "start was empty so saving front" << std::endl;
                        start = front;
                    }
                 // else if right has match
                } else if (*(back - 1) == *front) {
                    std::cout << "back matches  front so decrementing back" << std::endl;
                    back--;
                    // save pointers and advance
                    if (end == s.end()) {
                        std::cout << "end was empty so saving back" << std::endl;
                        end = back;
                    }
                } else {
                    std::cout << "neither front " << *front << " nor back " << *back << " matched so advancing pointers and reseting start and end" << std::endl;
                    front++;
                    back--;
                    start = s.end();
                    end = s.end();
                }
            }
        }
        if (front != s.end() && back != s.end()) {
            //std::cout << std::distance(s.begin(), start) << " - " << *start <<" ---- " << std::distance(s.begin(), end) << " - " << *end << std::endl;
            std::string p = s.substr(std::distance(s.begin(), start), std::distance(start, end) + 1);
            std::cout << p << std::endl;
        }
        return "";
    }
};

int main(int argc, char* argv[]) {
    auto solution = new Solution();
    for (auto i = 1; i < argc; i++) {
      solution->longestPalindrome(std::string(argv[i]));
      // std::cout << argv[i] << " -> " << solution->longestPalindrome(std::string(argv[i])) << std::endl;
    }
    return 0;
}
