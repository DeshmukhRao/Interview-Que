#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> A;
    int K;
    unordered_map<int, long long> dp; // Memoization for DP

    long long dfs(int node) {
        if (dp.find(node) != dp.end()) return dp[node]; // Return precomputed result

        long long fullCollect = A[node] - K;  // Option 1: Collect full value
        long long halfCollect = floor(A[node] / 2);  // Option 2: Collect half and affect children

        for (int child : tree[node]) {
            long long childValue = dfs(child);
            fullCollect += childValue; // Collect child normally
            halfCollect += floor(childValue / 2); // Apply floor(A[j] / 2) to child
        }

        return dp[node] = max(fullCollect, halfCollect); // Store result in DP table
    }

    long long treePoints(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> A, int K) {
        this->A = A;
        this->K = K;
        tree.resize(g_nodes);
        dp.clear(); // Clear DP table

        // Build adjacency list (tree structure)
        for (int i = 0; i < g_from.size(); i++) {
            tree[g_from[i]].push_back(g_to[i]);
        }

        // Start DFS from root (0)
        return dfs(0);
    }
};

int main() {
    int g_nodes = 4;
    vector<int> g_from = {0, 1, 2};
    vector<int> g_to = {1, 2, 3};
    vector<int> A = {10, 10, 3, 3};
    int K = 5;

    Solution sol;
    cout << sol.treePoints(g_nodes, g_from, g_to, A, K) << endl;
    return 0;
}
