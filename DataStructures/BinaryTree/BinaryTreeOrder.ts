export type BinaryNode<T> = {
    value: T;
    left: BinaryNode<T> | null;
    right: BinaryNode<T> | null;
}

export const BTPreOrder = <T>(tree: BinaryNode<T>): T[] =>
    preOrderRecurse(tree, []);

export const BTInOrder = <T>(tree: BinaryNode<T>): T[] =>
    inOrderRecurse(tree, []);

export const BTPostOrder = <T>(tree: BinaryNode<T>): T[] =>
    postOrderRecurse(tree, []);

function preOrderRecurse<T>(node: BinaryNode<T> | null, result: T[]): T[] {
    if (!node) return result;

    result.push(node.value);
    
    if (node.left)
        preOrderRecurse(node.left, result);
    if (node.right)
        preOrderRecurse(node.right, result);

    return result;
}

function inOrderRecurse<T>(node: BinaryNode<T> | null, result: T[]): T[] {
    if (!node) return result;

    if (node.left)
        inOrderRecurse(node.left, result);

    result.push(node.value);

    if (node.right)
        inOrderRecurse(node.right, result);

    return result;
}

function postOrderRecurse<T>(node: BinaryNode<T> | null, result: T[]): T[] {
    if (!node) return result;

    if (node.left)
        postOrderRecurse(node.left, result);
    if (node.right)
        postOrderRecurse(node.right, result);

    result.push(node.value);

    return result;
}

export default BinaryNode;