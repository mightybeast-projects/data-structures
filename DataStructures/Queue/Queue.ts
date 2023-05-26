type QNode<T> = {
    value: T;
    next?: QNode<T>;
}

export default class Queue<T> {
    public length: number = 0;
    public head?: QNode<T> = undefined;
    public tail?: QNode<T> = undefined;

    enqueue(item: T): T | undefined {
        this.length++;
        const node: QNode<T> = { value: item };

        if (!this.tail) {
            this.head = node;
            this.tail = node;
            return this.head.value;
        }

        this.tail.next = node;
        this.tail = node;

        return node.value;
    }

    deque(): T | undefined {
        if (!this.head)
            return undefined;
        
        this.length--;
        const currHead = this.head;
        this.head = this.head.next;
        currHead.next = undefined;

        if (this.length === 0)
            this.tail = undefined;

        return currHead.value;
    }

    peek = (): T | undefined => this.head?.value;
};