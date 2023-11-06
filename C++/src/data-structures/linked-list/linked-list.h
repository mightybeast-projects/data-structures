template <typename T>
struct Node
{
    T value;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int length = 0;

    void append(T value)
    {
        length++;

        Node<T> *node = new Node<T>();
        node->value = value;

        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
    }

    void prepend(T value)
    {
        length++;

        Node<T> *node = new Node<T>();
        node->value = value;

        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    void insertAt(int index, T value)
    {
        if (indexOutOfBounds(index))
            return;

        if (index == 0)
            return prepend(value);
        if (index == length - 1)
            return append(value);

        length++;

        Node<T> *node = new Node<T>();
        node->value = value;

        Node<T> *nextNode = getAt(index);
        Node<T> *prevNode = nextNode->prev;

        prevNode->next = node;
        node->prev = prevNode;

        nextNode->prev = node;
        node->next = nextNode;
    }

    T get(int index)
    {
        if (indexOutOfBounds(index))
            return (T)NULL;

        return getAt(index)->value;
    }

    T removeAt(int index)
    {
        if (indexOutOfBounds(index))
            return (T)NULL;

        return removeNode(getAt(index));
    }

    T remove(T value)
    {
        Node<T> *node = head;

        while (node != nullptr && node->value != value)
            node = node->next;

        if (node == nullptr)
            return (T)NULL;

        return removeNode(node);
    }

private:
    Node<T> *getAt(int index)
    {
        Node<T> *node = head;

        for (int i = 0; i < index; i++)
            node = node->next;

        return node;
    }

    T removeNode(Node<T> *node)
    {
        length--;

        if (length == 0)
        {
            head = nullptr;
            tail = nullptr;
            return node->value;
        }

        Node<T> *prevNode = node->prev;
        Node<T> *nextNode = node->next;

        if (nextNode != nullptr)
            nextNode->prev = prevNode;

        if (prevNode != nullptr)
            prevNode->next = nextNode;

        if (head == node)
            head = nextNode;

        if (tail == node)
            tail = prevNode;

        return node->value;
    }

    inline bool indexOutOfBounds(int index)
    {
        return index < 0 || index >= length;
    }
};