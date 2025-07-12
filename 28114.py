class Student:
    def __init__(self, p, y, n):
        self.p = int(p)
        self.y = int(y)
        self.n = n


def compare_by_year(s):
    return s.y % 100

def compare_by_problem_count(s):
    return s.p

students = []

for i in range(3):
    p, y, n = input().split()
    students.append(Student(p, y, n))

students.sort(key=compare_by_year)

ans1 = ""
for s in students:
    ans1 += str(s.y % 100)
print(ans1)

students.sort(key=compare_by_problem_count, reverse=True)
ans2 = ""
for s in students:
    ans2 += s.n[0]
print(ans2)
