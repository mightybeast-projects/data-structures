import dijkstras from "./GraphDijkstras";
import { anotherGraphList } from "../../DataStructures/Graph/Graph";

test("dijkstra via adj list", () => {
    expect(dijkstras(0, 6, anotherGraphList)).toEqual([0, 1, 4, 5, 6]);
});