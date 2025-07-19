board = []
for i in range(5):
    board.append(list(map(int, input().split())))

r, c = list(map(int, input().split()))

x = [0, 0, 1, -1]
y = [1, -1, 0, 0]
ans = False

def dfs(now_x, now_y, move, apple):
    global ans
    global board

    if board[now_x][now_y] == 1:
        apple += 1

    if apple >= 2:
        ans = True
        return

    if 3 <= move:
        return

    for i in range(4):
        nxt_x = now_x + x[i]
        nxt_y = now_y + y[i]

        if nxt_x < 0 or 5 <= nxt_x or nxt_y < 0 or 5 <= nxt_y:
            continue
        if board[nxt_x][nxt_y] == -1:
            continue

        temp = board[now_x][now_y]
        board[now_x][now_y] = -1
        dfs(nxt_x, nxt_y, move + 1, apple)
        board[now_x][now_y] = temp

def main():

    dfs(r, c, 0, 0)

    if ans:
        print("1")
    else:
        print("0")

if __name__ == "__main__":
  main()
