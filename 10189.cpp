#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int a,b,i,k,cnt=1,x[111][111],h[111][111],posx[]={1,1,1,-1,-1,-1,0,0},posy[]={-1,0,1,-1,0,1,-1,1};
    char t[111];
    while(scanf("%d%d",&a,&b)&&a|b){
          memset(&x,0,sizeof(x));
          memset(&h,0,sizeof(h));
          //top=0;
          //printf("%d%d",h[50][30],x[30][30]);
          for(k=1;k<=a;k++){
               scanf("%s",&t);
               
               for(i=1;i<=b;i++){
                     //arr[k][i]=t[i];
                     if(t[i-1]=='*'){h[k][i]=1;for(int j=0;j<8;j++){x[k+posx[j]][i+posy[j]]++;}}
               }
          }
          printf("Field #%d:\n",cnt++);
          for(i=1;i<=a;i++){
          for(k=1;k<=b;k++){if(h[i][k]==0)printf("%d",x[i][k]);else printf("*");}
          printf("\n");
          }
          //printf("\n");
    }
    
    return 0;    
}
