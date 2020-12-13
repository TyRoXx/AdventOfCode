#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <algorithm>

using Plugs = std::vector<int>;
using PlugMappings = std::unordered_map<int, Plugs>;

// [0, 1, 2, 3, 4, 7]
// [0, 2, 3, 4, 7]
// [0, 3, 4, 7]
// [0, 1, 3, 4, 7]

PlugMappings buildPlugMap(const Plugs &plugs)
{
    PlugMappings mappings;
    for (const int plug : plugs)
    {
    }
}

int solve(const Plugs &input)
{

    std::vector sorted = input;
    sorted.emplace_back(0);
    std::sort(sorted.begin(), sorted.end());
    sorted.emplace_back(sorted[sorted.size() - 1] + 3);

    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        int diff = sorted[i + 1] - sorted[i];
        map[diff] = map[diff] + 1;
    }

    return map.at(1) * map.at(3);
}

int main()
{
    const int a1 = solve({
        28,
        33,
        18,
        42,
        31,
        14,
        46,
        20,
        48,
        47,
        24,
        23,
        49,
        45,
        19,
        38,
        39,
        11,
        1,
        32,
        25,
        35,
        8,
        17,
        7,
        9,
        4,
        2,
        34,
        10,
        3,
    });
    assert(a1 == 220);
    std::cout
        << solve({160, 34, 123, 159,
                  148, 93, 165, 56, 179, 103, 171, 44, 110, 170, 147, 98, 25, 37,
                  137, 71, 5, 6, 121, 28, 19, 134, 18, 7, 66, 90, 88, 181, 89, 41, 156, 46, 8, 61, 124, 9, 161, 72, 13, 172, 111, 59, 105, 51, 109, 27, 152, 117, 52, 68, 95, 164, 116, 75, 78, 180, 81, 47, 104, 12, 133, 175, 16, 149, 135, 99, 112, 38, 67, 53, 153, 2, 136, 113, 17, 145, 106, 31, 45, 169, 146, 168, 26, 36, 118, 62, 65, 142, 130, 1, 140, 84, 94, 141, 122, 22, 48, 102, 60, 178, 127,
                  73, 74, 87, 182, 35})
        << std::endl;
}