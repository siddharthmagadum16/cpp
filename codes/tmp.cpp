
class SegTree {

  vector<int> tree;
  int unit, n;

  int merge(int a, int b) { return a + b; }

  public:
  SegTree(int n, int def) {
    tree = vector<int>(2*n, def);
    unit = def;
    this->n = n;
  }

  void update(int val, int index) {
    index = (index + n) / 2;
    for (tree[index] = val; index > 0; index /= 2) {
      tree[index] = merge(tree[index*2], tree[index*2+1]);
    }
  }

  int query(int begin, int end) {
    int aggLeft = unit, aggRight = unit;
    for (begin += n, end += n; begin < end; begin /= 2, end /= 2) {
      if (begin&1) aggLeft = merge(aggLeft, tree[begin++]);
      if (end&1) aggRight = merge(aggRight, tree[--end]);
    }
    return merge(aggLeft, aggRight);
  }
};


int solve(vector<vector<int>>&flights, int source, int destination) {
  vector<vector<pair<int,int>>>&adjList;

  sort(flights.begin(), flights.end(), [](const vector<int>&flight1, const vector<int>&flight2) {
    return flight1[2] < flgiht2[2];
  });

  for (vector<int>&flight: flights) {
    int src = flights[0];
    int dst = flights[1];
    int depTime = flights[2];
    int arrTime = flights[3];

    vector<int>flightDetails({depTime, arrTime, dst});
    adjList[src].push_back(flightDetails);
  }


  priority_queue<pair<int, int>>pBfs;
  vector<bool>visited(n,0);

  pBfs.push({source, 0});
  visited[source] = true;

  while(pBfs.size()) {
    int currTime = pBfs.top().first;
    int currAirport = pBfs.top().second;

    vector<int> minTimeAirport({currTime, -1,-1});
    int index = lower_bound(adjList[currAirport].begin(), adjlist[currAirPort].end(), minTimeAirport) - adjList[currAirport].begin();

    for (int i = index; i < adjList[currAirport].size(); ++ i) {
      vector<int> flightInfo = adjList[currAirport][i];
      int dstAirport = flightInfo[2];
      int arrivalTime = flightinfo[1];
      if (not visited[dstAirport]) {
        visited[dstAirport] = true;
        pBfs.push({arrivalTime, dstAirport});
      }
    }
  }

  visited(n,0);
  

  return visited[destination];
}

