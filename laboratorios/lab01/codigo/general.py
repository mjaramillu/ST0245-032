
# Obtain the longest common subsequence for two strings of text
def longest_common_subsequence(chain_a, chain_b, index_a = -2, index_b = -2):
    if index_a == -2 or index_b == -2:
        index_a = len(chain_a) - 1
        index_b = len(chain_b) - 1
    if index_a == -1 or index_b == -1:
        return 0
    if chain_a[index_a] == chain_b[index_b]:
        #print(len(chain_a), len(chain_b))
        return longest_common_subsequence(chain_a, chain_b, index_a - 1, index_b - 1) + 1
    a = longest_common_subsequence(chain_a, chain_b, index_a -1, index_b)
    b = longest_common_subsequence(chain_a, chain_b, index_a, index_b - 1)
    return max(a,b)
