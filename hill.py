# your code goes here
from numpy import matrix
import numpy

pt=input("Enter text")
key=input("Enter key n*n")

n=len(pt)

pt_vector=list()
for i in range(n):
	pt_vector.append(ord(pt[i])-65)

key_matrix=list()
for i in range(n):
	row=list()
	for j in range(n):
		row.append(ord(key[i*n+j])-65)
	key_matrix.append(row)
	
#cipher_text
cip_vector=[]
for i in range(n):
	val=0
	for j in range(n):
		val+=key_matrix[i][j]*pt_vector[j]
		val=val%26
	cip_vector.append(val)

cip_text=""
for i in cip_vector:
	cip_text+=str(chr(i+65))
print(cip_text)

mat=(matrix(key_matrix))
inv_mat=mat.I
inv_matrix=inv_mat.tolist()
text_vector=[]
for i in range(n):
	val=0
	for j in range(n):
		val+=inv_matrix[i][j]*cip_vector[j]
		val=val%26
	text_vector.append(int(val))
print(text_vector)
text=""
for i in pt_vector:
	text+=str(chr(i+65))
print(text)
