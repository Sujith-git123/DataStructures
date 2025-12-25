def lin():
  return map(int,input().split())
def solve():
  n,m=tuple(lin())
  nums=list(lin())
  nums.append(m)
  on,off=[],[]
  pre=0
  for i in range(n+1):
    if i%2==0:
      on.append(nums[i]-pre)
      off.append(0)
      pre=nums[i]
    else:
      off.append(nums[i]-pre)
      on.append(0)
      pre=nums[i]
  for i in range(1,len(on)):
      on[i]+=on[i-1]
  for i in range(1,len(off)):
    off[i]+=off[i-1]
  ans=on[-1]
  pre=0
  for i in range(n+1):
    if i%2==0 and nums[i]-1>pre:
      left=0
      if i-1>=0:
        left=on[i-1]
      ans=max(ans,left+nums[i]-1-pre+off[-1]-off[i])
    elif pre+1<nums[i]:
      right=off[-1]
      if i+1<n+1:
        right=off[i+1]
      ans=max(ans,on[i]+nums[i]-(pre+1)+off[-1]-right)
    pre=nums[i]
  print(ans)
solve()
