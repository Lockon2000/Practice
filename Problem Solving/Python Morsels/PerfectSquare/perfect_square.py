from math import sqrt
import decimal
from cmath import sqrt as csqrt

def is_perfect_square(x, *, complex=False):
    complexType = type(1j)
    c = decimal.getcontext()

    if not complex:
        t = type(x)
        if not (t == int or t == float or t == decimal.Decimal):
            raise TypeError

        d = decimal.Decimal(x)

        if d < 0:
            result = False
        else:
            d.sqrt().to_integral_exact()
            if not c.flags[decimal.Inexact]:
                result = True
            else:
                result = False
    else:
        t = type(x)
        if not (t == int or t == float or t == complexType):
            raise TypeError

        y = csqrt(x)
        if y.real.is_integer() and y.imag.is_integer():
            result = True
        else:
            result = False

    c.clear_flags()

    return result

