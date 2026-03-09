# Problem A: Reachability (Find the Target)

## Problem Statement
You are given an undirected graph with $N$ nodes (numbered $1$ to $N$) and $M$ edges. You are currently standing at node $S$. Your goal is to determine if it is possible to reach a target node $T$ by traversing the edges of the graph.

You must implement either a Breadth-First Search (BFS) or a Depth-First Search (DFS) to explore the graph and find the target.

## Input Format
* The first line contains two integers, $N$ and $M$ ($1 \le N \le 10^5$, $0 \le M \le 10^5$), representing the number of nodes and edges.
* The next $M$ lines each contain two integers, $u$ and $v$ ($1 \le u, v \le N$), representing an undirected edge between node $u$ and node $v$.
* The final line contains two integers, $S$ and $T$ ($1 \le S, T \le N$), representing your starting node and the target node.

## Output Format
* Print `YES` if there is a valid path from $S$ to $T$.
* Print `NO` if it is impossible to reach $T$ from $S$.

## Example 1
**Input:**
```text
4 4
1 2
1 3
2 4
3 4
1 4
