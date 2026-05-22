#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> tuitions(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> tuitions[i];
    }

    // Sort the tuitions in descending order
    std::sort(tuitions.begin(), tuitions.end(), std::greater<long long>());

    long long maxRevenue = 0;
    long long optimalTuition = 0;

    // Iterate over the sorted tuition fees
    for (int i = 0; i < N; ++i) {
        // Calculate revenue for the current tuition fee
        long long currentRevenue = tuitions[i] * (i + 1);
        if (currentRevenue > maxRevenue) {
            maxRevenue = currentRevenue;
            optimalTuition = tuitions[i];
        }
    }

    // Output the maximum revenue and the optimal tuition fee
    std::cout << maxRevenue << " " << optimalTuition << std::endl;

    return 0;
}
