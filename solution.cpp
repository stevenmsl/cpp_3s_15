#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol1209;
using namespace std;

/*takeaways
  - S = {-1, 0, 1, 2, -1, -4}
  - sort S to make eliminating duplicates easier
    S = {-4, -1, -1, 0, 1, 2}
  - just like creating combinations, we start from the
    first element, and for duplicate numbers,
    we only pick one of them so we can avoid creating duplicate triplets
  - to optimize the time complexity, we can loop through the
    array to find the first and second elements of the triplet.
    To find the third element, we do a lookup by the value (0-num[i]-num[j])
    to see if there is any occurrence of that value in a map to save time

    - {-4,-1, t} t = 0 - (-4) - (-1) = 5 -> no answer
    - skip the next -1 as it would create a duplicate triplet if there is an aswer
    - {-4,0,t} (x)
       ...
    - {-1, -1, t} t = 0 - (-1) -(-1) = 2 -> {-1,-1, 2}
      - notice that second -1 is at different level than the first -1,
        just like in the the combination questions it's not considered
        as a duplicate number.
    - also critical is to make sure there is enogh count for each number
      that constitutes the triplet. Consider the extreme case where the triplet
      is {0, 0, 0} so map[0] = 3. This means we need to check if map[0] >= 3 to
       make sure we have enough number of zero's to form a triplet.

*/

vector<vector<int>> Solution::threeSum(vector<int> &nums)
{
  auto count = unordered_map<int, int>();
  /* occurrences of each possible values */
  for (auto n : nums)
    count[n]++;
  sort(begin(nums), end(nums));
  auto result = vector<vector<int>>();
  for (auto i = 0; i < nums.size(); i++)
  {
    /* pick the first occurrence only */
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (auto j = i + 1; j < nums.size(); j++)
    {
      /* skip if it's the same value at the same level*/
      if (j - 1 != i && nums[j] == nums[j - 1])
        continue;
      auto t = 0 - nums[i] - nums[j];
      /* we sorted the array. So anything after nums[j] will be greater
         than or equal to t. No point that we keep looking.
      */
      if (nums[j] > t)
        continue;
      if (!count.count(t))
        continue;
      /* let's check if there is enough count for everyone */
      if (count[t] >= ((nums[i] == t) + (nums[j] == t) + 1))
        result.push_back({nums[i], nums[j], t});
    }
  }

  return result;
}