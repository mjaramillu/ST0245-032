#!/usr/bin/python

import HES

# La clave es una permutación de abcdefghijkl
def decrypt_attempt(key):
    result = HES.decrypt_from_file("encryptedFile", key)
    if "ything is 42" in result:
        return result
    return False

def hakiar(start, key, change):
    if decrypt_attempt(key)==True:
         return True
    if start == change:
        change = len(key)-1
        return hakiar(start+1, key, change)
    else:
        chart = key[start]
        key[start] = key[len(key)-1]
        key[len(key)-1] = chart
        return hakiar(start, key, change-1)
    return False
hakiar(0, "abcdefghijkl", 11)
