import crystalBalls from "./CrystallBalls";

test("crystal balls", () => {
    expect(crystalBalls(new Array(10).fill(true, 2))).toEqual(2);
    expect(crystalBalls(new Array(10).fill(false))).toEqual(-1);
});