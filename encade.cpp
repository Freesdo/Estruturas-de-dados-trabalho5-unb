#include <iostream>
#define N 40
using namespace std;

/* ENUNCIADO: 

Implemente um algoritmo em C++ que contenha uma Pilha Dinâmica e uma Fila Dinâmica.
Nas quais cada elemento representa um produto que possui dois campos, um inteiro para o código (chave) e um float para o preço.
No inicio o programa deve apresentar o seguinte menu de opções:
0 para sair.
1 Para gerenciar a Pilha.
2 Para gerenciar a Fila
Se o usuário escolher 1 ou 2 será apresentado um segundo menu:
cout<<"digite: \n";

        cout<<" 0 para voltar para o menu anterior \n";

        cout<<" 1 para inserir um elemento \n";

        cout<<" 2 para remover um elemento \n";

        cout<<" 3 para ver todos os elementos \n";

        cout<<" 4 para ver o tamanho da estrutura\n";

        cout<<" 5 para buscar por um elemento \n";

  

Se no segundo menu o usuário escolher a opção 2 (remover um elemento) deverá ser apresentado um terceiro menu com as seguintes opções: 

0 Para voltar para o menu anterior.

1 Para remover permanentemente. 

2 Para colocar o elemento em outra estrutura.

Se nesse terceiro menu o usuário escolher a opção 2, será exibido um quarto menu com as opções:

0 para voltar para o menu anterior. 

1 para colocar o elemento removido no topo da pilha.

2 para colocar o elemento removido no inicio da fila.

Observação: Um elemento só poderá estar em uma única estrutura, por exemplo,
um produto com chave 10 não poderá ser inserido na pilha se ele já está na fila. Então, antes de inserir um elemento 
deverá ser feito uma busca na pilha e na fila. 

*/

//obs: nao vou explicar como funciona o código. Tô com preguiça

struct registro{
	int chave;
	float preco;
};

class pilha{
	private:
		registro* p;
		int tamanho;
	public:
	pilha();
	void getreg();
	int getamanho();
	bool cheia();
	bool vazia();
	int remover();
	bool busca(int a);
	bool inserirelem(registro r);
	void removertudo();
    void passar_para_a_fila(registro* pt);
};


class fila{
	private:
	 registro* cm;
	 int inicio;
	 int fim;
	public:
		fila();
		void inserir(registro r);
		bool cheia();
		bool vazia();
		bool remover(int chave);
		void mostrar();
		bool busca(int chave,int* ptr);
		int tamanho();
        void passar_para_a_pilha(pilha* p1);
};

