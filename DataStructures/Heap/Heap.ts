export default class MinHeap {
    public length: number = 0;
    private data: number[] = [];

    insert(item: number): void {
        this.data[this.length] = item;
        this.heapifyUp(this.length);
        this.length++;
    }

    delete(): number | undefined {
        if (this.length === 0)
            return undefined;

        const out = this.data[0];
        this.length--;

        if (this.length === 0) {
            this.data = [];
            return out;
        }
        
        this.data[0] = this.data[this.length];
        this.heapifyDown(0);

        return out;
    }

    private heapifyUp(nodeIndex: number): void {
        if (nodeIndex === 0)
            return;

        const parentIndex = Math.floor((nodeIndex - 1) / 2);
        const node = this.data[nodeIndex];
        const parent = this.data[parentIndex];

        if (node < parent) {
            this.data[parentIndex] = node;
            this.data[nodeIndex] = parent;

            this.heapifyUp(parentIndex);
        }
    }

    private heapifyDown(nodeIndex: number): void {
        const leftChildIndex = 2 * nodeIndex + 1;
        const rightChildIndex = 2 * nodeIndex + 2;
        
        if (nodeIndex >= this.length || leftChildIndex >= this.length)
            return;

        const leftChild = this.data[leftChildIndex];
        const rightChild = this.data[rightChildIndex];
        const node = this.data[nodeIndex];

        if (leftChild > rightChild && node > rightChild) {
            this.data[rightChildIndex] = node;
            this.data[nodeIndex] = rightChild;
            this.heapifyDown(rightChildIndex);
        } else if (rightChild > leftChild && node > leftChild) {
            this.data[leftChildIndex] = node;
            this.data[nodeIndex] = leftChild;
            this.heapifyDown(leftChildIndex);
        }

    }
}