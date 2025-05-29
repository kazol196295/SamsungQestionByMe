#include<bits/stdc++.h>
using namespace std;

int n, ar[20], visited[20], max_ans;

void fun(int shot, int ans) {
    if (shot == n) {
        max_ans = max(max_ans, ans);
        return;
    }

    int original_ans = ans;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;

            // Default neighbors are 1
            int left = 1, right = 1,lf=0,rf=0;

            // Find left unvisited
            for (int j = i - 1; j >= 0; j--) {
                if (!visited[j]) {
                    lf=1;
                    left = ar[j];
                    break;
                }
            }

            // Find right unvisited
            for (int j = i + 1; j < n; j++) {
                if (!visited[j]) {
                    rf=1;
                    right = ar[j];
                    break;
                }
            }
            if(!lf && !rf)ans+=ar[i];
            else ans += left * right;

            fun(shot + 1, ans);

            // Backtrack
            ans = original_ans;
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        visited[i] = 0;
    }
    max_ans = INT_MIN;
    fun(0, 0);
    cout << max_ans << endl;
    return 0;
}
