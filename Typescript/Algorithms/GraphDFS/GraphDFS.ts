type GraphEdge = { to: number, weight: number };

export type WeightedAdjacencyList = GraphEdge[][];

export default function dfs(
    graph: WeightedAdjacencyList,
    source: number,
    value: number): number[] | null {

    const seen: boolean[] = new Array(graph.length).fill(false);
    const path: number[] = [];

    dfsRecurse(graph, source, value, seen, path);

    if (path.length === 0)
        return null;

    return path;
}

function dfsRecurse(
    graph: WeightedAdjacencyList,
    curr: number,
    value: number,
    seen: boolean[],
    path: number[]): boolean {

    if (seen[curr])
        return false;

    seen[curr] = true;

    path.push(curr);
    if (curr === value)
        return true;

    const list = graph[curr];

    for (let i = 0; i < list.length; i++)
        if (dfsRecurse(graph, list[i].to, value, seen, path))
            return true;

    path.pop();

    return false;
}