class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()
        self.lookup = {}


    def get(self, key: int) -> int:
        if key not in self.lookup:
            return -1

        self.cache.move_to_end(key)
        return self.lookup[key]

    def put(self, key: int, value: int) -> None:
        if key in self.lookup:
            self.cache.move_to_end(key)
        self.lookup[key] = value
        self.cache[key] = value

        if len(self.cache) > self.capacity:
            lru_key = next(iter(self.cache))
            del self.cache[lru_key]
            del self.lookup[lru_key]