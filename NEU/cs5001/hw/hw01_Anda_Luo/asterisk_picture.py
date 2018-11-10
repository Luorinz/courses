height_of_tree = 15
height_of_chunk = 5
width_of_chunk = 3
star_count = 1

for i in range(height_of_tree):
    for j in range((height_of_tree-star_count//2)):
        print(" ",end = "")
    for k in range(star_count):
        print("*",end = "")
    star_count += 2
    print("\n")
for i in range(height_of_chunk):
	for j in range(height_of_tree-2):
		print(" ",end = "")
	for k in range(width_of_chunk):
		print("*",end = "")
	print("\n")
