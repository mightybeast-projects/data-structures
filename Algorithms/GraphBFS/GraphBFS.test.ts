import { graphMatrix } from "../../DataStructures/Graph/Graph";
import bfs from "./GraphBFS";

test("graph bfs", function () {
    expect(bfs(graphMatrix, 0, 6)).toEqual([
        0,
        1,
        4,
        5,
        6,
    ]);

    expect(bfs(graphMatrix, 6, 0)).toEqual(null);
});
