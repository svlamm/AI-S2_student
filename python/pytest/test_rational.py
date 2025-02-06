from rational import Rational


def test_constructor():
    r = Rational(3, 4)
    assert str(r) == "3/4"


def test_equality():
    r = Rational(1, 2)
    assert r == Rational(1, 2)


def test_inequality():
    r = Rational(1, 2)
    assert r != Rational(1, 3)


def test_constructor_reduction():
    r = Rational(2, 4)
    assert r == Rational(1, 2)


def test_constructor_default():
    r = Rational(2)
    assert r == Rational(2, 1)


def test_multiply_integer():
    r = Rational(3, 4)
    x = r * 7
    assert r == Rational(3, 4)
    assert x == Rational(21, 4)


def test_multiply_integer_reduction():
    r = Rational(3, 10)
    x = r * 5
    assert r == Rational(3, 10)
    assert x == Rational(3, 2)


def test_multiply_integer_inplace():
    r = Rational(3, 4)
    r *= 7
    assert r == Rational(21, 4)


def test_multiply_integer_inplace_reduction():
    r = Rational(3, 10)
    r *= 5
    assert r == Rational(3, 2)


def test_multiply_rational():
    r = Rational(3, 4)
    x = r * Rational(9, 7)
    assert r == Rational(3, 4)
    assert x == Rational(27, 28)


def test_multiply_rational_reduction():
    r = Rational(3, 10)
    x = r * Rational(4, 6)
    assert r == Rational(3, 10)
    assert x == Rational(1, 5)


def test_multiply_rational_inplace():
    r = Rational(3, 4)
    r *= Rational(9, 7)
    assert r == Rational(27, 28)


def test_multiply_rational_inplace_reduction():
    r = Rational(3, 10)
    r *= Rational(4, 6)
    assert r == Rational(1, 5)


def test_add_rational():
    r = Rational(3, 10)
    x = r + Rational(6, 7)
    assert r == Rational(3, 10)
    assert x == Rational(81, 70)


def test_add_rational_reduction():
    r = Rational(23, 147)
    x = r + Rational(5, 91)
    assert r == Rational(23, 147)
    assert x == Rational(404, 1911)
