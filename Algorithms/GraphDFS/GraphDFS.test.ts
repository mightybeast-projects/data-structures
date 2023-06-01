import { graphList } from "../../DataStructures/Graph/Graph";
import dfs from "./GraphDFS";

test("graph dfs", function () {
    expect(dfs(graphList, 0, 6)).toEqual([
        0,
        1,
        4,
        5,
        6,
    ]);

    expect(dfs(graphList, 6, 0)).toEqual(null);
});
