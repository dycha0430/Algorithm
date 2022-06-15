def main():
    N = int(input())
    attrs = sorted(list(map(int, input().split())))

    answer = 2000000000
    start = 0
    end = N-1
    answer_s = 0
    answer_e = N-1
    while start != end:
        tmp = attrs[start] + attrs[end]
        if abs(tmp) < abs(answer):
            answer = tmp
            answer_s = attrs[start]
            answer_e = attrs[end]
        if tmp < 0:
            start += 1
        elif tmp > 0:
            end -= 1
        else:
             break

    print(str(answer_s) + " " + str(answer_e))


main()
