#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

double maximumValue(vector<pair<int, int>>& items, int n, int W) // Corrected parameter name
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector<double> ones(n);
    for (int i = 0; i < n; ++i) {
        ones[i] = static_cast<double>(items[i].second) / items[i].first; // Using static_cast for clarity
    }
    vector<vector<double>> v;
    for (int i = 0; i < n; ++i) {
        v.push_back({ones[i], static_cast<double>(items[i].first), static_cast<double>(items[i].second)}); // Explicitly convert weight and value to double
    }
    sort(v.rbegin(), v.rend()); // Sort in descending order

    double profit = 0.0;
    int i = 0;
    while (W > 0 && i < n) {
        if (v[i][1] <= W) {
            W -= v[i][1];
            profit += v[i][2];
        } else {
            double ratio = static_cast<double>(W) / v[i][1];
            profit += ratio * v[i][2];
            W = 0;
        }
        ++i;
    }
    return profit;
}

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}