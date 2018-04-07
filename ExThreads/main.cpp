#include <pthread.h>//pthread_create
#include <iostream>//cout
#include <memory>//unique_ptr
#include <unistd.h>//usleep
#include <iomanip>//setw,setfill
#include <cstdlib>//EXIT_SUCCESS
//g++ -o main.exe  -pthread main.cpp

using namespace std;

//Exemplo 1: Espera de encadeamento (thread_join)
//Estrutura para repartir o processamento
struct position{
    int* data;
    int* start;
    int* end;
    int add;
};

static void * funcA(void * data){

    position* p = (position *)data;

    int x=0;
    for(int* i = p->start; i < p->end ; i++)
    {
        //Atraso de teste
        usleep(10);
        x+=p->add;
        (*i)=x;
    }

}

void ex_thread_join(void){

    //Criar dados
    auto data = unique_ptr<int>(new int[2000]);

    auto data_ptr = data.get();
    auto p1 = unique_ptr<position>(new position);
    p1->data = data_ptr;
    p1->start = data_ptr;
    p1->end = p1->start +1000;
    p1->add = 2;
    //Criar a configuração do encadeamento
    pthread_t  mypthread1;
    //Criar o encadeamento
    pthread_create(&mypthread1,NULL,funcA,p1.get());

    auto p2 = unique_ptr<position>(new position);
    p2->data = data_ptr;
    p2->start = data_ptr  +1000;
    p2->end = p2->start +1000;
    p2->add = 3;
    pthread_t  mypthread2;
    pthread_create(&mypthread2,NULL,funcA,p2.get());

    //Local onde o retorno será colocado
    void * res;
    //Espera o encadeamento terminar e retorna um código de sucesso
    int r = pthread_join(mypthread1,&res);

    if(r!=0)
        cout << "Erro na thread1";

    r = pthread_join(mypthread2,&res);

    if(r!=0)
        cout << "Erro na thread2";

    for(int* i = data_ptr ; i < data_ptr+2000;i++)
        cout <<  setw(4) << setfill('0') << *i << ",";

}

//Exemplo 2: Cancelamento de encadeamento (pthread_cancel)
static void * funcB(void * data){

    for(int i = 0;  i < 1024 ; i++)
    {
        usleep(100);

        cout << i << ",";

        pthread_testcancel();
    }

}

void ex_thread_cancel(void){

    pthread_t  mypthread1;
    pthread_create(&mypthread1,NULL,funcB,NULL);

    pthread_detach(mypthread1);
    usleep(2000);

    pthread_cancel(mypthread1);
}

//Exemplo 3: Cancelamento de encadeamento (thread_exit)

static void * funcC(void * data){

    for(int i = 0;  i < 1024 ; i++)
    {
        usleep(10);

        cout << i << ",";

        if(i>64)
            pthread_exit(NULL);
    }

}

void ex_thread_exit(){

    pthread_t  mypthread1;
    pthread_create(&mypthread1,NULL,funcC,NULL);

    pthread_join(mypthread1,NULL);
}

int main(int argc, char * argv[]){

    cout << "BEGIN" << endl;

    //ex_thread_join();
    ex_thread_cancel();
    //ex_thread_exit();

    cout<< endl << "END" << endl;

    return EXIT_SUCCESS;
}
