#include <bits/stdc++.h>
using namespace std;

int n, erase, root, leafCount = 0;
vector<int> parent;
vector<vector<int>> children;

void dfs(int node) {
    if (node == erase) return;

    bool hasChild = false;
    for (int child : children[node]) {
        if (child == erase) continue;
        hasChild = true;
        dfs(child);
    }

    if (!hasChild) leafCount++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    parent.resize(n);
    children.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> parent[i];
        if (parent[i] == -1)
            root = i;
        else
            children[parent[i]].push_back(i);
    }

    cin >> erase;

    if (erase == root) {
        cout << 0 << '\n';
    } else {
        dfs(root);
        cout << leafCount << '\n';
    }

    return 0;
}