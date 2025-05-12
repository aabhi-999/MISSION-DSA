import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        if not nums1 or not nums2 or k <= 0:
            return []
        
        m, n = len(nums1), len(nums2)
        heap = []
        result = []
        
        for i in range(min(k, m)):
            heapq.heappush(heap, (nums1[i] + nums2[0], i, 0))
        
        while heap and len(result) < k:
            total, i, j = heapq.heappop(heap)
            result.append([nums1[i], nums2[j]])
            if j + 1 < n:
                heapq.heappush(heap, (nums1[i] + nums2[j + 1], i, j + 1))
        
        return result    
