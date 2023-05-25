import search from "./LinearSearch";

test("successful linear search", () => {
    expect(search([0, 1, 2], 0)).toBe(true);
});

test("unsuccessful linear search", () => {
    expect(search([0, 1, 2], 4)).toBe(false);
});