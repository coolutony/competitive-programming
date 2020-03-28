import sys


T, N, M = [int(n) for n in input().split(" ")]
for count in range(T):
    possible = [i for i in range(1,M+1)]
    for day in [18,17,16,15,14,13,11]:
        print("{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}".format(day,day,day,day,day,day,day,day,day,day,day,day,day,day,day,day,day,day))
        sys.stdout.flush()
        result = [int(n) for n in input().split(" ")]
        remainder = sum(result)%day
        possible = [n for n in possible if n%day==remainder]
        if len(possible) == 1:
            print("{}".format(possible[0]))
            sys.stdout.flush()
            correct = int(input())
            break