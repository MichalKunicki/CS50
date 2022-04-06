import sys
import csv

def main():
    
    # Check for correct command-line usage.
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE SEQUENCE")
    
    # Open file with STRS and copy the STR set avoiding first fieldname (name)
    database = open("./" + sys.argv[1])
    reader = csv.DictReader(database)
    strs = reader.fieldnames[1:]

    # Open DNA sequence and copy into memory.
    with open(sys.argv[2]) as sequence:
        dna = sequence.read()
    
    # Count the number of strs in DNA sequence
    dna_count = {}
    for str in strs:
        dna_count[str] = consecutive_repeats(str, dna)
    
    # Go through CSV to find a match:
    for row in reader:
        if match(strs, dna_count, row):
            print(f"{row['name']}")
            database.close()
            return
            
    # If no match:        
    print("No match")
    database.close()
        

# Maximum number of consecutive repeats in a DNA sequence
def consecutive_repeats(str, dna):
    i = 0
    while str*(i + 1) in dna:
        i += 1
    return i

# Check strs one by one if matching with names from the csv file
def match(strs, dna_count, row):
    for str in strs:
        if dna_count[str] != int(row[str]):
            return False
    return True
    
if __name__ == "__main__":
    main()