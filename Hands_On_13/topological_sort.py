# This code performs a topological sort on a directed acyclic graph (DAG) using depth-first search (DFS), visiting nodes recursively and storing them based on their finishing time.
# It returns a linear ordering of nodes where each node appears before its dependents, following the defined dependencies.

# Based on textbook figure 22.7

# cd Hands_On_13
# python3 topological_sort.py

def dfs_topological_sort(graph, node, visited, stack):
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs_topological_sort(graph, neighbor, visited, stack)
    stack.append(node)

def topological_sort(graph):
    visited = set()
    stack = []
    for node in graph:
        if node not in visited:
            dfs_topological_sort(graph, node, visited, stack)
    return stack[::-1]

graph = {
    "undershorts": ["pants", "shoes"],
    "socks": ["shoes"],
    "pants": ["shoes", "belt"],
    "shirt": ["tie", "belt"],
    "tie": ["jacket"],
    "belt": ["jacket"],
    "shoes": [],
    "watch": [],
    "jacket": []
}

result = topological_sort(graph)
print("Topological Order:", " -> ".join(result))
