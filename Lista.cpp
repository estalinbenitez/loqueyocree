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

//en esta parte verifico si el inicio es null
    if(inicio!=NULL){
        //si el inicio no es igual ah null creo el apuntador temporal
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
    //en este if si el inicio es null la lista esta vacia entonces retorno null
    if(inicio == NULL){
        
    return NULL;
    }

    // creo el apuntador animal, y en el ciclo lo igualo al temporal
        Animal* viejos;
    for(Animal* temp=inicio; temp->sig != NULL ;temp=temp->sig){
       viejos = temp;

            //en este if verifico si el edad del temp es mayor que el del vejo el viejo lo igualo al temp
        if(temp->edad > viejos->edad)
        {

        viejos = temp;
        }

    }
    return viejos;

}

Animal* Lista::getAnimalMasJoven()
{
    //verifico si la lista esta vacia y si lo esta retorno null
    if(inicio == NULL){
    return NULL;
    }

//en este for recorro la lista i ago lo mismo del animal mas viejo solo que en el if se verifica que si es menor que la edad

    Animal* ed;
    for(Animal* temp=inicio; temp->sig != NULL ;temp=temp->sig){
         ed = temp;
        if(temp->edad < ed->edad)
        {

            ed = temp;
        }

    }
    return ed;


}

Animal* Lista::buscar(string nombre){
//verifico si la lista no esta basia
    if (inicio == NULL)
        {
            return NULL;
        }

    //en este ciclo busco el nombre en la lista y si lo encuentro lo retorno
     for(Animal*temp=inicio; temp->sig != NULL ;temp=temp->sig){
        if(temp-> nombre == nombre){
            return temp;
        }

     }
     
     //si recorro la lista y no lo encuentro retorno  null
           cout<< "Animal no Existe";

            return NULL;

   }
void Lista::insertar(Animal*animalito , int pos ){

    // verifico si la posicion es igual ah cero para mover el inicio al segundo lugar
    if(pos == 0){

    Animal *temp = animalito;

        temp->sig = inicio;
        inicio = temp;
        return;
    }

     Animal*temp = inicio;

//en este siglo recorro el ciclo hasta la posicion insertada y verifico si el temp->sig es igual ah null eh ingreso
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

    //verifico que el inicio se distinto de null
  if(inicio != NULL){
      //si el nombre esta en el inicio desconecto el inicio 
            if(inicio->nombre==nom){
                inicio = inicio->sig;

            }else{
                //recorro el ciclo hasta encontrar el nombre ingresado y lo desconecto 
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

// si el inicio  es igual ah null retorno 0
    if(inicio==NULL){
        return 0 ;
    }
    // creo las variables para los acumuladores
    double suma=0;
    double acumulador=0;

    Animal *temp =inicio;
//recorro la lista y voy guardando la edad y al final de la funcion la divido entre la cantidad
    for(temp=inicio; temp->sig != NULL ;temp=temp->sig){
        suma+=temp->edad;
        acumulador++;

    }

    return (suma/acumulador);


}





