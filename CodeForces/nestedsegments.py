def lin():
  return map(int,input().split())
def solve():
  n=int(input())
  time=[]
  for i in range(n):
    l,r=lin()
    time.append((l,r,i+1))
  time.sort()
  mx=-1
  lx=-1
  index=-1
  for l,r,i in time:
    
    if r<=mx:
      print(i,index)
      return 
    elif l==lx:
      print(index,i)
      return 
    else:
      index=i
      mx=r
      lx=l
  print(-1,-1)
    
solve()
