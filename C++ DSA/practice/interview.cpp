#include <iostream>
#include <vector>

using namespace std;

int peak_output(int N, vector<int>& workload) {
    int current_streak = 0;
    int peak_output = 0;

    for (int i = 0; i < N; i++) {
        if (workload[i] > 6) {
            current_streak++;
        } else {
            current_streak = 0;
        }
        if (current_streak > peak_output) {
            peak_output = current_streak;
        }
    }
    return peak_output;
}
int main() {
    int N;
    cin >> N;
    vector<int> workload(N);
    for (int i = 0; i < N; i++) {
        cin >> workload[i];
    }
    int result = peak_output(N, workload);
    cout << result << endl;
    return 0;
}
