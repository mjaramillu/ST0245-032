
# Obtain the longest common subsequence for two strings of text
def longest_common_subsequence(chain_a, chain_b):
    if len(chain_a) == 0 or len(chain_b) == 0:
        return 0
    if chain_a[len(chain_a) -1] == chain_b[len(chain_b) -1]:
        return longest_common_subsequence(chain_a[:-1], chain_b[:-1]) + 1
    a = longest_common_subsequence(chain_a[:-1], chain_b)
    b = longest_common_subsequence(chain_a, chain_b[:-1])
    return max(a,b)
