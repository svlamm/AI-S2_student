import sys
def add(x, y):
    print(f"type of x: {type(x).__name__}")
    print(f"type of y: {type(y).__name__}")
    try:
        print(f"adding {x} and {y}: result is: {x + y}")
        return x + y
    except TypeError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        return None


add(1,2)
add(1.5, 15)
add("Hello", " world!")
add("sd", 5)


