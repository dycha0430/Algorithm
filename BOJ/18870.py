def main():
    N = int(input())
    X = []
    line = input().split()
    for i in range(N):
        X.append((int(line[i]), i))

    X.sort(key = lambda x : x[0])
    
    result = [0 for i in range(N)]
    order = 0
    for i in range(N):
        if (i != 0 and X[i][0] != X[i-1][0]):
            order += 1
        result[X[i][1]] = order

    for i in range(N):
        print(str(result[i]) + " ", end = "")

main()
