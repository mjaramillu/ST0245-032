
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

# Compute the number of ways in which a 2*1 rectange can fit into a 2*n board.
def rectangles_in_board(n):
    if n == 0 or n == 1: # Not the worst case
        return 1
    else: # Worst case
        return rectangles_in_board(n-1) + rectangles_in_board(n-2) # C1 + T(n-1) + T(n-2) = c_1 2^(n-1) + c_1 (2^n - 1)
