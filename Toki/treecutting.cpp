// H. Tree Cutting
// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// You are given a tree with n
//  vertices.

// A hero k
//  times do the following operation:

// Choose some edge.
// Remove it.
// Take one of the two remaining parts and delete it.
// Write the number of vertices in the remaining part.
// You are given an initial tree and the a sequence of written numbers. Find the number of ways to make operations such that the written numbers are equal to the given numbers. Due to the answer can be big, find it by modulo 998244353
// . Two ways are considered different, if on some operation edge or remaining part are selected differently.

// Input
// The first line contains a single integer n
//  (2≤n≤5000
// ) — the number of vertices.

// Each of the next n−1
//  lines contains two integers s
// , f
//  (1≤s,f≤n
// , s≠f
// ) — description of edge (s,f)
// .

// Next line contains a single integer k
//  (1≤k≤min(6,n−1)
// ) — the number of operations.

// Next line contains k
//  integers s1,s2,…,sk
//  (n>s1>s2>…>sk
// ) — written numbers.

// Output
// Print a single integer — the answer to the problem by modulo 998244353
// .

// Examples
// inputCopy
// 3
// 1 2
// 2 3
// 2
// 2 1
// outputCopy
// 4
// inputCopy
// 7
// 2 1
// 3 2
// 4 1
// 5 3
// 6 4
// 7 4
// 2
// 4 2
// outputCopy
// 2
// inputCopy
// 7
// 1 2
// 1 3
// 1 4
// 2 5
// 3 6
// 4 7
// 1
// 2
// outputCopy
// 3
// inputCopy
// 7
// 1 2
// 1 3
// 1 4
// 2 5
// 3 6
// 4 7
// 4
// 6 5 2 1
// outputCopy
// 24
// inputCopy
// 8
// 1 2
// 2 3
// 3 4
// 3 5
// 3 6
// 3 7
// 3 8
// 2
// 7 4
// outputCopy
// 0
// Note
// In the first test there are four possible ways to make operations:

// Remove the edge (1,2)
//  and delete vertex 1
// . Remove the edge (2,3)
//  and delete vertex 2
// .
// Remove the edge (1,2)
//  and delete vertex 1
// . Remove the edge (3,2)
//  and delete vertex 3
// .
// Remove the edge (3,2)
//  and delete vertex 3
// . Remove the edge (1,2)
//  and delete vertex 1
// .
// Remove the edge (3,2)
//  and delete vertex 3
// . Remove the edge (2,1)
//  and delete vertex 2
// .
// In the second test there are two possible ways to make operations:

// Remove the edge (4,1)
//  and delete the part with vertex 4
// . Remove the edge (2,3)
//  and delete the part with vertex 2
// .
// Remove the edge (4,1)
//  and delete the part with vertex 4
// . Remove the edge (3,2)
//  and delete the part with vertex 3
// .

// Solution:

// Let's start by analyzing what happens to the tree after one operation. We can think of the operation as cutting an edge and then deleting one of the two resulting parts. Suppose that the edge we cut connects vertices u and v, and let x and y be the sizes of the two parts we get after the cut. Depending on which part we delete, we either get a tree with x vertices and a tree with y vertices, or vice versa.

// Now, let's think about how we can construct a sequence of operations that results in a given sequence of sizes. Suppose that we want to get the sequence s[1], s[2], ..., s[k], where s[i] is the size of the remaining part after the i-th operation. We can start by choosing an arbitrary edge and cutting it, and then deleting one of the resulting parts. Let's say that we delete the part with x vertices. Then, we need to find a way to cut the remaining tree into two parts of sizes s[2] and n - s[1], respectively, and repeat the process. We can continue in this way until we've performed k operations.

// It turns out that we can solve the problem by dynamic programming. Let f[i][j] be the number of ways to cut a subtree rooted at node i into two parts of sizes j and n - j, respectively, using a single cut. We can compute f[i][j] using a simple dynamic programming algorithm that runs in O(n^3) time:

// First, we compute the size of the subtree rooted at each node using a depth-first search.
// Then, we compute f[i][j] for each node i and each j from 1 to the size of the subtree rooted at i. To do this, we consider all edges that go from i to one of its children j, and for each such edge, we compute the size of the subtree rooted at j and the size of the remaining subtree (which is the size of the subtree rooted at i minus the size of the subtree rooted at j). We then add up f[j][k] * f[i][j-k] for all k from 1 to the size of the subtree rooted at j, which gives us the number of ways to cut the subtree rooted at i into two parts of sizes k and n - k, respectively, using the edge (i, j). We also need to add the case where we don't use any of the edges going from i to its children, which corresponds to cutting the subtree rooted at i into two parts of sizes j and n - j using the edge connecting i to its parent.
// Once we have computed f[i][j] for all i and j, we can solve the problem by another dynamic programming algorithm that runs in O(n^3 * k) time. Let g[i][j][k] be the number of ways to perform the first k operations starting from the subtree rooted at i, where the remaining part after the first operation has size j. We can compute g[i][j][k] using the following recurrence:

// g[i][j][k] = sum(f[i][u] * g[v][n - j][k - 1] + f[i][n - u] * g[v][j][k - 1] for all edges (i, v) and all u from 1 to the size of the subtree rooted at i)

// Here, we consider all edges going from i to its children v, and we compute the size of the two parts we get after cutting the edge (i, v). We then add up the number of ways to perform the first k - 1 operations starting from the subtree rooted at v, where the remaining part after the first

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int mod = 998244353;

int n, k;
int s[N];
int dp[N][N][N];
int f[N][N];
vector < int > g[N];

void dfs(int u, int p) {
    f[u][1] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[u][i][j] = (dp[u][i][j] + 1LL * f[u][i] * f[v][j]) % mod;
            }
        }
        for (int i = 1; i <= n; i++) {
            f[u][i] = (f[u][i] + f[v][i]) % mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
    }
    dfs(1, 0);
    dp[1][s[1]][s[1]] = 1;
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int u = 1; u <= n; u++) {
                for (int v : g[u]) {
                    int x = f[v][j];
                    int y = f[v][n - j];
                    dp[u][j][n - j] = (dp[u][j][n - j] + 1LL * dp[v][x][y] * f[u][j]) % mod;
                    dp[u][n - j][j] = (dp[u][n - j][j] + 1LL * dp[v][y][x] * f[u][n - j]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[1][s[k]][i]) % mod;
    }
    cout << ans << '\n';
    return 0;
}