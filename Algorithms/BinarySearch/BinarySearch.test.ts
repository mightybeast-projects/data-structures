import search from "./BinarySearch";

test("binary search returns true", () => {
    expect(search([0, 1, 2, 3, 4, 5], 4)).toBe(true);
    expect(search([-10, -9, -4, -2, -1, 0], -2)).toBe(true);
});

test("binary search returns false", () => {
    expect(search([0, 1, 2, 3, 4, 5], 6)).toBe(false);
    expect(search([-10, -9, -4, -2, -1, 0], -11)).toBe(false);
});