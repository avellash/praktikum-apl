//praktikum2

#include <iostream>
using namespace std;

int main (int argc, char const *argv[])
{
    int number [] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // nampilin
    for(int i : number)
    {
        cout << "Nilai array : " << i << endl;
    }

    // hapus
    for (int i = 1; i < 3; i++)
    {
        number[i] = number[i + 1];
    }

    //total size array = tipedata * jumlah
    //jumlah = array / tipedata

   //number[2] = 10;

    int totalByte = sizeof(number);
    int singleByte = sizeof(number[0]);
    int panjangArray = sizeof(number) / sizeof(number[0]);
    // int panjangArray2 = size(number);

   //for (int i : number)
   //{
   //cout << "Nilai array : " << i << endl;
   //}

  // for (int i = 0; i < panjangArray; i++)
  // {
  //  cout << "Nilai array : " << number[i]
  // }

    //cout
        << totalByte << "\n"
        << singleByte << "\n"
        << panjangArray2; 

    //cout << "Versi c++ saya : " << _cplusplus
    return 0;

}

