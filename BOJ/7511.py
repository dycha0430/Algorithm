TC = int(input())
relation = dict()
checked = []
target = 0

def DFS(checking_friend):
    if checking_friend == target:
        return 1
    if (checking_friend not in relation) or (checked[checking_friend] != 0):
        return 0
    checked[checking_friend] = 1
    for p in relation[checking_friend]:
        if checked[p] == 0:
            if DFS(p) == 1:
                return 1

    return 0

for test_case in range(TC):
    print("Scenario " + str(test_case+1) + ":")
    N = int(input())
    K = int(input())
    checked = [0 for _ in range(N)]
    
    for i in range(K):
        a, b = map(int, input().split())
        if a in relation:
            relation[a].append(b)
        else:
            relation[a] = [b]

        if b in relation:
            relation[b].append(a)
        else:
            relation[b] = [a]

    M = int(input())
    for i in range(M):
        u, target = map(int, input().split())
        print(DFS(u))
    if test_case != TC-1:
        print()

