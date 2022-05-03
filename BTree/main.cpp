#include <iostream>
#include <random>
#include <chrono>
#include "btree.h"
#include "contact.h"
#include <vector>

using namespace std;

void insertContact();
void searchNode();
void showLowest();
void showHighest();
void getPre();
void getPost();
void modify();
void deleteNode();
void inOrder();
void preOrder();
void postOrder();


BTree<Contact> myTree;
int id;

std::vector< string > arr_names;
int i;

int main() {
    int opc;
    Contact contacto;

    do {
        system("cls");
        cout<<"1) Insertar Datos \n"
            <<"2) Buscar Nodo \n"
            <<"3) Mostrar Mínimo ID (Nodo)\n"
            <<"4) Mostrar Máximo ID (Nodo)\n"
            <<"5) Mostrar Nodo Antecesor\n"
            <<"6) Mostrar Nodo Sucesor\n"
            <<"7) Editar Nodo (por ID)\n"
            <<"8) Eliminar Nodo(Por ID)\n"
            <<"9) Mostrar Datos en InOrder\n"
            <<"10) Mostrar Datos en PreOrder\n"
            <<"11) Mostrar Datos en PostOrder\n"
            <<"12) Salir\n"
            <<"Selecciona una opcion: ";
        cin>>opc;

        switch(opc) {
            case 1:
                insertContact();
                break;
            case 2:
                searchNode();
                break;
            case 3:
                showLowest();
                break;
            case 4:
                showHighest();
                break;
            case 5:
                getPre();
                break;
            case 6:
                getPost();
                break;
            case 7:
                modify();
                break;
            case 8:
                deleteNode();
                break;
            case 9:
                inOrder();
                break;
            case 10:
                preOrder();
                break;
            case 11:
                postOrder();
                break;

            }
        system("pause");
        }
    while(opc!=12);

    return 0;

    }

void insertContact() {
    Contact contacto;
    int id;
    string name,address,email;

    cout<<"Ingresa el id del contacto: "<<endl;
    cin>>id;
    contacto.setId(id);
    cout<<"Ingrese el nombre del contacto: "<<endl;
    cin.sync();
    getline(cin,name);
    contacto.setName(name);
    cout<<"Ingresa la direccion del contacto: "<<endl;
    getline(cin,address);
    contacto.setAddress(address);
    cout<<"Ingresa el email del contacto: "<<endl;
    getline(cin,email);
    contacto.setEmail(email);

    arr_names.push_back(name);
    i++;

    myTree.insertData(contacto);
    }

void searchNode() {
    int opc2;
    Contact contacto;
    string name;
    cout<<"1) Por Id\n"
        <<"2) Por Nombre\n"
        <<"Selecciona una opcion: ";
    cin>>opc2;
    if(opc2 == 1) {
        cout<<"Ingresa el id :";
        cin>>id;

        if(myTree.isEmpty())
            cout<<"El arbol vacio"<<endl;
        else {

            if(myTree.getPredecessorNode(id) == nullptr)
                cout<<"No tiene padre"<<endl;
            else
                cout<<"predesecor: " <<myTree.retrieve(myTree.getPredecessorNode(id))<<endl;

            if(myTree.searchById(id)==nullptr)
                cout<<"El elemento no se encuentra en el arbol"<<endl;
            else
                cout<<"El id "<<id<< "si se encuentra en el arbol"<<endl;

            if(myTree.getSuccessorNode(id) == nullptr)
                cout<<"El elemento no tiene sucesor"<<endl;
            else
                cout<<"sucesor: "<<myTree.retrieve(myTree.getSuccessorNode(id))<<endl;
            }
        }
    else if(opc2 == 2) {
        cout<<"Ingresa el nombre :";
                cin>>name ;

                if(myTree.isEmpty())
                    cout<<"El arbol vacio"<<endl;
                else {
                   /* if(myTree.searchByName(name)==nullptr)
                        cout<<"El elemento no se encuentra en el arbol"<<endl;
                    else
                        cout<<"El nombre "<<name<< "si se encuentra en el arbol"<<endl;*/
                    for(int j=0;j<i;j++){
                        if(arr_names[j]==name)
                            cout<<"El elemento si se encuentra en la lista"<<endl;
                        else if(j+1==i){
                             if(arr_names[j]!=name)
                                cout<<"El elemento no se encuentra en la lista"<<endl;
                        }
                    }



                    }
    }
}

void showLowest() {
    if(myTree.isEmpty())
        cout<<"El arbol vacio"<<endl;
    else {
        cout<<"Elemento menor: "<<myTree.retrieve(myTree.getLowest())<<endl;
        cout<<endl;
        }
    }

void showHighest() {
    if(myTree.isEmpty())
        cout<<"El arbol vacio"<<endl;
    else {
        cout<<"Elemento mayor: "<<myTree.retrieve(myTree.getHighest())<<endl;
        cout<<endl;
        }
    }

void getPre() {
    if(myTree.isEmpty())
        cout<<"El arbol vacio"<<endl;
    else {
        cout<<"Ingresa el id para saber su nodo antecesor: ";
        cin>>id;
        if(myTree.getPredecessorNode(id) == nullptr)
            cout<<"No tiene padre"<<endl;
        else
            cout<<"antecesor: " <<myTree.retrieve(myTree.getPredecessorNode(id))<<endl;
        }
    }

void getPost() {
    if(myTree.isEmpty())
        cout<<"El arbol vacio"<<endl;
    else {
        cout<<"Ingresa el id para saber su nodo sucesor: ";
        cin>>id;

        if(myTree.getSuccessorNode(id) == nullptr)
            cout<<"El elemento no tiene sucesor"<<endl;
        else
            cout<<"sucesor: "<<myTree.retrieve(myTree.getSuccessorNode(id))<<endl;
        }
    }

void modify() {
    Contact contacto;
    int id;

    string name,address,email,vecN;

    myTree.retrieve(myTree.searchById(id)).getName();

    cout<<"Ingresa el id del contacto: "<<endl;
    cin>>id;
    contacto.setId(id);
    cout<<"Ingrese el nombre del contacto: "<<endl;
    cin.sync();
    getline(cin,name);
    contacto.setName(name);
    cout<<"Ingresa la direccion del contacto: "<<endl;
    getline(cin,address);
    contacto.setAddress(address);
    cout<<"Ingresa el email del contacto: "<<endl;
    getline(cin,email);
    contacto.setEmail(email);


    myTree.modify(id,contacto);
    }

void deleteNode() {
    Contact contacto;
    if(myTree.isEmpty())
        cout<<"El arbol vacio"<<endl;
    else {
        cout<<"Ingresa el id del elemento a eliminar: ";
        cin>>id;
        contacto =myTree.retrieve(myTree.searchById(id));
        myTree.deleteData(contacto) ;
        }
    }

void inOrder() {
    if(myTree.isEmpty())
        cout<<"El arbol vacio"<<endl;
    else {
        cout<<endl;
        cout<<"Recorrido inOrder: "<<endl;
        myTree.parseInOrder();
        cout<<endl;
        }
    }

void preOrder() {
    if(myTree.isEmpty())
        cout<<"El arbol vacio"<<endl;
    else {
        cout<<endl;
        cout<<"Recorrido preOrder: "<<endl;
        myTree.parsePreOrder();
        cout<<endl;
        }
    }

void postOrder() {
    if(myTree.isEmpty())
        cout<<"El arbol vacio"<<endl;
    else {
        cout<<endl;
        cout<<"Recorrido postOrder: "<<endl;
        myTree.parsePostOrder();
        cout<<endl;
        }
    }
