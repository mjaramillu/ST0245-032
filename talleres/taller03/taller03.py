#!/usr/bin/python

import matplotlib.pyplot as plt
import HES
import math
import time

# La clave es una permutación de abcdefghijkl
def decrypt_attempt(key):
    result = HES.decrypt_from_file("dinosaurios", key)
    print(key, result)
    if key == "cdba":
        print(result)
        #time.sleep(5)
    if "dinosaurios" in result:
        return result
    return False

def print_hanoi(state):
    maximum = max(len(state[0]), len(state[1]), len(state[2]))
    for i in range(maximum,-1,-1):
        string = ""
        for t in state:
            if i in t:
                string += str(t[i]) + " "
            else:
                string += "  "
        print(string)
    print("")

attempts = 0

def swap(string, a, b):
    result = ""
    for i in range(len(string)):
        if i == a:
            result += string[b]
        elif i == b:
            result += string[a]
        else:
            result += string[i]
    return result

def hakiar(dict, indices = []):
    #print(dict, indices)
    if len(indices) == len(dict):
        result = ""
        for i in indices:
            result += dict[i]
        decrypt_attempt(result)
        return
    for i in range(len(dict)):
        if not i in indices:
            new_indices = indices.copy()
            new_indices.append(i)
            hakiar(dict,new_indices)



hakiar("abcd")

moves = 0

def move_piece(state, source, target):
    global moves
    moves = moves + 1
    print(moves, "Moving", source, "->", target)
    source_piece = state[source][len(state[source]) - 1]
    if len(state[target]) > 1:
        target_piece = state[target][len(state[target]) - 1]
        if source_piece > target_piece:
            raise ValueError("Piece can't be moved there!")
    state[target][len(state[target])] = source_piece
    del state[source][len(state[source]) - 1]
    print_hanoi(state)
    #time.sleep(0.5)

def solve_hanoi(state, level, source, target, rest):
    if level == 1:
        move_piece(state, source, target)
    if level > 1:
        solve_hanoi(state, level - 1, source, rest, target)
        solve_hanoi(state, 1, source, target, rest)
        solve_hanoi(state, level - 1, rest, target, source)

def hanoi(topN):
    state = [{}, {}, {}]
    for i in range(topN):
        state[0][i]=topN - i
    print_hanoi(state)
    time.sleep(0.5)
    solve_hanoi(state, len(state[0]), 0, 2, 1)
'''
axis = []
values = []
for i in range(1,17):
    hanoi(i)
    axis.append(i)
    values.append(moves)
    moves = 0
plt.plot(axis, values)
plt.show()'''
