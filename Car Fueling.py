'''

Problem Introduction:

You are going to travel to another city that is located π miles away from your home city. Your car can travel
at most π miles on a full tank and you start with a full tank. Along your way, there are gas stations at
distances stop1, stop2, . . . , stopπ from your home city. What is the minimum number of refills needed?
Problem Description

Input Format. The first line contains an integer π. The second line contains an integer π. The third line
specifies an integer π. Finally, the last line contains integers stop1, stop2, . . . , stopπ.

Output Format. Assuming that the distance between the cities is π miles, a car can travel at most π miles
on a full tank, and there are gas stations at distances stop1, stop2, . . . , stopπ along the way, output the
minimum number of refills needed. Assume that the car starts with a full tank. If it is not possible to
reach the destination, output β1.

Constraints. 1 β€ π β€ 105. 1 β€ π β€ 400. 1 β€ π β€ 300. 0 < stop1 < stop2 < Β· Β· Β· < stopπ < π.
-------------------
Sample 1.

Input:
950
400
4
200 375 550 750

Output:
2

The distance between the cities is 950, the car can travel at most 400 miles on a full tank. It suffices
to make two refills: at points 375 and 750. This is the minimum number of refills as with a single refill
one would only be able to travel at most 800 miles.
---------------------------
Sample 2.

Input:
10
3
4
1 2 5 9

Output:
-1
One cannot reach the gas station at point 9 as the previous gas station is too far away.
'''

def min_fuel(d, tank, station):
    ut=0
    curF= tank - station[0]
    for i in range(len(station)-1):
        
        diff = station[i+1]-station[i]
        if diff<=tank:
            if diff<curF:
                curF -= diff
            else:
                if diff!=curF:
                    curF = tank - diff
                else:
                    curF = tank
                ut +=1
        else:
            return -1
       
    diff = d - station[-1]
    if diff<= tank:
        if diff<=curF:
            return ut
        else:
            return ut+1
    else:
         return -1


d, tank, ns, station = int(input()), int(input()), int(input()), [*map(int, input().split())]

print(min_fuel(d, tank, station))
