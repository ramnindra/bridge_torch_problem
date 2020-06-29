

### Introduction

The bridge and torch problem is a logic puzzle that deals with four people, a bridge and a torch. It is one of the category of river crossing puzzles, where a number of people must move across a river, with some constraints like  bridge being narrow or people with different speed etc.

*Write a C++ program that simulates a team hiking through a forest at night. The team encounters a series of narrow bridges along the way. At each bridge they may meet additional hikers who need their help to cross the bridge.
The narrow bridge can only hold two people at a time. They have one torch and because it's night, the torch has to be used when crossing the bridge. Each hiker can cross the bridge at different speeds. When two hikers cross the bridge together, they must move at the slower person's pace.
Determine the fastest time that the hikers can cross the each bridge and the total time for all crossings. The input to the program will be a yaml file that describes the speeds of each person, the bridges encountered, their length, and the additional hikers encountered along the way. Your solution should assume any number of people and bridges can be provided as inputs.
Demonstrate the operation of your program using the following inputs: the hikers cross 3 bridges, at the first bridge (100 ft long) 4 hikers cross (hiker A can cross at 100 ft/minute, B at 50 ft/minute, C at 20 ft/minute, and D at 10 ft/minute), at the second bridge (250 ft long) an additional hiker crosses with the team (E at 2.5 ft/minute), and finally at the last bridge (150 ft long) two hikers are encountered (F at 25 ft/minute and G at 15 ft/minute).*

### Example
Example as mentioned in Wikipedia (https://en.wikipedia.org/wiki/Bridge_and_torch_problem), involves four people, A, B, C, and D with times to cross the bridge 1, 2, 5, and 8 minutes correspondingly. Other formulations use crossing times `{1, 2, 5, 10}`, `{1, 2, 4, 10}`, or `{1, 4, 5, 10}`. The problem can be easily extended to more people, which have to cross the bridge under the same conditions.

### Research on this problem
http://page.mi.fu-berlin.de/rote/Papers/pdf/Crossing+the+bridge+at+night.pdf
http://www.puzzlesandriddles.com/Brainteaser17.html
https://en.wikipedia.org/wiki/Bridge_and_torch_problem
https://github.com/kkouptsov/BridgeCrossing
https://www.geeksforgeeks.org/puzzle-18-torch-and-bridge/


### Strategies Thought
* __Fastest First__ : 
        To save time the  fastest person pick one other person at a time.
* __Slowest Two First__
        Two slowest persons, who have not yet crossed, travel together. This offsets time wasted on traveling each person separately. However, additional crossings are needed to bring the torch back. 
* __Mix of above two__
    there are cases when an optimal solution switches between two strategies above.

### Dynamic  Programming Approach 
The approach is to use Dynamic programming. Before getting dive into dynamic programminc let’s see the following observation that will be required in solving the problem. When any two people cross the bridge, then the fastest person crossing time will not be contributed in answer as both of them move with slowest person speed. When some of the people will cross the river and reached the right side then only the fastest people(smallest integer) will come back to the left side.
Person can only be present either left side or right side of the bridge. Thus, if we maintain the left mask, then right mask can easily be calculated by setting the bits ‘1’ which is not present in the left mask. For instance, Right_mask = ((2n) – 1) XOR (left_mask).
Any person can easily be represented by bitmask(usually called as ‘mask’). When ith bit of ‘mask’ is set, that means that person is present at left side of the bridge otherwise it would be present at right side of bridge. For instance, let the mask of 6 people is 100101, which reprsents the person 1, 4, 6 are present at left side of bridge and the person 2, 3 and 5 are present at the right side of the bridge.


### Packages Needed
We need "YAML parser and emitter in C++": https://github.com/jbeder/yaml-cpp
### Quick start
```
$ cd src
$ make
$ ./a.out ../tests.yaml
```
### Dynamic Programming Implementaton
A global dp[2^20][2] array, in dp[i][j]-- 'i' denotes mask in which 'set bits' denotes total people standing at left side of bridge and 'j' denotes the turn that represent on which side we have to send people either from left to right(0) or from right to left(1).
I implemented using single file torchbridge.cpp

### Test config
test 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Test case Id
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Bridge Count
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; walk time for each bridge walk_time0 walk_time1 etc.

test:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; test_id: 1   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; bridgecount : 3
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; walk_time0: [21, 22, 23, 24, 25, 26, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; walk_time1: [1, 20, 21, 22, 24, 25, 30, 31, 32, 33, 34, 35, 36, 37, 38]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; walk_time2: [111, 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38]
---
test:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;test_id: 2
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; bridgecount : 2
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;walk_time0: [1, 20, 21, 22, 23, 24, 25, 30, 31, 32, 33, 34, 35, 36, 37, 38]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; walk_time1: [1, 20, 21, 22, 23, 24, 25, 26, 27, 28, 32, 33, 34, 35, 36, 37, 38]
```
$ cd src

ram@RAM-M-R0HQ: src $ ./a.out ../test.yaml 
Test Id : 1 bridge count : 3
21 22 23 24 25 26 28 29 30 31 32 33 34 35 36 37 38 
Total Taken :12648
1 20 21 22 24 25 30 31 32 33 34 35 36 37 38 
Total Taken :6465
111 20 21 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 
Total Taken :16872
Test Id : 2 bridge count : 2
1 20 21 22 23 24 25 30 31 32 33 34 35 36 37 38 
Total Taken :7280
1 20 21 22 23 24 25 26 27 28 32 33 34 35 36 37 38 
Total Taken :8092
ram@RAM-M-R0HQ: src $ 
