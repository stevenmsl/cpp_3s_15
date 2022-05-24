#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1209;

/*
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

tuple<vector<int>, vector<vector<int>>>
testFixture1()
{
  auto nums = vector<int>{-1, 0, 1, 2, -1, -4};
  auto output = vector<vector<int>>{{-1, 0, 1},
                                    {-1, -1, 2}};
  return make_tuple(nums, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.threeSum(get<0>(f))) << endl;
}

main()
{
  test1();
  return 0;
}