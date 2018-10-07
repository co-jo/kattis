#include <vector>
#include <iostream>

using namespace std;

int main() {

    int image[20][20];
    int kernel[20][20];
    int flipped[20][20];

    int ih, iw, kh, kw;
    cin >> ih >> iw >> kh >> kw;

    vector<vector<int>> convo((ih - kh + 1), vector<int>((iw - kw + 1), 0));
    // Iamge
    for (int i = 0; i < ih; i++) {
        for (int j = 0; j < iw; j++) {
            int ele;
            cin >> ele;
            image[i][j] = ele;
        }
    }
    // Kernel
    for (int i = 0; i < kh; i++) {
        for (int j = 0; j < kw; j++) {
            int ele;
            cin >> ele;
            kernel[i][j] = ele;
        }
    }

    // Really confusing soltuion, more straight foward to just input into
    // the array in their translated positions.
    int m = 0, n = 0;
    for (int k = kw - 1; k >= 0; k--) {
        for (int l = kh - 1; l >= 0; l--) {
            for (int i = 0; i < ((ih - kh) + 1); i++) {
                for (int j = 0; j < ((iw - kw) + 1); j++) {
                    convo[i][j] += (kernel[l][k]) * image[i + n][j + m];
                }
            }
            n += 1;
        }
        n = 0;
        m += 1;
    }

    for (int i = 0; i < ((ih - kh) + 1); i++) {
        for (int j = 0; j < ((iw - kw) + 1); j++) {
            cout << convo[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
