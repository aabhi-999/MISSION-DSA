class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d=[(v,n) for n,v in Counter(nums).items()]
        d.sort(reverse=True)

        return [i[1] for i in d[:k]]
