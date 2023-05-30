import dfs from "./BTDFS";
import tree from "../../DataStructures/BinaryTree/Tree";

test("dfs", () => {
    expect(dfs(tree, 45)).toEqual(true);
    expect(dfs(tree, 7)).toEqual(true);
    expect(dfs(tree, 69)).toEqual(false);
});