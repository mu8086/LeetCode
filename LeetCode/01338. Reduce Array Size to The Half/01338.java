class Solution {
    public int minSetSize(int[] arr) {
        int count, halfSize;
        Map<Integer, Integer> map = new HashMap<>();
        
        // [map] key: number, value: frequency
        for (int n : arr) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        
        // PriorityQueue implement as minheap by default, use reverseOrder for maxheap
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        // put frequency to pq
        for (int n : map.keySet()) {
            pq.offer(map.get(n));
        }
        
        for (count = 0, halfSize = arr.length / 2; halfSize > 0; ++count) {
            halfSize -= pq.poll();
        }
        
        return count;
    }
}
