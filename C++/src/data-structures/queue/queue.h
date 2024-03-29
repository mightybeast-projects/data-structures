namespace QueueNode
{
    template <typename T>
    struct Node
    {
        T value;
        Node<T> *next = nullptr;
    };
};

namespace Queue
{
    using namespace QueueNode;

    template <typename T>
    class Queue
    {
    public:
        int length = 0;
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;

        void enqueue(T value)
        {
            length++;

            Node<T> *node = new Node<T>;
            node->value = value;

            if (head == nullptr)
                head = node;

            if (tail != nullptr)
                tail->next = node;

            tail = node;
        }

        T dequeue()
        {
            if (head == nullptr)
                return T();

            length--;

            Node<T> *headNode = head;
            head = headNode->next;
            headNode->next = nullptr;

            if (length == 0)
                tail = nullptr;

            return headNode->value;
        }

        T peek()
        {
            if (head == nullptr)
                return T();

            return head->value;
        }
    };
};