import BinaryNode from "../../DataStructures/BinaryTree/BinaryTree";

export const compare = <T>(
    a: BinaryNode<T> | null,
    b: BinaryNode<T> | null): boolean => compareRecurse(a, b);

function compareRecurse<T>(
    a: BinaryNode<T> | null,
    b: BinaryNode<T> | null): boolean {
    if (a === b)
        return true;
    
    if (!a || !b || a.value !== b.value)
        return false;
    
    return compareRecurse(a.left, b.left) && compareRecurse(a.right, b.right);
}