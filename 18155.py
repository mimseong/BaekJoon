n, m = list(input().split())

li = []
for i in range(int(n)):
    s = input()
    li.append(s)
    
for i in range(int(m)):
    s = input()
    
    while (s.find('0') != -1):
        idx = s.find('0')
        s = s[0:idx] + 'O' + s[idx + 1:]
    while (s.find('1') != -1):
        idx = s.find('1')
        s = s[0:idx] + 'L' + s[idx + 1:]
    while (s.find('2') != -1):
        idx = s.find('2')
        s = s[0:idx] + 'Z' + s[idx + 1:]
    while (s.find('3') != -1):
        idx = s.find('3')
        s = s[0:idx] + 'E' + s[idx + 1:]
    while (s.find('5') != -1):
        idx = s.find('5')
        s = s[0:idx] + 'S' + s[idx + 1:]
    while (s.find('6') != -1):
        idx = s.find('6')
        s = s[0:idx] + 'B' + s[idx + 1:]
    while (s.find('7') != -1):
        idx = s.find('7')
        s = s[0:idx] + 'T' + s[idx + 1:]
    while (s.find('8') != -1):
        idx = s.find('8')
        s = s[0:idx] + 'B' + s[idx + 1:]
    
    check = True
    for bad in li:
        if bad in s:
            check = False
    
    if check:
        print('VALID')
    else:
        print('INVALID')