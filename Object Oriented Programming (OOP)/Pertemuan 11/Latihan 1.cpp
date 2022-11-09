#include <iostream>
using namespace std;

class Mahasiswa
{
    private:
        string namaMahasiswa;

    public:
        void setNama(string n)
        {
            namaMahasiswa = n;
        }
        void getNama()
        {
            cout << "Nama Mahasiswa: " << namaMahasiswa << "\n";
        }

};

int main()
{
    
    Mahasiswa mhs1;
    mhs1.setNama ("Abdul Zaki Syahrul Rahmat");
    mhs1.getNama();
    
    return 0;
    
}