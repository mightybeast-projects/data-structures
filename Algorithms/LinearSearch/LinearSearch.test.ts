import search from "./LinearSearch";

test("linear search returns true", () => {
    expect(search([0, 1, 2], 0)).toBe(true);
});

test("linear search returns false", () => {
    expect(search([0, 1, 2], 4)).toBe(false);
});