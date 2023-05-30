import bubbleSort from "./BubbleSort";

test("bubble sort", () => {
    const arr = [1, 8, 3, 7, 4, 2];
    bubbleSort(arr);
    expect(arr).toEqual([1, 2, 3, 4, 7, 8]);
});