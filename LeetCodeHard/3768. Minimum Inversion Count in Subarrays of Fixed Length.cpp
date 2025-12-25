class Solution:
    def minInversionCount(self, nums: List[int], k: int) -> int:
        if k==1:
            return 0
        win=SortedList()
        j=0
        s,ans=0,10**18
        for i in range(len(nums)):
            add=win.bisect_right(nums[i])
            s+=len(win)-add
            win.add(nums[i])
            if i-j+1==k:
                ans=min(ans,s)
                to=win.bisect_left(nums[j])
                s-=to
                win.remove(nums[j])
                j+=1
        return ans
