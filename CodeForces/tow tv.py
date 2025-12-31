def lin():
  return map(int,input().split())
def solve():
  n=int(input())
  c=0
  time=[]
  for _ in range(n):
    l,r=lin()
    time.append((l,1))
    time.append((r+1,-1))
  time.sort()
  for t,k in time:
    c+=k
    if c>2:
      print("NO")
      return
  print("YES")
    
solve()
