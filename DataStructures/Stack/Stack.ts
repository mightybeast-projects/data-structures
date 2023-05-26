type Node<T> = {
    value: T;
    prev?: Node<T>;
}

export default class Stack<T> {
    public length: number = 0;
    public head?: Node<T> = undefined;

    push(item: T): void {
        this.length++;
        const node: Node<T> = { value: item };

        if (!this.head) {
            this.head = node;
            return;
        }

        node.prev = this.head;
        this.head = node;
    }

    pop(): T | undefined {
        if (!this.head)
            return undefined;

        this.length--;
        
        const prevHead = this.head;
        this.head = this.head.prev;
        prevHead.prev = undefined;

        if (this.length === 0)
            this.head = undefined;

        return prevHead.value;
    }

    peek = (): T | undefined => this.head?.value;
}