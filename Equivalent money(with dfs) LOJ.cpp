#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> money;

void dfs(int node, int &component_size, int &component_money) {
    visited[node] = true;
    component_size++;
    component_money += money[node];

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, component_size, component_money);
        }
    }
}

string equalizing_money(int n) {
    int total_money = 0;
    
    // Calculate total money in the entire graph
    for (int i = 0; i < n; i++) {
        total_money += money[i];
    }

    // If total money is not divisible by n, it's impossible to equalize
    if (total_money % n != 0) {
        return "No";
    }

    int target_money = total_money / n;

    // Traverse each connected component
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int component_size = 0;
            int component_money = 0;
            dfs(i, component_size, component_money);

            // Check if the total money in this component can be equally distributed
            if (component_money % component_size != 0) {
                return "No";
            }

            // Check if the money per person in this component matches the global target
            if (component_money / component_size != target_money) {
                return "No";
            }
        }
    }

    return "Yes";
}

int main() {
    int t;
    cin >> t;

    for (int case_num = 1; case_num <= t; case_num++) {
        int n, m;
        cin >> n >> m;

        money.assign(n, 0);
        graph.assign(n, vector<int>());
        visited.assign(n, false);

        for (int i = 0; i < n; i++) {
            cin >> money[i];
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--;  // Convert to zero-based indexing
            v--;  // Convert to zero-based indexing
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        string result = equalizing_money(n);
        cout << "Case " << case_num << ": " << result << endl;
    }

    return 0;
}  