//
//
//  Created by rregar on 6/24/20.
//  Copyright © 2020 Ram. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "yaml-cpp/yaml.h"

#define BITCOUNT(v) (int)(v * ((int)~(int)0/255)) >> (sizeof(int) - 1) * CHAR_BIT

/* Global dp[2^20][2] array, in dp[i][j]-- 'i' denotes mask in which 'set bits' denotes
   total people standing at left side of bridge and 'j' denotes the turn that represent on
   which side we have to send people either from left to right(0) or from right to left(1) */

int dp[1 << 20][2];

/* Utility function to find total time required to send people to other side of bridge */

int findMinCrossingTime(int leftmask, bool turn, std::vector<int>& arr)
{
  int n = arr.size();

  // If all people has been transfered
  if (!leftmask)
    return 0;

  int& res = dp[leftmask][turn];

  // If we already have solved this subproblem,
  // return the answer.
  if (~res)
    return res;

  // Calculate mask of right side of people
  int rightmask = ((1 << n) - 1) ^ leftmask;

  /* if turn == 1 means currently people are at
     right side, thus we need to transfer
     people to the left side */
  if (turn == 1) {
    int minRow = INT_MAX, person;
    for (int i = 0; i < n; ++i)
    {
      // Select one people whose time is less
      // among all others present at right side
      if (rightmask & (1 << i)) {
        if (minRow > arr[i]) {
          person = i;
          minRow = arr[i];
        }
      }
    }

    // Add that person to answer and recurse for next turn
    // after initializing that person at left side
    res = arr[person] + findMinCrossingTime(leftmask | (1 << person),
        turn ^ 1, arr);
  } else {

    // BITCOUNT will count total set bits in 'leftmask'
    if (BITCOUNT(leftmask) == 1) {
      for (int i = 0; i < n; ++i) {

        // Since one person is present at left
        // side, thus return that person only
        if (leftmask & (1 << i))
        {
          res = arr[i];
          break;
        }
      }
    } else {

      // try for every pair of people by
      // sending them to right side
      // Initialize the result with maximum value
      res = INT_MAX;
      for (int i = 0; i < n; ++i)
      {
        // If ith person is not present then
        // skip the rest loop
        if (!(leftmask & (1 << i)))
          continue;

        for (int j = i + 1; j < n; ++j)
        {
          if (leftmask & (1 << j))
          {
            // Find maximum integer(slowest
            // person's time)
            int val = std::max(arr[i], arr[j]);

            // Recurse for other people after un-setting
            // the ith and jth bit of left-mask
            val += findMinCrossingTime(leftmask ^ (1 << i) ^ (1 << j),
                turn ^ 1, arr);
            // Find minimum answer among
            // all chosen values
            res = std::min(res, val);
          }
        }
      }
    }
  }
  return res;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " <config filename>" << std::endl;
    exit(0);
  }

  // Load all test descriptions (YAML documents) as a vector
  std::vector<YAML::Node> tests = YAML::LoadAllFromFile(argv[1]);

  for(auto &t : tests)
  {
    YAML::Node data = t["test"];

    // test parameters
    int test_id = data["test_id"].as<int>();
    int bridgecount = data["bridgecount"].as<unsigned int>();

    std::cout << "Test Id : " << test_id << " bridge count : " << bridgecount << std::endl;
    for (int c = 0; c < bridgecount; c++)
    {
      std::string query("walk_time" + std::to_string(c));
      std::vector<int> walk_time = data[query.c_str()].as<std::vector<int>>();
      int received = 0;
      for (int j = 0; j < walk_time.size(); j++)
      {
        std::cout << walk_time[j] << " " ;
        // Find the mask of 'n' people
        int mask = (1 << walk_time.size()) - 1;

        // Initialize all entries in dp as -1
        memset(dp, -1, sizeof(dp));
        received += findMinCrossingTime(mask, 0, walk_time);
      }
      std::cout << "\nTotal Taken :" << received << std::endl;
    }
  }
  exit(0);
}
