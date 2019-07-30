#!/usr/bin/python

import HES

def decrypt_attempt(key):
    result = HES.decrypt_from_file("encryptedFile", key)
    if "42" in result:
        return result
    return False

def hanoi(topN, a = "Tower1", b = "Tower2", c = "Tower3"):

def subset(s, base = ""):

def permutations(base, stri):
