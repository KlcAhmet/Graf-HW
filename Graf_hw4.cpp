#include<iostream>
using namespace std;
#define dugumBoyutu 20




int durum =0;
int graf[dugumBoyutu][dugumBoyutu] =
{
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};



bool donguKontrol(int u, bool gezilmis[], int ust) {
   gezilmis[u] = true;    //mark v as gezilmis
   for(int v = 0; v<dugumBoyutu; v++) {
      if(graf[u][v]) {
         if(!gezilmis[v]) {     //when the adjacent dugumBoyutu v is not gezilmis
            if(donguKontrol(v, gezilmis, u)) {
               return true;
            }
         } else if(v != ust) {    //when adjacent vertex is gezilmis but not ust
            return true;    //there is a cycle
         }
      }
   }
   return false;
}

bool agackont() {
   bool *temp = new bool[dugumBoyutu];

   for(int i = 0; i<dugumBoyutu; i++)
      temp[i] = false;    //initialize as no dugumBoyutu is gezilmis

   if(donguKontrol(0, temp, -1))
    {
        durum =1;
     //durum if there is a cycle or not
      return false;
    }

   for(int i = 0; i<dugumBoyutu; i++) {
      if(!temp[i]){
        durum =2;
        return false;
      }    //if there is a dugumBoyutu, not gezilmis by traversal, graf is not connected

   }
   return true;
}

int main() {
   if(agackont())
      cout << "Verilen graf bir agactir.";
   else if(durum==1)
    {
     cout << "Verilen graf bir agac degildir. Cunku dongu barindiriyor.";
    }
   else if(durum==2)
    {
    cout << "Verilen graf bir agac degildir. CUnkU grafta bagli olmayan dugumler var.";

    }

}
