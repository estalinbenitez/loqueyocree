#include "Lista.h"

Lista::Lista()
{
    inicio=NULL;

}

Lista::~Lista()
{
    //dtor
}


//Funcion que agrega ah la lista

void Lista::agregar(Animal* animalito){

    if(inicio!=NULL){
            Animal*temp=inicio;
            while(temp->sig!=NULL){
                temp=temp->sig;
            }
                temp->sig=animalito;
        }else{
            inicio=animalito;
        }


}
//Funcion Imprimir
void Lista::imprimir(){

    Animal*tmp=inicio;
    while(tmp!=NULL){
        cout<<tmp->tipo<<" "<<tmp->edad<<" "<<tmp->nombre<<" "<<endl;
        tmp=tmp->sig;
    }
}

void Lista::escribir(){

    write.open("Listas.txt");

    cout<<"Escribiendo Datos en Archivo"<<endl;
    Animal*tmp=inicio;
     while(tmp!=NULL){
    write<<tmp->tipo<<" "<<tmp->edad<<" "<<tmp->nombre<<" "<<endl;

        tmp=tmp->sig;
    }

    write.close();
}

void Lista::leer(){
    read.open("Listas.txt");

    cout<<"Leyendo Lista Del Archivo"<<endl;
    string str;
    string edad;
    string nombre;

    read.seekg(0);

    while(read>>str>>edad>>nombre){

        int e=atoi(edad.c_str());


        if(str=="Perro")
            agregar(new Perro(e,nombre));
        if(str=="Canario")
            agregar(new Canario(e,nombre));
        if(str=="Lora")
            agregar(new Lora(e,nombre));


    }
    read.close();
}

Animal* Lista::getAnimalMasViejo()
{
    if(inicio == NULL){
    return NULL;
    }

    Animal* viejos;
    for(Animal* temp=inicio; temp->sig != NULL ;temp=temp->sig){
       viejos = temp;

        if(temp->edad>viejos->edad)
        {

        viejos = temp;
        }

    }
    return viejos;

}

Animal* Lista::getAnimalMasJoven()
{
    if(inicio == NULL){
    return NULL;
    }

    Animal* ed;
    for(Animal* temp=inicio; temp->sig != NULL ;temp=temp->sig){
         ed = temp;
        if(temp->edad<ed->edad)
        {

            ed = temp;
        }

    }
    return ed;


}

Animal* Lista::buscar(string nombre){

    if (inicio == NULL)
        {
            return NULL;
        }


     for(Animal*temp=inicio; temp->sig != NULL ;temp=temp->sig){
        if(temp-> nombre == nombre){
            return temp;
        }

     }
           cout<< "Animal no Existe";

            return NULL;

   }
void Lista::insertar(Animal*animalito , int pos ){

    if(pos == 0){

    Animal *temp = animalito;

        temp->sig = inicio;
        inicio = temp;
        return;
    }

     Animal*temp = inicio;

        for(int i= 1; i < pos; i++){

            if(temp->sig == NULL){
            temp->sig = animalito;
            break;
                }
            temp = temp->sig;
        }

        animalito->sig = temp->sig;
        temp->sig = animalito;


}


void Lista::Borrar(string nom){

  if(inicio != NULL){
            if(inicio->nombre==nom){
                inicio = inicio->sig;

            }else{
                Animal* temp= inicio;
                for(temp=inicio; temp->sig != NULL ;temp=temp->sig){
                    if(temp->sig->nombre==nom){
                        temp->sig = temp->sig->sig;
                    }

                }
            }
        }
}

double Lista::promedio(){

    if(inicio==NULL){
        return 0 ;
    }
    double suma=0;
    double acumulador=0;

    Animal *temp =inicio;

    for(temp=inicio; temp->sig != NULL ;temp=temp->sig){
        suma+=temp->edad;
        acumulador++;

    }

    return (suma/acumulador);


}





