from sys import argv

originalCSV = open(argv[1]).read()
fixedCSV = open(argv[2], "w")

fixedCSV.write(originalCSV.replace("|", ","))