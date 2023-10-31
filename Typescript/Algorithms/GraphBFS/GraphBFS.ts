import Queue from "../../DataStructures/Queue/Queue";

export type WeightedAdjacencyMatrix = number[][];

export default function dfs(
    graph: WeightedAdjacencyMatrix,
    source: number,
    value: number): number[] | null {

    const seen = new Array(graph.length).fill(false);
    const prev = new Array(graph.length).fill(-1);
    const queue = new Queue();

    queue.enqueue(source);
    seen[source] = true;

    do {
        const curr = queue.deque() as number;
        if (curr === value)
            break;

        const adjs = graph[curr];

        for (let i = 0; i < adjs.length; i++) {
            if (adjs[i] === 0)
                continue;

            if (seen[i])
                continue;

            seen[i] = true;
            prev[i] = curr;
            queue.enqueue(i);
        }
    } while (queue.length);

    if (prev[value] === -1)
        return null;

    let curr = value;
    const out: number[] = [];

    while (prev[curr] !== -1) {
        out.push(curr);
        curr = prev[curr];
    }

    return [source].concat(out.reverse());
}