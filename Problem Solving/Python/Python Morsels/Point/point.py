class Point():
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __eq__(self, other):
        return (self.x, self.y, self.z) == (other.x, other.y, other.z)

    def __add__(self, other):
        if type(other) == Point:
            return Point(self.x + other.x, self.y + other.y, self.z + other.z)
        else:
            raise TypeError(f"Can't add Point object to {type(other)}")

    def __sub__(self, other):
         if type(other) == Point:
            return Point(self.x - other.x, self.y - other.y, self.z - other.z)
         else:
            raise TypeError(f"Can't subtract {type(other)} from Point object")

    def __mul__(self, other):
        if type(other) == int:
            return Point(self.x * other, self.y * other, self.z * other)
        else:
            raise TypeError(f"Can't multiply Point object and {type(other)}")

    def __rmul__(self, other):
        return self.__mul__(other)

    def __repr__(self):
        return f"Point(x={self.x}, y={self.y}, z={self.z})"

    def __iter__(self):
        yield from (self.x, self.y, self.z)
        