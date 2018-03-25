void EntenderRepresentacaoDeFloat(){
    struct data{
        union {
            unsigned __int32 ui;
            float f;
        };
    };
     data s =  data();
    s.ui=0b01000000000000000000000000000000u;
         //seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
         //(-1^s)*(1+f(m))^(e+1-2^7)
         // S * M ^ E
    cout << "sizeof(ui)=" << sizeof(s.ui) << " sizeof(f)=" << sizeof(s.f) << " sizeof(s)=" << sizeof(s) << endl;
    cout << "ui=" << hex<< s.ui << " f=" << s.f << endl;
}
//sizeof(ui)=4 sizeof(f)=4 sizeof(s)=4
//ui=40000000 f=2
