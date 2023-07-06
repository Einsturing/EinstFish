//难度-简单
//模拟取模即可
class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int n = distance.size();
        int d1 = 0;
        int d2 = 0;
        for (int r = start; r != destination; r = (r + 1) % n)
            d1 += distance[r];
        for (int l = (start + n - 1) % n; l != (destination - 1 + n) % n; l = (l + n - 1) % n)
            d2 += distance[l];
        return min(d1, d2);
    }
};