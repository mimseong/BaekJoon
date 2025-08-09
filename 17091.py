num2words = {
    1: "one",
    2: "two",
    3: "three",
    4: "four",
    5: "five",
    6: "six",
    7: "seven",
    8: "eight",
    9: "nine",
    10: "ten",
    11: "eleven",
    12: "twelve",
    13: "thirteen",
    14: "fourteen",
    15: "fifteen",
    16: "sixteen",
    17: "seventeen",
    18: "eighteen",
    19: "nineteen",
    20: "twenty",
    30: "thirty",
    40: "forty",
    50: "fifty",
    60: "sixty",
    70: "seventy",
    80: "eighty",
    90: "ninety",
    0: "zero",
}


def n2w(n):
    try:
        return num2words[n]
    except KeyError:
        try:
            return num2words[n // 10 * 10] + " " + num2words[n % 10]
        except KeyError:
            print("Number out of range")


h = int(input())
m = int(input())

if m == 0:
    print(f"{n2w(h)} o' clock")
elif m == 15:
    print(f"quarter past {n2w(h)}")
elif m == 30:
    print(f"half past {n2w(h)}")
elif m == 45:
    next_hour = h + 1 if h < 12 else 1
    print(f"quarter to {n2w(next_hour)}")
elif m <= 30:
    if m == 1:
        print(f"one minute past {n2w(h)}")
    else:
        print(f"{n2w(m)} minutes past {n2w(h)}")
else:  # m > 30
    remaining_minutes = 60 - m
    next_hour = h + 1 if h < 12 else 1
    if remaining_minutes == 1:
        print(f"one minute to {n2w(next_hour)}")
    else:
        print(f"{n2w(remaining_minutes)} minutes to {n2w(next_hour)}")
