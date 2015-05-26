#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>


typedef long long int ll;

typedef struct Edge {
	ll s, t, w;
	ll index;
} Edge;

std::vector< std::vector<Edge> > edges;


ll dijkstra(ll source)
{
	ll total = 0;
	std::set<ll> paths;
	std::set< std::pair<ll, ll> > distance;

	Edge edge;
	edge.s = 0;
	edge.t = 0;
	edge.w = 0;
	edge.index = 0;
	std::vector< std::pair<ll, Edge> > d(edges.size(), std::make_pair(LLONG_MAX, edge));

	distance.insert(std::make_pair(0, source));
	d[source] = std::make_pair(0, edge);


	while (!distance.empty()) {
		ll min_distance = distance.begin()->first;
		ll min_node = distance.begin()->second;
		Edge edge = d[min_node].second;

		distance.erase(distance.begin());
		if (edge.index != 0) {
			//std::cout << edge.s << " " << edge.t << " " << edge.w << " " << edge.index << std::endl;
			total += edge.w;
			paths.insert(edge.index);
		}


		for (ll i = 0; i < edges[min_node].size(); i++) {
			Edge edge = edges[min_node][i];
			if (min_distance + edge.w <= d[ edge.t ].first) {
				distance.erase(std::make_pair(d[edge.t].first, edge.t));
				d[edge.t].first = min_distance + edge.w;
				d[edge.t].second = edge;
				distance.insert(std::make_pair(d[edge.t].first, edge.t));
			}
		}
	}

	std::cout << total << std::endl;
	for (std::set<ll>::iterator it = paths.begin(); it != paths.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll n, m;
	std::cin >> n >> m;
	edges.resize(n);
	for (ll i = 1; i <= m; i++) {
		ll u, v, w;
		std::cin >> u >> v >> w;
		u--;
		v--;
		Edge edge;
		edge.s = u;
		edge.t = v;
		edge.w = w;
		edge.index = i;
		edges[u].push_back(edge);
		edge.s = v;
		edge.t = u;
		edges[v].push_back(edge);
	}

	ll s;
	std::cin >> s;
	dijkstra(s - 1);
	
	return 0;
}