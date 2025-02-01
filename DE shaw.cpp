#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> ratings;

// Check if we can choose (n-2) products ensuring min(mx[]) >= X
bool isPossible(int X) {
    vector<vector<int>> validRatings(n);  // Store valid ratings per customer

    // Step 1: Filter valid ratings
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ratings[i][j] >= X) {
                validRatings[i].push_back(ratings[i][j]);
            }
        }
    }

    // Step 2: Each customer should have at least one valid product
    for (int i = 0; i < n; i++) {
        if (validRatings[i].size() < (n - 2)) return false;  // Not enough products
    }

    // Step 3: Select the (n-2) best products per customer
    vector<int> maxRatings;
    for (int i = 0; i < n; i++) {
        sort(validRatings[i].begin(), validRatings[i].end(), greater<int>()); // Sort descending
        maxRatings.push_back(validRatings[i][0]); // Pick best available rating
    }

    // Step 4: Check the minimum of these max values
    return (*min_element(maxRatings.begin(), maxRatings.end())) >= X;
}

// Function to find the maximum possible value of min(mx[])
int maximizeMinMax() {
    int low = 0, high = 1e9, best = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            best = mid;  // Try higher
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return best;
}

int main() {
    cin >> n >> m;
    ratings.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ratings[i][j];
        }
    }

    cout << maximizeMinMax() << endl;
    return 0;
}
