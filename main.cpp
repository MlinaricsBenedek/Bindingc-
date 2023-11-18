#include <iostream>

constexpr int N_ELEMENTS = 100;

int main()
{
    //komment
    int *b = new int[N_ELEMENTS];//hibás hivatkozas
    
    std::cout << "1-100 ertekek duplazasa";//rossz szintaktika stringnél:"", hiányzó:;
    for (int i = 0;i<N_ELEMENTS;i++)//hiányos ciklusfej
    {
        b[i] = i * 2;
    }
    for (int i = 0; i<N_ELEMENTS; i++)//hiányzó feltétel
    {
        std::cout << "\n Ertek:"<<b[i];//hianyzó paraméter
    }    
    std::cout << "Atlag szamitasa: " << std::endl;
    int atlag=0;//hiányzó értékadés
    for (int i = 0; i < N_ELEMENTS; i++)//rossz szintaktika csere ,->;
    {
        atlag += b[i];
    }
    atlag /= N_ELEMENTS;
    std::cout << "Atlag: " << atlag << std::endl;
    return 0;
}
