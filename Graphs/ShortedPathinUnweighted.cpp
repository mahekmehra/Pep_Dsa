vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	vector<vector<int>> adj(n+1);
	for(auto &i : edges){
		int u = i.first;
		int v = i.second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> visited(n+1,false);
	vector<int> parent(n+1,-1);

	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int front = q.front();
		q.pop();
		visited[front] = true;
		for(int &v : adj[front]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
				parent[v] = front;
			}
		}
	}

	vector<int> ans;
	ans.push_back(t);
	int pr = parent[t];
	while(pr!=-1){
		ans.push_back(pr);
		pr = parent[pr];
	} 

	reverse(ans.begin(),ans.end());
	return ans;

}

/*The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.

A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.

For example
In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go from S=1 to T=8  via (1, 2, 5, 8)  or (1, 4, 6, 7, 8) but these paths are not shortest.*/
