type Node<T> = {
    value: T;
    next?: Node<T>;
    prev?: Node<T>;
}

export default class LinkedList<T> {
    public head?: Node<T>;
    public tail?: Node<T>;
    public length: number;

    constructor() {
        this.length = 0;
        this.head = undefined;
        this.tail = undefined;
    }

    append(item: T): void {
        this.length++;
        const node: Node<T> = { value: item };

        if (!this.tail) {
            this.tail = node;
            this.head = node;
            return;
        }

        node.prev = this.tail;
        this.tail.next = node;
        this.tail = node;
    }

    prepend(item: T): void {
        this.length++;
        const node: Node<T> = { value: item };

        if (!this.head) {
            this.head = node;
            this.tail = node;
            return;
        }

        node.next = this.head;
        this.head.prev = node;
        this.head = node;
    }

    insertAt(index: number, item: T): void {
        if (index > this.length) {
            throw new Error("index is larger than list length");

        } else if (index === this.length) {
            this.append(item);
            return;
        } else if (index === 0) {
            this.prepend(item);
            return;
        }

        this.length++;

        const curr = this.getAt(index) as Node<T>;
        const node: Node<T> = { value: item };

        node.next = curr;
        node.prev = curr.prev;
        curr.prev = node;
        if (node.prev)
            node.prev.next = curr;

    }

    remove(item: T): T | undefined {
        var curr = this.head;
        for (let i = 0; i < this.length && curr; i++) {
            if (curr.value === item)
                break;
            curr = curr.next;
        }

        if (!curr)
            return undefined;

        return this.removeNode(curr);
    }

    removeAt(index: number): T | undefined {
        const node = this.getAt(index);

        if (!node)
            return undefined;

        return this.removeNode(node);
    }

    get(index: number): T | undefined {
        return this.getAt(index)?.value;
    }

    private removeNode(node: Node<T>): T | undefined {
        this.length--;
        if (this.length === 0) {
            const out = this.head?.value;
            this.head = undefined;
            this.tail = undefined;
            return out;
        }

        if (node.prev)
            node.prev.next = node.next;
        if (node.next)
            node.next.prev = node.prev;

        if (node === this.head)
            this.head = node.next;
        if (node === this.tail)
            this.tail = node.prev;

        node.prev = undefined;
        node.next = undefined;
        return node.value;
    }

    private getAt(index: number): Node<T> | undefined {
        var curr = this.head;
        for (let i = 0; i < index && curr; i++) {
            curr = curr.next;
        }
        return curr;
    }
}