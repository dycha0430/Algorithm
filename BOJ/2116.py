N = int(input())
dices = []
for i in range(N):
    dices.append(list(map(int, input().split())))

answer = 0
for i in range(6):
    under_num = dices[0][i]
    ret = 0
    for dice_num in range(N):
        under_num_idx = dices[dice_num].index(under_num)

        rest_dices = []
        up_num = 0
        if under_num_idx == 0:
            rest_dices = [1, 2, 3, 4]
            up_num = dices[dice_num][5]
        elif under_num_idx == 1:
            rest_dices = [0, 2, 4, 5]
            up_num = dices[dice_num][3]
        elif under_num_idx == 2:
            rest_dices = [0, 1, 3, 5]
            up_num = dices[dice_num][4]
        elif under_num_idx == 3:
            rest_dices = [0, 2, 4, 5]
            up_num = dices[dice_num][1]
        elif under_num_idx == 4:
            rest_dices = [0, 1, 3, 5]
            up_num = dices[dice_num][2]
        elif under_num_idx == 5:
            rest_dices = [1, 2, 3, 4]
            up_num = dices[dice_num][0]

        side_max = 0
        for i in range(4):
            side_max = max(side_max, dices[dice_num][rest_dices[i]])
        under_num = up_num
        ret += side_max
    answer = max(answer, ret)

print(answer)
