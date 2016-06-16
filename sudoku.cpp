#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int count=0;
char a[9][10],b[9][10];

void reset()
{
   int i;
   for(i=0;i<9;i++)
      strcpy(a[i],b[i]);
}

void input()
{
   int i;
   for(i=0;i<9;i++)
   {
      cout<<"A"<<i+1<<": ";
      cin>>b[i];
   }
}

int isfixed(int r,int c)
{
   if(b[r][c]=='0') return 0;
   return 1;
}

void print()
{
    int i,j;
    cout<<"\n\t\t_________________________\n";
    for(i=0;i<9;i++)
    {
      cout<<"\t\t| ";
      for(j=0;j<9;j++)
      {
         if(a[i][j]!='0')
            cout<<a[i][j];
         else
            cout<<"_";
         if(j==2||j==5||j==8)
            cout<<" | ";
         else
            cout<<" ";
      }
      if(i==2||i==5)
         cout<<"\n\t\t|_______________________|";
      cout<<"\n";
    }
    cout<<"\t\t|_______________________|\n";
}

int checkrow(int r,char no)
{
   int i;
   for(i=0;i<9;i++)
      if(a[r][i]==no)
         return 0;
   return 1;
}

int checkcol(int c,char no)
{
   int i;
   for(i=0;i<9;i++)
      if(a[i][c]==no)
         return 0;
   return 1;
}

int checkbox(int row,int col,char n)
{
   int x,y;
   for(x=(row/3)*3;x<((row/3)*3+3);x++)
      for(y=(col/3)*3;y<((col/3)*3+3);y++)
         if(a[x][y]==n)
            return 0;
   return 1;
}

void back(int &x,int &y)
{
   if(y==0 && x!=0)
   {
      y=8;
      x=x-1;
   }
   else
      y--;
}

char place(int i,int j,char black='!')
{
   if(!isfixed(i,j))
      a[i][j]='0';
   count++;
   char k;
   for(k=49;k<58;k++)  //number
      if(a[i][j]=='0' && checkrow(i,k)==1 && checkcol(j,k)==1 && checkbox(i,j,k)==1 && isfixed(i,j)==0 && k>black)
         return k;
   int x=i,y=j; char c1;
   allot:
   back(x,y);
   if(!isfixed(x,y))
   {
      c1=a[x][y];
      a[x][y]=place(x,y,c1);
      return place(i,j);
   }
   else goto allot;
}

int main()
{
   int i,j;
   input();
   reset();
   print();
   cout<<"\n\n";
   for(i=0;i<9;i++)
      for(j=0;j<9;j++)
         if(!isfixed(i,j))
            a[i][j]=place(i,j);
   print();
   cout<<"\n\nThe program has run "<<count<<" times";
   return 0;
}
