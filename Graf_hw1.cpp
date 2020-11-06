#include<iostream>
#include <list>
using namespace std;

class Graf   // Graf ad�nda bir s�n�f olu�turarak girilecek d���m de�erlerinin aralar�ndaki k�pr�ler tan�mlanacak
{            // ve alt bile�enler bulunacakt�r
    int V;

    list<int> *ekler;

    void dsfMetodu(int v, bool gezilmis[]);  // DFS algoritmas�n�n fonksiyon haline getirilerek d���mler aras� ge�i�e bakar
public:
    Graf(int V);                            // Graf�m�z�n ka� d���mden olu�tu�unu bu consructor'a belirtmemiz gerekir.
    ~Graf();
    void kopruEkle(int v, int w);           // d���mlerimiz aras� k�pr�leri tan�mlayaca��m�z fonksiyon
    void bagliOlanComponentler();           // ba�l� olan componentleri buluyor ve yazd�r�yor. (ekran ��kt�s�n� veriyor)
};

void Graf::bagliOlanComponentler()
{
    int a=1;

    bool *gezilmis = new bool[V];
    for(int v = 0; v < V; v++)
        gezilmis[v] = false;

    for (int v=0; v<V; v++)
    {

        if (gezilmis[v] == false)
        {
            cout << "\n"<< a<<"             ";
            dsfMetodu(v, gezilmis);

            a++;

        }
    }
    delete[] gezilmis;
}

void Graf::dsfMetodu(int v, bool gezilmis[])
{
int a=1;
    gezilmis[v] = true;
    cout <<v << " ";

    // Recur for all the vertices
    // ekleracent to this vertex
    list<int>::iterator i;
    for(i = ekler[v].begin(); i != ekler[v].end(); ++i)
        if(!gezilmis[*i])
            dsfMetodu(*i, gezilmis);
}

Graf::Graf(int V)
{
    this->V = V;
    ekler = new list<int>[V];
}

Graf::~Graf()
{
    delete[] ekler;
}

void Graf::kopruEkle(int v, int w)
{
    ekler[v].push_back(w);
    ekler[w].push_back(v);
}


int main() {
    Graf g(20); // Graf�m�z�n 20 d���mden olu�tu�unun dere�erini parametre olarak verdik

    // Graf�m�z�n kom�uluk ili�kilerini 20x20 boyutundaki array olarak tan�mlad�k
    //   V1 V2 V3 V4 V5 V6 V7 V8 V9 .............................V20
    int array[20][20] = {
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V1
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V2
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V3
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V4
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V5
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},     // V6
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V7
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V8
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V9
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},     // V10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},     // V11
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V12
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},     // V13
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},     // V14
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},     // V15
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0},     // V16
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},     // V17
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},     // V18
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},     // V19
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, };  // V20

int array2[48][2];
int array2satir=0;

        // Bu FOR d�ng�s� e�er "array" isimli dizimizin kom�uluk matrisini kullanarak d���mler aras� k�pr�leri tespit ediyor ve array2 adl� dizine populate ediyor.
        for(int satir=0;satir<20;satir++)
        {
            for(int sutun=0;sutun<20;sutun++)
            {
                if(array[satir][sutun]==1)
                {
                    array2[array2satir][0]=satir;
                    array2[array2satir][1]=sutun;
                    array2satir++;
                }
            }
        }

 int birinci;
 int ikinci;

        /* Bu FOR d�ng�s� array isimli dizimizin i�indeki hatal� dizileri d�zeltiyor
           �rnek verirsek 0 ve 1 d���m� aras�ndaki k�pr�y� belirtiyor, ek olarak 1 ve 0 olarak da dizinin i�iresinde bulunuyor
           bu y�zden e�er dizimizde 0 ve 1 aras� k�pr� var ise 1 ve 0 de�erini(tersi) tespit edip sat�r ve sutuna -1 de�erlerini yerle�tiriyor
        */
        for(int satir=0;satir<48;satir++)
        {
            birinci=array2[satir][0];
            ikinci=array2[satir][1];
            for(int satir2=0;satir2<48;satir2++)
            {
                if(array2[satir2][0]==ikinci)
                {
                    if(array2[satir2][1]==birinci)
                    {
                        array2[satir2][0]=-1;
                        array2[satir2][1]=-1;
                    }
                }
            }
        }
        // Bu FOF d�ng�s� array2 adl� dizimizin i�indeki d���mler aras� k�pr�leri olu�turup alt bile�enleri bulacak
        // ve ekrana print edecek fonksiyona parametre g�nderiyor
        for(int satir=0;satir<48;satir++)
        {
           if(array2[satir][0]==-1)
           {
               continue;
           }

           g.kopruEkle(array2[satir][0],array2[satir][1]);

        }
        cout << "Alt Bilesen   Dugumler \n";
        g.bagliOlanComponentler();
        cout << "\n \n \n";

    return 0;
}
