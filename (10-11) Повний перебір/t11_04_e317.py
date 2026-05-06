import sys

sys.setrecursionlimit(20000)
sys.set_int_max_str_digits(0)
def karatsuba(x, y):

    if x < 10 or y < 10:
        return x * y
    n = max(len(str(x)), len(str(y)))
    m = n // 2
    power = 10 ** m
    x_high, x_low = divmod(x, power)
    y_high, y_low = divmod(y, power)
    z0 = karatsuba(x_low, y_low)
    z2 = karatsuba(x_high, y_high)
    z1 = karatsuba((x_low + x_high), (y_low + y_high)) - z0 - z2
    result = (z2 * (10 ** (2 * m))) + (z1 * power) + z0
    
    return result

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    a = int(input_data[0])
    b = int(input_data[1])
    

    print(karatsuba(a, b))

if __name__ == '__main__':
    main()
