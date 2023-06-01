import LRU from "./LRU";

test("LRU", () => {
    const lru = new LRU<string, number>(3);

    expect(lru.get("foo")).toEqual(undefined);
    lru.update("foo", 69);
    expect(lru.get("foo")).toEqual(69);

    lru.update("bar", 420);
    expect(lru.get("bar")).toEqual(420);

    lru.update("baz", 1337);
    expect(lru.get("baz")).toEqual(1337);

    lru.update("ball", 69420);
    expect(lru.get("ball")).toEqual(69420);
    expect(lru.get("foo")).toEqual(undefined);
    expect(lru.get("bar")).toEqual(420);
    lru.update("foo", 69);
    expect(lru.get("bar")).toEqual(420);
    expect(lru.get("foo")).toEqual(69);

    expect(lru.get("baz")).toEqual(undefined);
});
