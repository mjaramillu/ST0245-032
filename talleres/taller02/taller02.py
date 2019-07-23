
# greatest common divider
def gdc(p, q):
    if p == 0:
        return q
    if q == 0:
        return p
    residue = p%q
    return gdc(q, residue)
    

# suma grupo
def sum_group(start, nums, target):

# combinations
def combinations(s):

# combinations auxiliary
def _combinations_aux (prefix, s):


# -- TESTS --

def test(value, expected):
    print("Value:", str(value), "Expected:", str(expected), "Passed:", str(value==expected))

test(gcd(12,36),12)
test(gcd(8,12),4)
test(gcd(72,108),36)
test(gcd(162,270),54)
test(sum_group(0, {2,4,8},9),false)
test(sum_group(0, {2,4,8},8),true)
test(sum_group(0, {10,2,2,5},9),true)
test(sum_group(0, {10,2,2,5},17),true)
combinations("abc")
combinations("Eafit")
combinations("Hola")
combinations("Hi")
