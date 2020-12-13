using namespace std;
#include<iostream>
#include<math.h>
#include<vector>
std::vector<int> vect;

int dtmerminantBul( int matrix[4][4], int say) {
   int dtm = 0;
   int altMTX[4][4];
   if (say == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < say; x++) {
         int subi = 0;
         for (int i = 1; i < say; i++) {
            int subj = 0;
            for (int j = 0; j < say; j++) {
               if (j == x)
               continue;
               altMTX[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         dtm = dtm + (pow(-1, x) * matrix[0][x] * dtmerminantBul( altMTX, say - 1 ));
      }
   }
   return dtm;
}

int matrixTara(int matrix[5][5])
{
    int ad=0;

        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
                if(matrix[i][j]==1)
            {
                    ad=ad+1;
            }
        }
          vect.push_back(ad);
          ad=0;
        }
        return 0;
};
int matrixTara2(int par[5][5])
{       int ad=0;
        int ad2=0;
        int par2[4][4];
        for(int i=0;i<5;i++)
            {
            if(ad2<vect[i])
                ad=i;
                ad2=vect[i];
            }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                 if( (i==ad)){
                   par2[i][j]=par[i+1][j];
                   }
                else if(j==ad)
                {
                    par2[i][j]=par[i][j+1];
                }

                else
                {
                 par2[i][j]=par[i][j];
                }
            }
        }
        par2[3][3]=par[4][4];
        cout<<"Yayilim Agaci Sayisi: "<<dtmerminantBul(par2,4)<<"\n\n\n";
        return 0;
}
int matrixTara3(int matrix[5][5])
{
    int par[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i==j)
            {
                par[i][j] =vect[i];
            }
            else
            {
             int x=matrix[i][j]*-1;
             par[i][j]=x;
            }
        }
    }
    matrixTara2(par);
    return 0;
}

int main()
{
    int matrix[5][5]= {{0, 1, 1, 1, 0},{1, 0, 0, 1, 1},{1, 0, 0, 1, 0},{1, 1, 1, 0, 1},{0, 1, 0, 1, 0}};
    matrixTara(matrix);
    matrixTara3(matrix);

    return 0;
}
