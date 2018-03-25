void EntenderRepresentacaoDeDouble(){
    struct data{
        union {
            unsigned __int64 ui;
            double d;
        };
    };
     data s =  data();
    s.ui=0b0100000000001000000000000000000000000000000000000000000000000000u;
         //seeeeeeeeeeemmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
         //(-1^s)*(1+f(m))^(e+1-2^10)
         // S * M ^ E
    cout << "sizeof(ui)=" << sizeof(s.ui) << " sizeof(d)=" << sizeof(s.d) << " sizeof(s)=" << sizeof(s) << endl;
    cout << "ui=" << hex<< s.ui << " d=" << s.d << endl;
}
//sizeof(ui)=8 sizeof(d)=8 sizeof(s)=8
//ui=4008000000000000 d=3
