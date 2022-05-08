//Registro animales

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;


class menu
{
private:
    string tipodeanimal;
    string raza;
    string edad;
    string fechaingreso;
    string codigoanimal;
    string nombre;
    string direccion;
    string notelefono;
    string fechaadopcion;

public:
    void agregaranimal();
    void darenadopcion();
    void modificar();
    void listaranimales();
    void menuPrincipal();
    void detallesanimal();
    void mostarRegistro(string codigo);
};

void pausa();
void error();

void menu::menuPrincipal()
{
    int opcion;
    do
    {
        cout<<"\t\t\t\t***Registro de animal al albergue***\t\t\t\t\n\n";
        cout<<"1. Ingresar un nuevo animal\n\n";
        cout<<"2. Mostrar detalles del animal\n\n";
        cout<<"3. Listar Animales en existencia\n\n";
        cout<<"4. Dar en adopcion\n\n";
        cout<<"5. Modificar datos del animal\n\n";
        cout<<"6. Salir\n\n";
        cout<<"Opcio: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opcion no valida!\n\n";
            break;

        case 1:
            agregaranimal();
            break;

        case 2:
            detallesanimal();
            break;

        case 3:
            listaranimales();
            break;

        case 4:
            darenadopcion();
            break;

        case 5:
            modificar();
            break;

        case 6:
            break;
        }
    }
    while(opcion!=6);
}

void menu::agregaranimal()
{
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("animales.txt",ios::in);
    escritura.open("animales.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Ingresar un nuevo animal***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el codigo del animal: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"Codigo de animal no valido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,codigoanimal);
            while(!verificador.eof())
            {
                getline(verificador,tipodeanimal);
                getline(verificador,raza);
                getline(verificador,edad);
                getline(verificador,fechaingreso);

                if(codigoanimal==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un animal con ese codigo\n\n";
                    cout<<"El animal con ese codigo es: "<<nombre<<"\n\n";
                    cout<<"Ingresa un codigo valido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\nCodigo de animal no valido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,codigoanimal);
            }

            if(verificador.eof()&&auxCodigo!=codigoanimal)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        codigoanimal=auxCodigo;
        cout<<"\t\t\t\t***Ingresar un nuevo animal***\t\t\t\t\n\n";
        cout<<"Ingresa el codigo del animal: ";
        cout<<codigoanimal;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el tipo de animal: ";
        getline(cin,tipodeanimal);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la raza del animal: ";
        getline(cin,raza);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la edad del animal: ";
        getline(cin,edad);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la fecha de inscripcion del animal:  ";
        getline(cin,fechaingreso);
        cout<<"\n\n";

        escritura<<codigoanimal<<"\n"<<tipodeanimal<<"\n"<<raza<<"\n"<<edad
                 <<"\n"<<fechaingreso<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}

void menu::darenadopcion()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("animales.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Dar en adopcion a un animal***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el codigo del animal que deseas dar en adopcion: ";
        getline(cin,auxCodigo);
        getline(lectura,codigoanimal);
        while(!lectura.eof())
        {
            getline(lectura,tipodeanimal);
            getline(lectura,raza);
            getline(lectura,edad);
            getline(lectura,fechaingreso);

            if(auxCodigo==codigoanimal)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"Codigo: "<<codigoanimal<<endl;
                cout<<"Tipo de animal: "<<tipodeanimal<<endl;
                cout<<"Raza: "<<raza<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"Fecha de ingreso: "<<fechaingreso<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas dar en adopcion al: "<<tipodeanimal<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                 ofstream escritura;
                 ifstream verificador;
                 string auxCodigo;
                 bool coincidencia=false;
                 verificador.open("adopcion.txt",ios::in);
                 escritura.open("adopcion.txt",ios::app);
                 if(escritura.is_open()&&verificador.is_open())
                 
                 cout<<"\n\n\t\t\t\t***Ingresar datos del nuevo propietario del animal***\t\t\t\t\n\n";
                 cout<<"\n\nIngresa el nombre de la persona : ";
                 getline(cin,nombre);
                 cout<<"\n\n";
                 fflush(stdin);
                 cout<<"Ingresa direccion de propietario: ";
                 getline(cin,direccion);
                 cout<<"\n\n";
                 fflush(stdin);
                 cout<<"Ingresa el numero de telefono del propietario: ";
                 getline(cin,notelefono);
                 cout<<"\n\n";
                 fflush(stdin);
                 cout<<"Ingresa la fecha de adopcion: ";
                 getline(cin,fechaadopcion);
                 cout<<"\n\n";
                 
                 escritura<<nombre<<"\n"<<direccion<<"\n"<<notelefono
                 <<"\n"<<fechaadopcion<<"\n";
                    cout<<"\n\nLa adopcion del animalse ha realizado correctamente\n\n";
                }

                else
                {

                    cout<<"\n\nAnimal conservado\n\n";
                    auxiliar<<codigoanimal<<"\n"<<tipodeanimal<<"\n"<<raza<<"\n"<<edad
                            <<"\n"<<fechaingreso<<"\n";

                }

            }
            else
            {
                auxiliar<<codigoanimal<<"\n"<<tipodeanimal<<"\n"<<raza<<"\n"<<edad
                        <<"\n"<<fechaingreso<<"\n";
            }
            getline(lectura,codigoanimal);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el codigo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("animales.txt");
    rename("auxiliar.txt","animales.txt");
    pausa();
}

