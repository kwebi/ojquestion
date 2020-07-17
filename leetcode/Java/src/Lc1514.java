import java.util.Map.Entry;

import java.util.*;

public class Lc1514 {
    ArrayList<ArrayList<Edge>> list = new ArrayList<>();
    double[] dis = new double[10005];
    boolean[] vis = new boolean[10005];

    public static void main(String[] args) {
        Lc1514 lc1514 = new Lc1514();
        int[][] a = { { 1, 4 }, { 2, 4 }, { 0, 4 }, { 0, 3 }, { 0, 2 }, { 2, 3 } };
        double[] d = { 0.37, 0.17, 0.93, 0.23, 0.39, 0.04 };
        double res = lc1514.maxProbability(5, a, d, 3, 4);
        System.out.println(res);
    }

    private void dijk(int start) {
        Arrays.fill(dis, 0);
        Arrays.fill(vis, false);
        PriorityQueue<Edge> que = new PriorityQueue<>((a, b) -> {
            return Double.compare(b.val, a.val);
        });
        que.add(new Edge(start, 1));
        dis[start] = 1;

        while (!que.isEmpty()) {
            Edge t = que.poll();
            int now = t.to;
            double val = t.val;
            if (vis[now])
                continue;
            vis[now] = true;
            ArrayList<Edge> l = list.get(t.to);
            for (int i = 0; i < l.size(); i++) {
                Edge e = l.get(i);
                if (e.to == now)
                    continue;
                if (dis[e.to] < val * e.val) {
                    dis[e.to] = val * e.val;
                    que.add(new Edge(e.to, val * e.val));
                }
            }
        }
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        for (int i = 0; i < 10005; i++)
            list.add(new ArrayList<>());
        for (int i = 0; i < edges.length; i++) {
            list.get(edges[i][0]).add(new Edge(edges[i][1], succProb[i]));
            list.get(edges[i][1]).add(new Edge(edges[i][0], succProb[i]));
        }
        dijk(start);
        return dis[end];
    }
}

class Edge {
    public int to;
    public double val;

    public Edge(int to, double val) {
        this.to = to;
        this.val = val;
    }
}