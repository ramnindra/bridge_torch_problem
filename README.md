

### Introduction

### Implementaton


### Third-party Libraries

LibYAML - A C library for parsing and emitting YAML.
https://github.com/yaml/libyaml

YAML parser and emitter in C++
https://github.com/jbeder/yaml-cpp



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

