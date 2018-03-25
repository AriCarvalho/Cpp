#include <iomanip>
#include <fstream>
#include <string>

void  EscritaEmArquivo()
{
    auto c = "Escrita de chars";
    auto s = string("Escrita de strings");

    ofstream ofs("a.txt",ios::app);
    if(ofs.good())
    {
        ofs << c << endl;
        ofs << s << endl;
    }
    ofs.close();
}
//Arquivo escrito: a.txt
