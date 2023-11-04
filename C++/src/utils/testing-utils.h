namespace TestingUtils
{
    template <typename T>
    void EXPECT_EQ_ARR(T *arr, T *expected, int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
            EXPECT_EQ(arr[i], expected[i]);
    }

    template <typename T>
    void EXPECT_NULL(T obj)
    {
        EXPECT_EQ(obj, NULL);
    }

    template <typename T>
    void EXPECT_NULLPTR(T *ptr)
    {
        EXPECT_EQ(ptr, nullptr);
    }
}