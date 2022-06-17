import sys
read = sys.stdin.readline
write = sys.stdout.write

class DisjointSet:
    def __init__(self, n):
        self.data = [-1 for _ in range(n)]

    def find(self, index):
        if self.data[index] < 0:
            return index

        self.data[index] = self.find(self.data[index])

        return self.data[index]

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return;

        if self.data[x] < self.data[y]:
            self.data[x] += self.data[y]
            self.data[y] = x
        else:
            self.data[y] += self.data[x]
            self.data[x] = y

TC = int(input())

for test_case in range(TC):
    print("Scenario " + str(test_case+1) + ":")
    N = int(read())
    K = int(read())
    relation = DisjointSet(N)
    
    for i in range(K):
        a, b = map(int, read().split())
        relation.union(a, b)

    M = int(input())
    for i in range(M):
        u, v = map(int, read().split())
        if (relation.find(u) == relation.find(v)):
            print(1)
        else:
            print(0)
    if test_case != TC-1:
        print()        
