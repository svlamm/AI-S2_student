class Rational:
    """
    This is a data type that implements rational (fractional) values.
    The numerator and denominator are stored as two integers.
    The appropriate constructors and operators are provided.

    Rational values are always simplified (i.e. reduced): the numerator
    and denominator have no common factors.
    """

    def __init__(self, numerator, denominator=1):
        """ Construct a rational object.

        This constructor initializes a rational from its numerator and denominator.
        The default value for the denominator is 1, so a rational be initialized
        with just a whole value.
        """
        self.numerator = numerator
        self.denominator = denominator
        self._reduce()

    def __eq__(self, other):
        """ Compare two rational values.

        This operator tests for equality. It returns true
        if and only if the numerator and denominator of both
        operands are equal.
        """
        return self.numerator == other.numerator and self.denominator == other.denominator

    def __mul__(self, other):
        """ Multiply a rational.

        This operator multiplies a rational value by another value and
        returns the result. The other value can either be an integer (int)
        or another rational.
        """
        if isinstance(other, int):
            numerator = self.numerator * other
            denominator = self.denominator 
            return Rational(numerator, denominator)

        elif isinstance(other, Rational):
            numerator = self.numerator * other.numerator
            denominator = self.denominator * other.denominator

            return Rational(numerator, denominator)
        else:
            raise TypeError

    def __imul__(self, other):
        """ Multiply a rational in-place.

        This operator multiplies a rational value by another value in-place.
        The other value can either be an integer (int) or another rational.
        """
        if isinstance(other, int):
            self.numerator *= other
            self._reduce()
            return self

        elif isinstance(other, Rational):
            self.numerator *= other.numerator
            self.denominator *= other.denominator
            self._reduce()
            return self
        else:
            raise TypeError

    def __add__(self, other):
        """ Add a rational to another rational.

        This operator adds a rational value and a rational variable.
        """
        numerator = self.numerator * other.denominator + other.numerator * self.denominator
        denominator = self.denominator * other.denominator
        return Rational(numerator, denominator)

    def __repr__(self):
        """ Represent a rational value.

        This method prints a Rational in the format numerator/denominator
        where both values are printed as decimal values.
        """
        return f"{int(self.numerator)}/{int(self.denominator)}"

    def _reduce(self):
        a = self.numerator
        b = self.denominator

        while b:
            t = b
            b = a % b
            a = t

        if a:
            self.numerator //= a
            self.denominator /= a
