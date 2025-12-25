from collections import deque

def lin():
    return map(int, input().split())

def solve():
    n = int(input())
    nums = list(lin())

    m = {}
    dq = deque()

    for i in range(n):
        nums[i] += i + 1
        if i > 0:
            m.setdefault(nums[i], []).append(nums[i] + i)

    seen = set()

    for i in range(n):
        if nums[i] == n + 1:
            dq.append(nums[i])
            seen.add(nums[i])

    ans = n + 1

    while dq:
        node = dq.popleft()
        for adj in m.get(node, []):
            if adj not in seen:
                ans = max(ans, adj)
                seen.add(adj)
                dq.append(adj)

    print(ans - 1)


t = int(input())
for _ in range(t):
    solve()
