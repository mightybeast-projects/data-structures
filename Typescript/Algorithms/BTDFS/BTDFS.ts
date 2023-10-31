import BinaryNode from "../../DataStructures/BinaryTree/BinaryTree";

const dfs = <T>(tree: BinaryNode<T>, value: T): boolean =>
    dfsRecurse(tree, value);

function dfsRecurse<T>(node: BinaryNode<T> | null, value: T): boolean {
    if (!node)
        return false;

    if (node.value === value)
        return true;
    
    if (node.value < value)
        return dfsRecurse(node.right, value);

    return dfsRecurse(node.left, value);
}

export default dfs;