main(){
    fila f;
    pilha p;
    registro r1;
    int esc,x,esc_second,esc_remover,esc_terceiro,busf;
    bool a,b;
    while(true){
    cout<<"--BEM VINDO AO GERENCIADOR--\n\ndigite:\n0 para sair\n1 para gerenciar a pilha\n2 para gerenciar a fila\n\nescolha: ";
    cin>>esc;
    switch(esc){
        default:
         cout<<"\nescolha uma opcao valida.\n\n";
         break;
        case 0:
         return 0;
         break;
        case 1:
    do{
         cout<<"\n--GERENCIANDO A PILHA--\n\ndigite:\n";

        cout<<"0 para voltar para o menu anterior \n";

        cout<<"1 para inserir um elemento \n";

        cout<<"2 para remover um elemento \n";

        cout<<"3 para ver todos os elementos \n";

        cout<<"4 para ver o tamanho da estrutura\n";

        cout<<"5 para buscar por um elemento \n";
        cout<<"escolha: ";
        cin>>esc_second;
        
        switch(esc_second){
            case 0:
             break;
            default:
             cout<<"insira uma opcao valida.\n";
             break;
            case 1:
             a=true;
             cout<<"\ninsira a chave: ";
             cin>>r1.chave;
             while(p.busca(r1.chave)==true||f.busca(r1.chave,&x)==true){
                cout<<"Esta chave ja consta em uma das estruturas. tente novamente com outra chave.\n\nchave: ";
                cin>>r1.chave;
             }
             cout<<"insira o preco: ";
             cin>>r1.preco;
             a=p.inserirelem(r1);
             if(a==true)
              cout<<"\n--ELEMENTO INSERIDO COM SUCESSO--\n\n";
             else
              cout<<"\n--ELEMENTO NAO FOI INSERIDO--\n\n";
            break;
            case 2:
           
             cout<<"--REMOCAO--\ndigite:\n";
             cout<<"0 Para voltar para o menu anterior\n1 Para remover permanentemente\n2 Para colocar o elemento em outra estrutura\nescolha: ";
             cin>>esc_remover;
             switch(esc_remover){
                case 0:
                 break;
                case 1:
            x=p.remover();
        	if(x!=-1)
        	cout<<"--ELEMENTO DE CHAVE "<<x<<" FOI REMOVIDO--\n\n";
        	break;                                                 
                break;
                case 2:
                    cout<<"digite:\n0 para voltar para o menu anterior\n1 para colocar o elemento removido no inicio da fila\nescolha: ";
                    cin>>esc_terceiro;
                    switch(esc_terceiro){
                        default:
                    while(esc_terceiro!=1||esc_terceiro!=0){
                        cout<<"\nescolha invalida. tente novamente.\n";
                        cin>>esc_terceiro;
                    }
                        case 0:
                        break;
                        case 1:
                        p.passar_para_a_fila(&r1);
                        f.inserir(r1);
                        break;
                    }
        }
                break;
                case 3:
                p.getreg();
                break;
                case 4:
                cout<<"\n--O TAMANHO DA ESTRUTURA E "<<p.getamanho()<<"--\n\n";
                break;
                case 5:
                cout<<"\ninsira a chave que deseja procurar: ";
                cin>>x;
                a=p.busca(x);
                if(a==true)
                 cout<<"\n--BUSCA REALIZADA COM SUCESSO--\n\n";
                else
                 cout<<"\n--BUSCA NAO FOI REALIZADA, CHAVE NAO ENCONTRADA--\n\n";
                break;
        }
        }while(esc_second!=0);
        break;
        
        case 2:
        do{
            cout<<"--GERENCIANDO A FILA--\n\ndigite:\n";
        cout<<"0 para voltar para o menu anterior \n";
        cout<<"1 para inserir um elemento \n";
        cout<<"2 para remover um elemento \n";
        cout<<"3 para ver todos os elementos \n";
        cout<<"4 para ver o tamanho da estrutura\n";
        cout<<"5 para buscar por um elemento \n";
        cout<<"escolha: ";
        cin>>esc_second;
        switch(esc_second){
            case 0:
                 break;
            default:
             cout<<"escolha invalida. tente novamente\n\n";
                 break;
            case 1: 
             a=true;
             cout<<"\ninsira a chave: ";
             cin>>r1.chave;
             while(p.busca(r1.chave)==true||f.busca(r1.chave,&x)==true){
                cout<<"Esta chave ja consta em uma das estruturas. tente novamente com outra chave.\n\nchave: ";
                cin>>r1.chave;
             }
             cout<<"insira o preco: ";
             cin>>r1.preco;
             f.inserir(r1);
                 break;
            case 2:
           cout<<"--REMOCAO--\ndigite:\n";
             cout<<"0 Para voltar para o menu anterior\n1 Para remover permanentemente\n2 Para colocar o elemento em outra estrutura\nescolha: ";
             cin>>esc_remover;
             switch(esc_remover){
                case 0:
                 break;
                case 1:
                f.remover(x);                                                 
                break;
                case 2:
                    cout<<"digite:\n0 para voltar para o menu anterior\n1 para colocar o elemento removido no topo da pilha\nescolha: ";
                    cin>>esc_terceiro;
                    switch(esc_terceiro){
                        default:
                    while(esc_terceiro!=1||esc_terceiro!=0){
                        cout<<"\nescolha invalida. tente novamente.\n";
                        cin>>esc_terceiro;
                    }
                        break;
                        case 0:
                        break;
                        case 1:
                        f.passar_para_a_pilha(&p);   //boltar aqui
                        break;
                    }
             }
                break;
                case 3:
                f.mostrar();
                break;
                case 4:
                cout<<"--TAMANHO DA FILA: "<<f.tamanho()<<"--\n\n";
                break;
                case 5:
                cout<<"\ninsira a chave que deseja buscar\nchave: ";
                cin>>x;
                a=f.busca(x,&busf);
				if(a==true)
				  cout<<"--PRODUTO DE CHAVE "<<x<<"FOI ACHADO NA POSICAO "<<busf<<"\n\n";
				else
				  cout<<"--CHAVE NAO ENCONTRADA--\n\n";
				break;
        }

        }while(esc_second!=0);
        break;
        }

    }
    return 0;
}



pilha::pilha(){
	p=new registro[N];
	tamanho=0;
}

