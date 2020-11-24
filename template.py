from sys import argv
from os import system as cmd
from os.path import abspath as path
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("filename", type=str)
parser.add_argument("-o", "--output", type=str, help="the input/output files")
args = parser.parse_args()

f = ""

cmd(f"cp ~/Documents/GitHub/cp/template.cpp {args.filename}.cpp")

ofile = args.filename if not args.output else args.output

with open(f"{args.filename}.cpp") as fin:
    f = fin.readlines()

ind = 0

for i, s in enumerate(f):
    if "std::ios_base::sync_with_stdio(false);cin.tie(0);" in s:
        ind = i

f.insert(ind+1, f"\n\t// setIO(\"{ofile}\");\n")

with open(args.filename + ".cpp", "w+") as fout:
    for i in f:
        fout.write(i)
