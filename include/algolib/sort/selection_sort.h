#ifndef ALGOLIB_SELECTION_SORT_H
#define ALGOLIB_SELECTION_SORT_H

#include <iterator>
#include <functional>

namespace algolib::sort
{
    template <
        std::random_access_iterator RandomIt,
        typename Compare = std::less<>
    >
    constexpr void selection_sort(RandomIt first,
                                  RandomIt last,
                                  Compare comp = Compare{})
    {
        for (auto i = first; i != last; ++i)
        {
            auto min_it = i;

            for (auto j = std::next(i); j != last; ++j)
            {
                if (comp(*j, *min_it))
                {
                    min_it = j;
                }
            }

            if (min_it != i)
            {
                std::iter_swap(i, min_it);
            }
        }
    }

}

#endif //ALGOLIB_SELECTION_SORT_H