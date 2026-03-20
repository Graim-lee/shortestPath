# Graph Theory Project 2025-2026

The Floyd–Warshall algorithm makes it possible to compute minimum‑value paths from any vertex
to any other vertex in a directed weighted graph. This algorithm is based on Warshall’s algorithm,
which is dedicated to computing the transitive closure of a graph. The computation of this transitive
closure is adapted in order to retain, among all paths connecting two vertices, those with the smallest
value. 

<p align="center">
  <img src="img.png" alt="Floyd Warshall diagram">
</p>
<p align="center"><em>Figure 1.1, Substructure of the Floyd Warshall Algorithm</em></p>


Why does Floyd Warshall work?
The algorithm relies on the principle of optimal substructure, meaning:

If the shortest path from i to j passes through some vertex k, then the path from i to k and the path from k to j must also be shortest paths.
The iterative approach ensures that by the time vertex k is considered, all shortest paths using only vertices 0 to k-1 have already been computed.
By the end of the algorithm, all shortest paths are computed optimally because each possible intermediate vertex has been considered[^1].




### References: 

[^1]: Geeks4Geeks https://www.geeksforgeeks.org/dsa/floyd-warshall-algorithm-dp-16/
