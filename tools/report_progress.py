#!/usr/bin/env python3

import argparse
import glob
import json
import os
import re

parser = argparse.ArgumentParser(description="Report progress for a specific decompiled file")
parser.add_argument('path', metavar='path', type=str,
                    help='Path of the files to evaluate')
parser.add_argument('label', metavar='label', type=str,
                    help='The name of the reporting progress')
args = parser.parse_args()

def getFiles(path):
    return glob.glob(os.getcwd() + path + "/*.c", recursive = True)

def getPercentage(totalFuncCount, remainingFuncCount):
    return round((totalFuncCount / remainingFuncCount) * 100, 2) or 0

def getColor(totalFuncCount, remainingFuncCount):
    percentage = getPercentage(totalFuncCount, remainingFuncCount)
    if percentage >= 75:
        return "brightgreen"
    elif percentage >= 50:
        return "brightyellow"
    if percentage >= 25:
        return "brightorange"
    else:
        return "brightred"

def getRequiredAsm(fileName):
    with open(filePath, "rt") as f:
        content = f.read()
        pattern = r'^ ?INCLUDE_ASM'
        matches = re.findall(pattern, content, re.MULTILINE)
        return len(matches) | 1

def getFoundFunctions(fileName):
    with open(filePath, "rt") as f:
        content = f.read()
        pattern = r'^ ?[a-zA-Z0-9_]{1,6} [a-zA-Z0-9_]{1,200}\(.{0,100}\) ?(\/\/.{0,400})?({|\n{)'
        matches = re.findall(pattern, content, re.MULTILINE)
        return len(matches) | 1

requireAsmFound = 0
functionsFound = 0

for filePath in getFiles(args.path):
    requireAsmFound += getRequiredAsm(filePath)
    functionsFound += getFoundFunctions(filePath)

report = {
    "schemaVersion": 1,
    "label": args.label,
    "message": repr(getPercentage(functionsFound, requireAsmFound)) + "%",
    "color": getColor(functionsFound, requireAsmFound),
}

print(json.dumps(report))