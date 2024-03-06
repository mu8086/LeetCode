int minCostClimbingStairs(int *cost, int costSize) {
    for (int i = 2; i < costSize; ++i) {
        cost[i] += (cost[i-2] < cost[i-1]) ? cost[i-2] : cost[i-1];
    }
    
    return (cost[costSize-2] < cost[costSize-1]) ? cost[costSize-2] : cost[costSize-1];
}
