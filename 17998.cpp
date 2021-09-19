alpha = input()
query = input()

s1 = set()

for i in range(len(query)):
    s1.add(query[0:i] + query[i + 1:])

for i in range(len(alpha)):
    for j in range(len(query)):
        s1.add(query[0:j] + alpha[i] + query[j + 1:])

for i in range(len(alpha)):
    for j in range(len(query)):
        s1.add(query[0:j] + alpha[i] + query[j:])
    s1.add(query + alpha[i])

li = []
for string in s1:
    if string == query:
        continue
    li.append(string)

li.sort()
for string in li:
    print(string)