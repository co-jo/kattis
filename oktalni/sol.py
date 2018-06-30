import sys

dict = {
    '000': '0', '001': '1', '010': '2', '011': '3',
    '100': '4', '101': '5', '110': '6', '111': '7'
}

binary = str(input())
length = len(binary)

if (length % 3):
    pad = 3 - length % 3
    binary = (pad * '0') + binary

oct = ""
for i in range(0, len(binary), 3):
    oct = oct + dict[binary[i:i+3]]

print oct

