export default function quickSort(arr: number[]): void {
    quickSortRecurse(arr, 0, arr.length - 1);
}

function quickSortRecurse(arr: number[], low: number, high: number): void {
    if (low >= high)
        return;

    const pivotIdx = partition(arr, low, high);
    quickSortRecurse(arr, low, pivotIdx - 1);
    quickSortRecurse(arr, pivotIdx + 1, high);
}

function partition(arr: number[], low: number, high: number): number {
    const pivot = arr[high];

    let idx = low - 1;

    for (let i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            idx++;
            const tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }

    idx++;
    arr[high] = arr[idx];
    arr[idx] = pivot;

    return idx;
}