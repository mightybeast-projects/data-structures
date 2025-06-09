#include <gtest/gtest.h>
#include <vector>

namespace testingUtils
{
    using namespace std;

    template <typename T>
    void EXPECT_EQ_ARR(T arr, T expected, int arrSize);

    template <typename T>
    void EXPECT_EQ_VEC(vector<T> vec, vector<T> expected);

    template <typename T>
    void EXPECT_NULL(T obj);

    template <typename T>
    void EXPECT_NOT_NULL(T obj);

    template <typename T>
    void EXPECT_NULLPTR(T *ptr);

    template <typename T>
    void EXPECT_NE_NULLPTR(T *ptr);
}

#include "testing-utils.tpp"