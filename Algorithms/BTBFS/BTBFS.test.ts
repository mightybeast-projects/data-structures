import tree from "../../DataStructures/BinaryTree/Tree";
import bfs from "./BTBFS";

test("bt bfs test", () => {
    expect(bfs(tree, 45)).toEqual(true);
    expect(bfs(tree, 7)).toEqual(true);
    expect(bfs(tree, 69)).toEqual(false);
});