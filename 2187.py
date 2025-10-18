def main():
    n, a, b = list(map(int, input().split()))

    points = []
    for _ in range(n):
        r, c, s = list(map(int, input().split()))
        points.append({"r": r, "c": c, "s": s})

    minValue = 987654321
    for i in range(n):
        for j in range(i + 1, n):
            r1 = points[i].get("r")
            c1 = points[i].get("c")
            s1 = points[i].get("s")
            r2 = points[j].get("r")
            c2 = points[j].get("c")
            s2 = points[j].get("s")

            if abs(r1 - r2) <= a and abs(c1 - c2) <= b and abs(s1 - s2) <= minValue:
                minValue = abs(s1 - s2)
            print(minValue)
            print(r1, c1, s1, r2, c2, s2)

    print(minValue)


if __name__ == "__main__":
    main()

# 평면에 N(1 ≤ N ≤ 1,000)개의 점들이 있다. 각각의 점들은 정수 값으로 어떤 가중치 S(1 ≤ S ≤ 2,000,000)를 가지고 있다. 또 각각의 점들은 (r, c)의 좌표를 갖는데 이는 (행, 열) 순이다. 또한 1 ≤ r ≤ 2,000,000과 1 ≤ c ≤ 2,000,000가 성립한다.
# 이제 우리는 세로로 A(1 ≤ A ≤ 2,000,000), 가로로 B(1 ≤ B ≤ 2,000,000)만큼의 직사각형을 쳐서 이 중 몇 개의 점들을 이 사각형 안에 포함시키려고 한다. 이때, 사각형 안에 포함된 점들 중, “S의 최대-S의 최소”가 최대가 되도록 하려 한다.
