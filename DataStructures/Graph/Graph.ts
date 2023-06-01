import { WeightedAdjacencyMatrix } from "../../Algorithms/GraphBFS/GraphBFS";
import { WeightedAdjacencyList } from "../../Algorithms/GraphDFS/GraphDFS";

export const graphList: WeightedAdjacencyList = [];

//     >(1)<--->(4) ---->(5)
//    /          |       /|
// (0)     ------|------- |
//    \   v      v        v
//     >(2) --> (3) <----(6)
graphList[0] = [
    { to: 1, weight: 3 },
    { to: 2, weight: 1 },
];
graphList[1] = [
    { to: 4, weight: 1 },
];
graphList[2] = [
    { to: 3, weight: 7 },
];
graphList[3] = [];
graphList[4] = [
    { to: 1, weight: 1 },
    { to: 3, weight: 5 },
    { to: 5, weight: 2 },
];
graphList[5] = [
    { to: 2, weight: 18 },
    { to: 6, weight: 1 },
];
graphList[6] = [
    { to: 3, weight: 1 },
];

export const anotherGraphList: WeightedAdjacencyList = [];

//      (1) --- (4) ---- (5)
//    /  |       |       /|
// (0)   | ------|------- |
//    \  |/      |        |
//      (2) --- (3) ---- (6)
anotherGraphList[0] = [
    { to: 1, weight: 3 },
    { to: 2, weight: 1 },
];
anotherGraphList[1] = [
    { to: 0, weight: 3 },
    { to: 2, weight: 4 },
    { to: 4, weight: 1 },
];
anotherGraphList[2] = [
    { to: 1, weight: 4 },
    { to: 3, weight: 7 },
    { to: 0, weight: 1 },
];
anotherGraphList[3] = [
    { to: 2, weight: 7 },
    { to: 4, weight: 5 },
    { to: 6, weight: 1 },
];
anotherGraphList[4] = [
    { to: 1, weight: 1 },
    { to: 3, weight: 5 },
    { to: 5, weight: 2 },
];
anotherGraphList[5] = [
    { to: 6, weight: 1 },
    { to: 4, weight: 2 },
    { to: 2, weight: 18 },
];
anotherGraphList[6] = [
    { to: 3, weight: 1 },
    { to: 5, weight: 1 },
];

export const graphMatrix: WeightedAdjacencyMatrix = [
    [0, 3, 1,  0, 0, 0, 0], // 0
    [0, 0, 0,  0, 1, 0, 0],
    [0, 0, 7,  0, 0, 0, 0],
    [0, 0, 0,  0, 0, 0, 0],
    [0, 1, 0,  5, 0, 2, 0],
    [0, 0, 18, 0, 0, 0, 1],
    [0, 0, 0,  1, 0, 0, 1],
];