import { tree, anotherTree } from "../../DataStructures/BinaryTree/Tree";
import { compare } from "./BTComparison";


test("Compare Binary Trees", () => {
    expect(compare(tree, tree)).toEqual(true);
    expect(compare(tree, anotherTree)).toEqual(false);
});