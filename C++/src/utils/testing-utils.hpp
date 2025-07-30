#include <gtest/gtest.h>
#include <vector>

namespace testingUtils
{
    template <typename T>
    void EXPECT_NULL(T obj);

    template <typename T>
    void EXPECT_NOT_NULL(T obj);

    template <typename T>
    void EXPECT_NULLPTR(T* ptr);

    template <typename T>
    void EXPECT_NE_NULLPTR(T* ptr);

    template <typename T>
    void EXPECT_EQ_ARR(T arr, T expected, int arrSize);

    template <typename T>
    void EXPECT_EQ_VEC(std::vector<T> vec, std::vector<T> expected);
}

#include "testing-utils.tpp"