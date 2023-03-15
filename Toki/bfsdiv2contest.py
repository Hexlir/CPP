from collections import defaultdict

def solve(n, a, edges):
    # Build the adjacency list of the tree
    adj_list = defaultdict(list)
    for u, v in edges:
        adj_list[u].append(v)
        adj_list[v].append(u)

    # Find the vertex distances for each vertex in the tree
    vertex_distances = []
    for i in range(1, n+1):
        # Initialize the distance list with -1 for all vertices
        distances = [-1] * n
        queue = [i]
        distances[i-1] = 0
        while queue:
            u = queue.pop(0)
            for v in adj_list[u]:
                if distances[v-1] == -1:
                    distances[v-1] = distances[u-1] + 1
                    queue.append(v)
        # Sort the distances in increasing order
        distances.sort()
        vertex_distances.append(distances)

    # Check which vertices are good vertices
    good_vertices = []
    for i in range(1, n+1):
        if sorted(a) == vertex_distances[i-1]:
            good_vertices.append(i)

    # If there is only one vertex left without a label, label it with any integer not in the list a
    if len(good_vertices) == 1:
        vertex_labels = set(a)
        for i in range(1, n+1):
            if i not in vertex_labels:
                good_vertices.append(i)
                break

    # Output the results
    print(len(good_vertices))
    print(*sorted(good_vertices))

# Read the input
n = int(input())
a = list(map(int, input().split()))
edges = [tuple(map(int, input().split())) for _ in range(n-1)]

# Solve the problem
solve(n, a, edges)
