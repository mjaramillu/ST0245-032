import general
import os
import sys

#TODO: CITATION: https://www.mkyong.com/python/python-how-to-list-all-files-in-a-directory/
#TODO: CITATION: https://www.guru99.com/reading-and-writing-files-in-python.html

def obtain_dna_files():
    path = "dna_samples/"
    files = []
    for r, d, f in os.walk(path):
        for file in f:
            if '.dna' in file:
                filepath = os.path.join(r, file)
                f = open(filepath, "r")
                this_file = {}
                this_file["name"] = file
                this_file["contents"] = f.read()
                files.append(this_file)
                f.close()
    return files

def compare_dna_files():
    files = obtain_dna_files()
    for i in range(len(files)):
        for j in range(i,len(files)):
            if i != j:
                a = files[i]
                b = files[j]
                print("Comparing", a["name"], "with", b["name"], "...")
                print("Size of A:", len(a["contents"])/1000.0, "KiB")
                print("Size of B:", len(b["contents"])/1000.0, "KiB")
                print("Longest common subsequence:", general.longest_common_subsequence(a["contents"], b["contents"]))

def test(value, expected):
    print("Value:", str(value), "Expected:", str(expected), "Passed:",  str(value==expected))

print("Testing lcs...")
test(general.longest_common_subsequence("AXYT", "AYZX"),2)
test(general.longest_common_subsequence("AGGGGGTAB", "GXTXAYB"),4)
test(general.longest_common_subsequence("ABCDGH", "AEDFHR"),3)
compare_dna_files()
print("Testing board...")
test(general.rectangles_in_board(1),1)
test(general.rectangles_in_board(2),2)
test(general.rectangles_in_board(3),3)
test(general.rectangles_in_board(4),5)
test(general.rectangles_in_board(5),8)
test(general.rectangles_in_board(10),89)
