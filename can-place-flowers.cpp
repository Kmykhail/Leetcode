//
// Created by mykhailenko on 17.07.21.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int cur = 0; cur < flowerbed.size() && n > 0; ++cur) {

            if (!flowerbed[cur]) {
                auto prev_cond = (cur - 1 < 0 || (cur - 1 >= 0 && !flowerbed[cur - 1]));
                auto next_cond = (cur + 1 >= flowerbed.size() || (cur + 1 < flowerbed.size() && !flowerbed[cur + 1]));

                if (prev_cond && next_cond) {
                    flowerbed[cur] = 1;
                    --n;
                }
            }
        }

        return !n;
    }
};