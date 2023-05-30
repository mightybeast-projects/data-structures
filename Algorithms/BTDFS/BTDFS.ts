import BinaryNode from "../../DataStructures/BinaryTree/BinaryTree";

const dfs = <T>(tree: BinaryNode<T>, value: T): boolean =>
    dfsRecurse(tree, value);

function dfsRecurse<T>(node: BinaryNode<T> | null, value: T): boolean {
    if (!node)
        return false;

    if (node.value === value)
        return true;
    
    return dfsRecurse(node.left, value) || dfsRecurse(node.right, value);
}

export default dfs;