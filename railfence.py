# your code goes here
plain_text=input("Enter text")
key=int(input("Enter key value"))
rail=[]
n=len(plain_text)

for i in range(key):
	r=[]
	for j in range(n):
		r.append('#')
	rail.append(r)
dir_down=False
row,col=0,0

for i in range(n):
	if(row==0 or row==key-1):
		dir_down=not dir_down
		
	rail[row][i]=plain_text[i]
	if(dir_down):
		row=row+1
	else:
		row=row-1
print()
c=""
for i in range(key):
	for j in range(n):
		if(rail[i][j]!='#'):
			c+=str(rail[i][j])
print(c)

rail1=[]

dir_down=False
row,col=0,0

c1=""
for i in range(n):
	if(row==0 or row==key-1):
		dir_down=not dir_down
		
	c1+=str(rail[row][i])
	if(dir_down):
		row=row+1
	else:
		row=row-1

print(c1)