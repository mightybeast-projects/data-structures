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

        Node<T> *node = new Node<T>;
        node->value = value;

        if (head == nullptr)
        {
            head = node;
            return;
        }

        node->prev = head;
        head = node;
    }

    T pop()
    {
        if (head == nullptr)
            return (T)NULL;

        length--;

        Node<T> *head = this->head;
        this->head = head->prev;
        delete head->prev;

        return head->value;
    }

    T peek()
    {
        return head->value;
    }
};