void menu::detallesanimal()
{
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("animales.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***Consultar detalles de un animal***\t\t\t\t\n\n";
        cout<<"Ingresa el codigo del animal el cual deseas consultar detalles: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigoanimal);
        while(!mostrar.eof())
        {
            getline(mostrar,tipodeanimal);
            getline(mostrar,raza);
            getline(mostrar,edad);
            getline(mostrar,fechaingreso);

            if(auxCodigo==codigoanimal)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"Codigo: "<<codigoanimal<<endl;
                cout<<"Tipo de animal: "<<tipodeanimal<<endl;
                cout<<"Raza: "<<raza<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"Fecha de ingreso: "<<fechaingreso<<endl;
                cout<<"\n\n";
            }

            getline(mostrar,codigoanimal);
        }

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}

void menu::modificar()
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxtipodeanimal;
    string auxraza;
    string auxedad;
    string auxfechaingreso;
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("animales.txt",ios::in);
    verificador.open("animales.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Modificar los datos de un animal***\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el codigo del animal el cual deseas modificar: ";
        getline(cin,auxCodigo);

        if(auxCodigo=="")
        {
            do
            {
                cout<<"Codigo de animal no valido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        }

        codigoModif=auxCodigo;

        getline(lectura,codigoanimal);
        while(!lectura.eof())
        {
            getline(lectura,tipodeanimal);
            getline(lectura,raza);
            getline(lectura,edad);
            getline(lectura,fechaingreso);

            if(auxCodigo==codigoanimal)
            {
                encontrado=true;
                mostarRegistro(codigoModif);

                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el animal\n\n";
                fflush(stdin);
                cout<<"Ingresa el codigo del animal: ";
                getline(cin,auxCodigo);
                if(auxCodigo==codigoModif)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(auxCodigo==codigoModif)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,codigoanimal);
                        while(!verificador.eof())
                        {
                            getline(verificador,tipodeanimal);
                            getline(verificador,raza);
                            getline(verificador,edad);
                            getline(verificador,fechaingreso);

                            if(auxCodigo==codigoanimal)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un animal con ese codigo!\n\n";
                                cout<<"El animal con ese codigo es: "<<tipodeanimal<<"\n\n";
                                cout<<"Ingresa un codigo valido!:";
                                getline(cin,auxCodigo);

                                if(auxCodigo=="")
                                {
                                    do
                                    {
                                        cout<<"Codigo de animal no valido! ";
                                        cout<<"intentalo nuevamente: ";
                                        getline(cin,auxCodigo);
                                    }
                                    while(auxCodigo=="");
                                }
                                break;
                            }

                            getline(verificador,codigoanimal);
                        }

                        if(verificador.eof()&&auxCodigo!=codigoanimal)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***Modificar los datos de un animal***\n\n";
                cout<<"Ingresa el codigo del animal el cual deseas modificar:";
                cout<<codigoModif;
                mostarRegistro(codigoModif);
                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el animal\n\n";
                cout<<"Ingresa el codigo del animal: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el tipo de animal: ";
                getline(cin,auxtipodeanimal);;
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa la raza del animal: ";
                getline(cin,auxraza);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la edad del animal:";
                getline(cin,auxedad);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la fecha de ingreso del animal: ";
                getline(cin,auxfechaingreso);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n"<<auxtipodeanimal<<"\n"<<auxraza<<"\n"<<auxedad
                        <<"\n"<<auxfechaingreso<<"\n";
                cout<<"El registro se ha modificado correctamente.\n\n";
            }


            else
            {

                auxiliar<<codigoanimal<<"\n"<<tipodeanimal<<"\n"<<raza<<"\n"<<edad
                        <<"\n"<<fechaingreso<<"\n";
            }


            getline(lectura,codigoanimal);
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontro ningun registro con ese codigp!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("animales.txt");
    rename("auxiliar.txt","animales.txt");
    pausa();
}

void menu::listaranimales()
{
    int i=0;
    ifstream lectura;
    lectura.open("animales.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los animales en existencia***\t\t\t\t\n\n";
        getline(lectura,codigoanimal);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,tipodeanimal);
            getline(lectura,raza);
            getline(lectura,edad);
            getline(lectura,fechaingreso);
            cout<<"Codigo: "<<codigoanimal<<endl;
            cout<<"Tipo de animal: "<<tipodeanimal<<endl;
            cout<<"Raza: "<<raza<<endl;
            cout<<"Edad: "<<edad<<endl;
            cout<<"Fecha de ingreso: "<<fechaingreso<<endl;
            cout<<"\n\n";
            getline(lectura,codigoanimal);
        }

        if(i==1)
            cout<<"Hay un solo animal registrado en este albergue\n\n";

        else

            cout<<"Hay un total de "<<i<<"  animales registrados en este albergue\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);
}

int main()
{
    system ("color b0");
    menu inicio;
    inicio.menuPrincipal();
    return 0;
}

void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicacion que el programa o que el archivo de texto se llame: \n";
    cout<<"animales.txt, si el archivo tiene otro nombre renombrelo al ya mencionado\n\n";
}

void menu::mostarRegistro(string codigo)
{

    ifstream mostrar;
    mostrar.open("animales.txt",ios::in);
    getline(mostrar,codigoanimal);
    while(!mostrar.eof())
    {
        getline(mostrar,tipodeanimal);
        getline(mostrar,raza);
        getline(mostrar,edad);
        getline(mostrar,fechaingreso);

        if(codigo==codigoanimal)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"Codigo: "<<codigoanimal<<endl;
            cout<<"Tipo de animal: "<<tipodeanimal<<endl;
            cout<<"Raza: "<<raza<<endl;
            cout<<"Edad: "<<edad<<endl;
            cout<<"Fecha de ingreso: "<<fechaingreso<<endl;
            cout<<"\n\n";
        }

        getline(mostrar,codigoanimal);
    }

    mostrar.close();
}
