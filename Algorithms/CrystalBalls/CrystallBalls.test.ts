import crystalBalls from "./CrystallBalls";

test("crystal balls return value", () => {
    expect(crystalBalls(new Array(10).fill(true, 2))).toEqual(2);
});

test("crystal balls return -1", () => {
    expect(crystalBalls(new Array(10).fill(false))).toEqual(-1);
});