//diajkstra fele korte hbe 
// min cost ber korte hbe protita warm hole check kore 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> p;
struct warmhole {
    int sx,sy,dx,dy,cost;
};
int min_cost(int sx, int sy, int dx, int dy, vector<warmhole>& holes);
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;cin>>n;int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        vector<warmhole> holes(n);
        for(int i=0;i<n;i++)
        {
            cin>>holes[i].sx>>holes[i].sy>>holes[i].dx>>holes[i].dy>>holes[i].cost;
        }
        cout<<min_cost(sx,sy,dx,dy,holes)<<endl;
    }
}

int min_cost(int sx, int sy, int dx, int dy, vector<warmhole>& holes) {
    priority_queue<p, vector<p>, greater<p>> pq;
    map<pair<int, int>, int> dist;
    pq.push({0, {sx, sy}}); // cost, (start x, start y)
    dist[{sx, sy}] = 0;
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int curr_cost = top.first;
        int curr_x = top.second.first;
        int curr_y = top.second.second;
        if (curr_x == dx && curr_y == dy) {
            return curr_cost; // Reached destination
        }
        //move directly to destination
        int direct_cost = curr_cost + abs(curr_x - dx) + abs(curr_y - dy);
        if(dist.find({dx,dy})==dist.end() || dist[{dx, dy}] >  direct_cost) {
            dist[{dx, dy}] = direct_cost;
            pq.push({ direct_cost, {dx, dy}});
        }
        // Explore warmholes
        for ( auto hole:holes)
        {
            int walk_to_hole = abs(curr_x - hole.sx) + abs(curr_y - hole.sy);
            int tot_cost=curr_cost+hole.cost+walk_to_hole;
            if(dist.find({hole.dx,hole.dy})==dist.end() || dist[{hole.dx, hole.dy}] > tot_cost) {
                dist[{hole.dx, hole.dy}] = tot_cost;
                pq.push({tot_cost, {hole.dx, hole.dy}});
            }
            //as bidirectional move it can first go to destination and then to hole
            walk_to_hole= abs(curr_x - hole.dx) + abs(curr_y - hole.dy);
            tot_cost=curr_cost+hole.cost+walk_to_hole;
            if(dist.find({hole.sx, hole.sy})==dist.end() || dist[{hole.sx, hole.sy}] > tot_cost) {
                dist[{hole.sx, hole.sy}] = tot_cost;
                pq.push({tot_cost, {hole.sx, hole.sy}});
            }
        }
    }
    // Placeholder implementation; replace with actual logic.
    return -1; // Replace with actual minimum cost calculation
}
