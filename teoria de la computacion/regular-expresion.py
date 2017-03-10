import re
expReg = re.compile(r"^C0{5}\d{2}\|(ENG|FRE|POR|GER|RUS|SPA)\|(S|P)\|L([\d]{7})\|(PF|VW|VC|)\|S([\d]{7})\|[\+\-\w\,\'\s\:\()]*\|(0|3)\|")

tex = open("texto.txt", "r")

for line in tex:
    if re.match(expReg, line):
        print ('GOOD')
    else:
        print ('BAD')

tex.close()
