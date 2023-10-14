//includes can be replaced with <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>

//graph representation
class Graph {
private:
	//size
	int N;
	//nodes list
	std::list<std::pair<int, int>>* adj;
public:
	//constructor
	Graph(int n) : N(n) {
		adj = new std::list<std::pair<int, int>>[N];
	}
	//add new bidirectional edge
	inline void push_edge(int src, int dist, int w) {
		adj[src].push_back(std::make_pair(dist, w));
		adj[dist].push_back(std::make_pair(src, w));
	}
	//main function to find and print path
	void get_shortest_path(int src, int t) {
		std::vector<std::vector<std::pair<int, int>>> path(N);
		std::vector<int> dist(N, INT_MAX);
		shortest_path(src, dist, path);
		std::cout << dist[t] << '\n';
		for (const auto i : path[t]) {
			std::cout << i.first << ' ' << i.second << '\n';
		}
	}
	//modificated dijkstra saving path
	void shortest_path(int src, std::vector<int>& dist, std::vector<std::vector<std::pair<int, int>>>& path) {
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
		q.push(std::make_pair(0, src));
		dist[src] = 0;
		while (!q.empty()) {
			int current = q.top().second;
			q.pop();
			std::list<std::pair<int, int>>::iterator it;
			for (it = adj[current].begin(); it != adj[current].end(); ++it) {
				int distanation = (*it).first;
				int cost = (*it).second;
				if (dist[distanation] > dist[current] + cost) {
					dist[distanation] = dist[current] + cost;
					path[distanation].push_back(std::make_pair(distanation, cost));
					q.push(std::make_pair(dist[distanation], distanation));
				}
			}
		}
	}
};