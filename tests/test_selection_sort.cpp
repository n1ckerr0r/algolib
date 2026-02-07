#include <gtest/gtest.h>
#include <vector>
#include <algolib/sort/selection_sort.h>

TEST(SelectionSort, SortsIntegersAscending)
{
    std::vector<int> v{4, 2, 5, 1, 3};

    algolib::sort::selection_sort(v.begin(), v.end());

    EXPECT_EQ(v, (std::vector<int>{1,2,3,4,5}));
}

TEST(SelectionSort, SortsDescendingWithComparator)
{
    std::vector<int> v{4, 2, 5, 1, 3};

    algolib::sort::selection_sort(v.begin(), v.end(), std::greater<>());

    EXPECT_EQ(v, (std::vector<int>{5,4,3,2,1}));
}

TEST(SelectionSort, WorksWithAlreadySorted)
{
    std::vector<int> v{1,2,3,4,5};

    algolib::sort::selection_sort(v.begin(), v.end());

    EXPECT_EQ(v, (std::vector<int>{1,2,3,4,5}));
}