bool pilha::inserirelem(registro r){
	bool a;
	a=cheia();
	if(a==true)
	 return false;
	else{
		for(int i=0;i<tamanho;i++){
			if(r.chave==p[i].chave){
				cout<<"\n--CHAVE JA INSERIDA, INSIRA UMA OUTRA--\n";
				return false;
			}
		}
	p[tamanho]=r;
	tamanho++;
	return true;
}


}

bool pilha::vazia(){
	if(tamanho<=0)
	 return true;
	else if(tamanho>0)
	return false;
    return false;
}
bool pilha::cheia(){
	if(tamanho>=N)
	 return true;
	else if (tamanho<=N)
	 return false;
     return false;
}

int pilha::remover(){
	bool a;
	a=vazia();
	if(a==true){
	
		cout<<"--A PILHA ESTA VAZIA, NAO FOI POSSIVEL REMOVER--\n\n";
		return -1;
	}
	else{
		tamanho--;
		return p[tamanho].chave;
	}
}

void pilha::getreg(){
	for (int i=0;i<tamanho;i++){
		cout<<"--REGISTRO "<<i+1<<" DA PILHA--\n\n";
		cout<<"Chave: "<<p[i].chave<<'\n';
		cout<<"preco: "<<p[i].preco<<'\n'<<'\n';
	}
}

int pilha::getamanho(){
	return tamanho;
}

bool pilha::busca(int a){
	for(int i=0;i<tamanho;i++){
		if(a==p[i].chave){
		 cout<<"--CHAVE ENCONTRADA NA POSICAO "<<i<<"--\n";
		 cout<<"--PRECO DO PRODUTO: "<<p[i].preco<<"--\n\n";
		 return true;
	}
	}
return false;
}

void pilha::removertudo(){
	delete [] p;
	tamanho=0;
}

fila::fila(){
	this->inicio=0;
	this->fim=0;
	this->cm=new registro[N];
}

bool fila::vazia(){
	if(inicio==fim)
	 return true;
	else
	 return false;
}

bool fila::cheia(){
	if(fim-inicio==N)
	 return true;
	else
	 return false;
}

void fila::inserir(registro r){
	bool a;
	int x;
	a=cheia();
	if(a==true){
		cout<<"--LISTA CHEIA, REMOVA ALGUM ELEMENTO E DEPOIS TENTE NOVAMENTE--\n\n";
	}
	else{
		if(busca(r.chave,&x)==true)
			cout<<"--CHAVE JA INSERIDA, ESCOLHA ALGUMA OUTRA CHAVE DIFERENTE E TENTE NOVAMENTE--\n\n";
		else{
			int pos;
			pos=fim%N;
			cm[pos]=r;
			fim+=1;
		}
	}
}

bool fila::remover(int chave){
	bool x;
    chave=inicio;
	x=vazia();
	if(x==true){
		cout<<"--A FILA ESTA VAZIA, INSIRA ALGUM ELEMENTO E TENTE NOVAMENTE--\n\n";
		return false;
	}
	else{
		inicio+=1;
		cout<<"--ELEMENTO DE CHAVE "<<chave<<" FOI REMOVIDO--\n\n";
		return true;
	}	
}

bool fila::busca(int chave,int* ptr){
	*ptr=inicio;
	for(*ptr;*ptr<fim;*ptr++){
		if(cm[*ptr%N].chave==chave)
		 return true;
	}
	return false;
}

void fila::mostrar(){
	for(int i=inicio;i<fim;i++){
		cout<<"--PRODUTO "<<i+1<<"--\n\nchave: "<<cm[i%N].chave<<"\npreco: "<<cm[i%N].preco<<"\n\n\n";
	}
}

int fila::tamanho(){
	return (fim-inicio);
}

void pilha::passar_para_a_fila(registro* pt){
    bool a;
    *pt=p[tamanho-1];
	a=vazia();
	if(a==true){
	
		cout<<"--A PILHA ESTA VAZIA, NAO FOI POSSIVEL REMOVER--\n\n";
	}
	else{
		tamanho--;
	}

}

void fila::passar_para_a_pilha(pilha* p1){
    bool x;
    registro err=cm[inicio];
	x=vazia();
	if(x==true){
		cout<<"--A FILA ESTA VAZIA, INSIRA ALGUM ELEMENTO E TENTE NOVAMENTE--\n\n";
	}
	else{
		inicio+=1;
		p1->inserirelem(err);
	}	
}
