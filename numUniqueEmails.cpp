#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> res;

        for (const auto &email: emails) {
            auto pos = email.find('@');
            if (pos == string::npos) continue;

            string local_name;
            for (const auto &tmp_local: email.substr(0, pos)) {
                if (tmp_local == '.') continue;
                if (tmp_local == '+') break;

                local_name += tmp_local;
            }
            res.emplace(local_name + email.substr(pos, email.size()));
        }

        return (int)res.size();
    }
};