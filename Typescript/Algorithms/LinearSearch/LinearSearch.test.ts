import search from "./LinearSearch";

test("linear search", () => {
    expect(search([0, 1, 2], 0)).toBe(true);
    expect(search([0, 1, 2], 4)).toBe(false);
});