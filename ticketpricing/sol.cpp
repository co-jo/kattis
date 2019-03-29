#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tickets[53][101];
int revenue[53][301];
int path[53][301];

#define MAX 1001

int main() {

    int n, w, k, v;
    scanf("%d %d\n", &n, &w);

    for (int i = 0; i <= 52; i++) {
        for (int j = 0; j <= 300; j++) {
            revenue[i][j] = -1;
        }
    }

    vector<vector<int>> sold(w+1);
    vector<vector<int>> prices(w+1);
    for (int i = w; i >= 0; i--) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            prices[i].push_back(v);
        }
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            sold[i].push_back(v);
        }

        scanf("\n");
    }

    for (int i = 0; i < prices[w].size(); i++) {
        if (revenue[w][sold[w][i]] <= sold[w][i] * prices[w][i]) {
            revenue[w][sold[w][i]] = sold[w][i] * prices[w][i];
            path[w][sold[w][i]] = prices[w][i];
        }
    }

    for (int i = w-1; i >= 0; i--) {
        for (int j = 0; j < sold[i].size(); j++) {
            for (int l = 0; l <= n+1; l++) {
                if (revenue[i+1][l] == -1) continue;
                int s = min(sold[i][j], n-l);
                if (revenue[i][l+s] < revenue[i+1][l] + s * prices[i][j]) {
                    revenue[i][l+s] = revenue[i+1][l] + s * prices[i][j];
                    path[i][l+s] = path[i+1][l];
                }
            }
        }
    }

    int sum = 0, price = 0;
    for (int i = w; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (sum <= revenue[i][j]) {
                sum = revenue[i][j];
                price = path[i][j];
            }
        }
    }

    printf("%d\n%d\n", sum, price);

    return 0;
}
