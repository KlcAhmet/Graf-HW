#include<iostream>
#include<stdio.h>
#include <vector>
using namespace std;
#define INFINITY 9999
#define grafBoyutu 20

void dijkstraFonksiyonu(int G[grafBoyutu][grafBoyutu],int n,int baslangicDugumu) {

   int maliyet[grafBoyutu][grafBoyutu],mesafe[grafBoyutu],gezi[grafBoyutu];
   int gezilmis[grafBoyutu],count,minMesafe,siradakiDugum,i,j;


   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)
      maliyet[i][j]=INFINITY;
   else
      maliyet[i][j]=G[i][j];
   for(i=0;i<n;i++) {
      mesafe[i]=maliyet[baslangicDugumu][i];
      gezi[i]=baslangicDugumu;
      gezilmis[i]=0;
   }

   mesafe[baslangicDugumu]=0;
   gezilmis[baslangicDugumu]=1;
   count=1;


   while(count<n-1) {
      minMesafe=INFINITY;
      for(i=0;i<n;i++)
         if(mesafe[i]<minMesafe&&!gezilmis[i]) {
         minMesafe=mesafe[i];
         siradakiDugum=i;
      }


      gezilmis[siradakiDugum]=1;


      for(i=0;i<n;i++)
         if(!gezilmis[i])
      if(minMesafe+maliyet[siradakiDugum][i]<mesafe[i]) {
         mesafe[i]=minMesafe+maliyet[siradakiDugum][i];
         gezi[i]=siradakiDugum;
      }


      count++;
   }


   for(i=0;i<n;i++)
   if(i!=baslangicDugumu) {

   //Yol
      cout<<baslangicDugumu<<"-"<<i<<"\t"<<"\t";


   //Yön
      j=i;

      std::vector< int > vecArr;
      do {

         j=gezi[j];
         vecArr.push_back(j);


      }
      while(j!=baslangicDugumu);

      for(int i=vecArr.size()-1;i>=0;i--){
        cout<<vecArr[i]<<"-";
      }
      cout<<i<<"\t"<<"\t";
      cout<<mesafe[i]<<"\n";
   }
}



int main() {

	// Graf
    int G[20][20] = {
        {0, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {4, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 6, 0, 0, 10, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 6, 8, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 12, 0, 5, 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1, 11, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 8, 0, 0, 0, 11, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 19, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 8, 0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 6, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 5, 0, 8},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0}};


   int n=20;

   for (int i=0;i<20;i++){
    cout<<"Kaynak-Hedef\t"<<"Rota\t\t\t\t\t"<<"Mesafe"<<"\n";
    dijkstraFonksiyonu(G,n,i);

   }
   return 0;
}

