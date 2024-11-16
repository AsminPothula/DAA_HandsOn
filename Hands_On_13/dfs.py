# This DFS code recursively traverses a graph from a starting node to search for a specified target node, stopping early if the target is found. 
# It keeps track of visited nodes to prevent revisits and cycles.

# Based on textbook figure 22.7

# cd Hands_On_13
# python3 dfs.py

def dfs_search(graph, node, target, visited):
    if node == target:
        print(f"Found target node: {node}")
        return True
    
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            if dfs_search(graph, neighbor, target, visited):
                return True
    return False

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

visited = set()
target_node = "jacket"
print("Target node: Jacket")
print("Starting node: Undershorts")
found = dfs_search(graph, "undershorts", target_node, visited)

if not found:
    print("Target node not found in the graph.")
