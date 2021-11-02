
notes = {"C4":261.63,
"D4":293.66,
"E4":329.63,
"F4":349.23,
"G4":392.00,
"A4":440.00,
"B4":493.88,
"C5":523.25,}
for note, frequency in notes.items():
    print("#define %s %i" % (note, (1000000/(2*frequency))))
