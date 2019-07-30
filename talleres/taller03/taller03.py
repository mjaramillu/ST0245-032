#!/usr/bin/python

import HES

# La clave es una permutación de abcdefghijkl
def decrypt_attempt(key):
    result = HES.decrypt_from_file("encryptedFile", key)
    if "ything is 42" in result:
        return result
    return False

def hakiar(start):
    key = "abcd"
    if decrypt_attempt("abcd") return true
    else

def generarClave(start, key, change):
    if(start == len(key)-1) return key
    if(start == change)
        change = len(key)-1
        return generarClave(start+1, key, change)
    else
        chart = key[start]
        key[start] = key[change]
        key[change] = chart
        return generarClave(start, key, change-1)
