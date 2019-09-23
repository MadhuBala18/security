#include<bits/stdc++.h>
using namespace std;
class playfair{
	public:
	char n[5][5];
	string msg;
	char getChar(int i,int j)
	{
		return n[(i+5)%5][(j+5)%5];
	}
	bool getPos(char c,int &p,int &q)
	{
		int i,j;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(c==n[i][j])
				{
					p=i;
					q=j;
					return true;
				}
			}
		}
		return false;
	}
	void play(string str,string key,bool e,bool i)
	{
		createEncoder(key,i);
		getText(str,e,i);
		if(e)
			playutil(1);
		else
			playutil(-1);
		
	}
	void playutil(int dir)
	{
		string cip="";
		for(string::const_iterator it=msg.begin();it!=msg.end();it++)
		{
			int i,j,k,l;
			if(getPos(*it++,i,j))
			{
				if(getPos(*it,k,l))
				{
					if(i==k)
					{
						cip+=getChar(i,j+dir);
						cip+=getChar(k,l+dir);
					}
					else
					if(j==l)
					{
						cip+=getChar(i+dir,j);
						cip+=getChar(k+dir,l);
						
					}
					else
					{
						cip+=getChar(i,l);
						cip+=getChar(k,j);
					}
				}
			}
		}
		cout<<cip<<endl;
	}
	void getText(string str,bool e,bool i)
	{
		msg="";
		string nmsg="";
		for(string::iterator it=str.begin();it!=str.end();it++)
		{
			*it=toupper(*it);
			if(*it<65 || *it>90)
				continue;
			if(*it=='J' && i)
			msg+='I';
			if( *it=='Q' && !i)
				continue;
			msg+=*it;
		}
		if(e)
		{
			nmsg="";
			for(int i=0;i<msg.size();i+=2)
			{
				nmsg+=msg[i];
				if(i+1<msg.size())
				{
					if(msg[i+1]==msg[i])
						nmsg+="X";
					nmsg+=msg[i+1];
				}
			}
			if(nmsg.size()&1)
				nmsg+="X";
			msg=nmsg;
		}
		cout<<msg<<endl;
	}
	void createEncoder(string key,bool i)
	{
		string s="";
		key+="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//	cout<<endl<<key<<endl;
		for(string::iterator it=key.begin();it!=key.end();it++)
		{
			*it=toupper(*it);
			if(*it<65 || *it>90)
				continue;
			if(*it=='J' && i || *it=='Q' && !i)
				continue;
			if(s.find(*it)==-1)
			s+=*it;
		}
		cout<<s<<endl;
		copy(s.begin(),s.end(),&n[0][0]);
		for(int i=0;i<5;i++)
		{	for(int j=0;j<5;j++)
				cout<<n[i][j]<<" ";
			cout<<endl;
		}
				
	}
};
int main()
{
	bool i,e;
	string str,key;
	cout<<"Enter 1 for encrypt";
	cin>>e;
	cout<<"Enter 1 for I==J";
	cin>>i;
	cout<<"Enter text:";
	cin>>str;
	cout<<"Enter key";
	cin>>key;
	playfair pf;
	pf.play(str,key,e,i);
	return 0;
}