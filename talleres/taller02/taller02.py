
# greatest common divider
def gcd(p, q):
    if p == 0:
        return q
    if q == 0:
        return p
    residue = p%q
    return gcd(q, residue)


# suma grupo
def sum_group(start, nums, target):
    return 0

# combinations
def combinations(s):
    return 0

# combinations auxiliary
def _combinations_aux (prefix, s):
    return 0


# -- TESTS --

def test(value, expected):
    print("Value:", str(value), "Expected:", str(expected), "Passed:", str(value==expected))

test(gcd(12,36),12)
test(gcd(8,12),4)
test(gcd(72,108),36)
test(gcd(162,270),54)
test(sum_group(0, {2,4,8},9),False)
test(sum_group(0, {2,4,8},8),True)
test(sum_group(0, {10,2,2,5},9),True)
test(sum_group(0, {10,2,2,5},17),True)
combinations("abc")
combinations("Eafit")
combinations("Hola")
combinations("Hi")
