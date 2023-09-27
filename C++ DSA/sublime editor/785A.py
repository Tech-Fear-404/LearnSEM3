di={"Tetrahedron":4,"Cube":6,"Octahedron":8,"Dodecahedron":12,"Icosahedron":20}
n=int(input())
su=0
for i in range(n):
	q=input()
	su+=di[q]
print(su)
