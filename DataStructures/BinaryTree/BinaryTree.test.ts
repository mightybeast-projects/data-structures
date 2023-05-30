import { btPreOrderTraversal } from "./BinaryTree";
import { btInOrderTraversal } from "./BinaryTree";
import { btPostOrderTraversal } from "./BinaryTree";
import tree from "./Tree";

test("pre order traversal", function () {
    expect(btPreOrderTraversal(tree)).toEqual([
        20,
        10,
        5,
        7,
        15,
        50,
        30,
        29,
        45,
        100,
    ]);
});

test("in order traversal", function () {
    expect(btInOrderTraversal(tree)).toEqual([
        5,
        7,
        10,
        15,
        20,
        29,
        30,
        45,
        50,
        100,
    ]);
});

test("post order traversal", function () {
    expect(btPostOrderTraversal(tree)).toEqual([
        7,
        5,
        15,
        10,
        29,
        45,
        30,
        100,
        50,
        20,
    ]);
});