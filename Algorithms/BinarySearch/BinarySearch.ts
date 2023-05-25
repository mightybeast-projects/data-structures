export default function binarySearch(arr: number[], value: number): boolean {
    let low = 0;
    let high = arr.length;

    do {
        const median = Math.floor(low + (high - low) / 2);
        const arrValue = arr[median];
        if (arrValue === value)
            return true;
        else if (value > arrValue)
            low = median + 1;
        else
            high = median;
    } while (low < high);

    return false;
}