#include<bits/stdc++.h>
using namespace std;
// int t[200][200];

//memporization 


// int knapSack(int *val,int *wt,int w,int n){
//  if(n==-1||w==0)
//    return 0;
//  if(t[w][n]!=-1)
//     return t[w][n];
//  if(wt[n]>w)
//    return t[w][n] = knapSack(val,wt,w,n-1);
//  return t[w][n] = max((val[n] + knapSack(val,wt,w-wt[n],n-1)),knapSack(val,wt,w,n-1));
// }
// int main(int argc, char const *argv[])
// {
//  int n,w;
//  cin>>n>>w;
//  int val[n],wt[n];
//  for(int i=0;i<n;i++)
//      cin>>val[i];
//  for(int i=0;i<n;i++)
//      cin>>wt[i];
//  for(int i=0;i<200;i++){
//   for(int j=0;j<200;j++)
//         t[i][j] = -1;
//  }
//   cout<<knapSack(val,wt,w,n-1);
//  return 0;
// }

//top_down Approach
int main(int argc, char const *argv[])
{
 int n,w;
 cin>>n>>w;
 int val[n],wt[n];
 for(int i=0;i<n;i++)
     cin>>val[i];
 for(int i=0;i<n;i++)
     cin>>wt[i];
 int t[n+1][w+1];
  for(int i=0;i<n+1;i++){
  for(int j=0;j<w+1;j++)
   {
    if(i==0||j==0)
      t[i][j]=0;
   }
 }
  for(int i=1;i<n+1;i++){
  for(int j=1;j<w+1;j++){
   if(wt[i-1]<=j){
    t[i][j] = max((val[i-1] + t[i-1][j-wt[i-1]]),t[i-1][j]);
   }
   else
     t[i][j] = t[i-1][j];
  }
 }
cout<<t[n][w];
 return 0;
}
