from cs50 import get_int

height = get_int(f"Pyramid height?:\n")

while(height < 1 or height > 8):
    height = get_int(f"Pyramid height?:\n")

width = 1
for i in range(height):
    print((height - 1) * " " + width * "#" )
    height -= 1
    width += 1

