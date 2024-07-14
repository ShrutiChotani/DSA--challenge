# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int remain = accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0);
        if (remain < 0) return -1;

        int start = 0;
        int currRemain = 0;
        for (int i = 0; i < n; ++i) {
            currRemain += gas[i] - cost[i];
            if (currRemain < 0) {
                currRemain = 0;
                start = i + 1;
            }
        }
        
        return start;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int result = solution.canCompleteCircuit(gas, cost);
    if (result == -1) {
        cout << "Cannot complete the circuit." << endl;
    } else {
        cout << "Start from index: " << result << endl;
    }
    return 0;
}
