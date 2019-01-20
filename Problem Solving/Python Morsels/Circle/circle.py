from math import pi

class Circle:
    def __init__(self, radius=1):
        self.radius = radius

    @property
    def radius(self):
        return self.__radius

    @radius.setter
    def radius(self, radius):
        if radius < 0:
            raise ValueError("Radius cannot be negative")
        else:
            self.__radius = radius

    @property
    def diameter(self):
        return 2*self.radius

    @diameter.setter
    def diameter(self, diameter):
        self.radius = diameter/2

    @property
    def area(self):
        return pi*self.radius**2

    def __repr__(self):
        return f"Circle({self.radius})"
