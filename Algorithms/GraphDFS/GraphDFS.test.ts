import dfs, { WeightedAdjacencyList } from "./GraphDFS";

const list: WeightedAdjacencyList = [];

//     >(1)<--->(4) ---->(5)
//    /          |       /|
// (0)     ------|------- |
//    \   v      v        v
//     >(2) --> (3) <----(6)
list[0] = [
    { to: 1, weight: 3 },
    { to: 2, weight: 1 },
];
list[1] = [
    { to: 4, weight: 1 },
];
list[2] = [
    { to: 3, weight: 7 },
];
list[3] = [];
list[4] = [
    { to: 1, weight: 1 },
    { to: 3, weight: 5 },
    { to: 5, weight: 2 },
];
list[5] = [
    { to: 2, weight: 18 },
    { to: 6, weight: 1 },
];
list[6] = [
    { to: 3, weight: 1 },
];

test("graph dfs", function () {
    expect(dfs(list, 0, 6)).toEqual([
        0,
        1,
        4,
        5,
        6,
    ]);

    expect(dfs(list, 6, 0)).toEqual(null);
});
