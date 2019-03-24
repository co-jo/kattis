#include <iostream>
#include <vector>

using namespace std;

vector<int> link(1000000, 0);
vector<int> children(1000000, 1);

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (children[a] < children[b]) swap(a, b);
    children[a] += children[b];
    link[b] = a;
}

int main() {

    int n, q;
    scanf("%d %d\n", &n, &q);

    for (int i = 0; i < n; i++) link[i] = i;

    int a, b;
    char query;
    for (int i = 0; i < q; i++) {
        scanf("%c %d %d\n", &query, &a, &b);
        if (query == '?') {
            if (same(a, b)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else {
            unite(a, b);
        }
    }

    return 0;
}
