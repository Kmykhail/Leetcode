//
// Created by mykhailenko on 09.07.21.
//

//We are given an array asteroids of integers representing asteroids in a row.
//
//For each asteroid, the absolute value represents its size, and the sign represents its direction
//(positive meaning right, negative meaning left). Each asteroid moves at the same speed.
//
//Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will
//explode. If both are the same size, both will explode. Two asteroids moving in the same direction
//will never meet.

//Example 1:
//Input: asteroids = [5,10,-5]
//Output: [5,10]
//Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

//Example 2:
//Input: asteroids = [8,-8]
//Output: []
//Explanation: The 8 and -8 collide exploding each other.

//Example 3:
//Input: asteroids = [10,2,-5]
//Output: [10]
//Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

//Example 4:
//Input: asteroids = [-2,-1,1,2]
//Output: [-2,-1,1,2]
//Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.

#include <vector>
#include <stack>
#include <map>
#include <math.h>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(const vector<int>& asteroids) {
        stack<int> m_stack;

        auto collision_fn = [&m_stack](const int val) -> bool{
            bool need_to_insert = true;

            while (!m_stack.empty() && val < 0) {
                auto top = m_stack.top();
                auto abs_val = abs(val);

                if (top < 0 || top > abs_val) {
                    need_to_insert = top > abs_val ? false : need_to_insert;
                    break;
                }

                m_stack.pop();
                if (abs_val == top) {
                    need_to_insert = false;
                    break;
                }
            }

            return need_to_insert;
        };

        for (const auto &it: asteroids) {
            if (collision_fn(it)) {
                m_stack.emplace(it);
            }
        }

        vector<int> res(m_stack.size());

        for (int i = m_stack.size() - 1; !m_stack.empty(); --i) {
            res[i]=m_stack.top();
            m_stack.pop();
        }

        return res;
    }
};

int main() {
    map<vector<int>, vector<int>> tests {
            {{5,10,-5}, {5,10}},
            {{8,-8}, {}},
            {{10,2,-5}, {10}},
            {{-2,-2,1,-2}, {-2,-2,-2}},
            {{-2,-2,1,-1}, {-2,-2}},
            {{-2,-1,1,2}, {-2,-1,1,2}}
    };

    Solution qw;
    for ( auto &[test, expected]: tests) {
        if (auto res = qw.asteroidCollision(test); res != expected) {
            stringstream input_result;
            stringstream exp_result;
            copy(test.begin(), test.end(), std::ostream_iterator<int>(input_result, " "));
            copy(expected.begin(), expected.end(), std::ostream_iterator<int>(exp_result, " "));

            cout << "Error, Input: " << input_result.str() << ", Expected: "<< exp_result.str() << endl;
            break;
        }
    }
}