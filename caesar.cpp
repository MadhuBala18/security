#include<bits/stdc++.h>
using namespace std;
string encrypt(string str,int k)
{
	string c="";
	for(int i=0;i<str.size();i++)
	{
		if(isupper(str[i]))
			c+=(((str[i]-'A')+k)%26+'A');
		else
		if(islower(str[i]))
			c+=(((str[i]-'a')+k)%26+'a');
		else
			c+=str[i]+k;
	}
	return c;
}
string decrypt(string str,int k)
{
	string c="";
	for(int i=0;i<str.size();i++)
	{
		if(isupper(str[i]))
			c+=(((str[i]-'A')-k)%26+'A');
		else
		if(islower(str[i]))
			c+=(((str[i]-'a')-k)%26+'a');
		else
			c+=str[i]-k;
	}
	return c;
}
int main()
{
	string str,cipher,text;
	int k;
	cin>>str;
	cin>>k;
	cipher=encrypt(str,k);
	text=decrypt(cipher,k);
	cout<<str<<endl<<cipher<<endl<<text<<endl;
}