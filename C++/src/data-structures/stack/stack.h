template <typename T>
struct Node
{
    T value;
    Node<T> *prev = nullptr;
};

template <typename T>
class Stack
{
public:
    int length = 0;
    Node<T> *head = nullptr;

    Stack() {}

    void push(T value)
    {
        length++;

        Node<T> node;
        node.value = value;

        if (head == nullptr)
        {
            head = &node;
            return;
        }

        node.prev = head;
        head = &node;
    }
};