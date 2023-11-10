#include <vector>

using namespace std;

namespace MinHeap
{
    class MinHeap
    {
    public:
        int length = 0;

        void insert(int value);

        int remove();

        int peek();

    private:
        vector<int> arr = {};

        void heapifyUp(int nodeIndex);

        void heapifyDown(int nodeIndex);
    };

}