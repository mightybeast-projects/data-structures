import BinaryNode from "../../DataStructures/BinaryTree/BinaryTree";
import Queue from "../../DataStructures/Queue/Queue";

export default function bfs<T>(tree: BinaryNode<T>, value: T): boolean {
    const queue = new Queue<BinaryNode<T> | null>();

    queue.enqueue(tree);

    while (queue.length) {
        const node = queue.deque() as BinaryNode<T>;

        if (!node)
            continue;

        if (node.value === value)
            return true;

        queue.enqueue(node.left);
        queue.enqueue(node.right);
    }

    return false;
}