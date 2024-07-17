#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<ctime>
#include<string>
#include<sstream>

using namespace std;
 //Permite utilizar tildes en la consola de C++

/******************************/
/* Procedimiento para tener el año actual */
int obtenerAnnioActual(){
	
	int annio;
	stringstream auxiliar; //acá se guardará el año para luego convertirlo en int
	
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	
	stringstream ss_year;
    ss_year << timePtr->tm_year+1900;
    string Year = ss_year.str();
    
    auxiliar << Year; //Se guarda el año en el auxiliar
    
    auxiliar >> annio; //se convierte a int para luego ser restado por el año de nacimiento del estudiante
    
   return annio;
    
}

/***********************************************************************************************/
//Variables Globales
int cedEstudiante=0, annioNacimiento=0;
float promedios[4], notaExamenAdmision=0;
string estadoAdmision;
char nomEstudiante[100];

//variables para las estadísticas
int cantAdmitidos=0, cantEnEspera=0, cantNoAdmitidos=0;
float acumuladoAdmitidos = 0.0, acumuladoEnEspera = 0.0, acumuladoNoAdmitidos = 0.0;
float promAdmitidos=0.0, promEnEspera=0.0, promNoAdmitidos=0.0; 


/***********************************************************************************************/
//atributo para color de letra
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);

/***********************************************************************************************/
//prototipos de funciones y procedimientos
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2); 
void ingresar_datos(); //permite ingresar por el usuario los datos solicitados
int calculoEdad(); //calcula la edad según el año actual y el año de nacimiento
float promedioColegio(); //calcula el promedio de las calificaciones del colegio
float porcentajeCriterioColegio(); //Calcula el porcentaje de criterio del 40% con base al promedio del colegio
float porcentajeCriterioExamenAdmision(); //calcula el porcentaje de criterio de 60% con base al examen de admisión
float promedioAdmision(); // califica el promedio total de admisión
string estadoCalificacion(); //verifica si es aprobado o no
void hacer_graficos(int a,int y);
void graficos();
void estadisticas();
void menu();

/***********************************************************************************************/
//procedimientos y funciones
void gotoxy(int x ,int y){
	
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
void cuadro(int x1, int y1, int x2, int y2){
	int i;
	
	for (i=x1; i<=x2;i++){
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++){
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}
void ingresar_datos(){
	
	char sigue;

	do{
		system("cls");
		
		cuadro(10,7,95,24);
		cuadro(18,3,38,5);
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(20,04); printf("INGRESANDO DATOS");

		SetConsoleTextAttribute (hConsoleHandle, 6);
		gotoxy(12,8); printf("CEDULA DEL ESTUDIANTE --> ");
		scanf("%i", &cedEstudiante);
		gotoxy(12,10); printf("NOMBRE DEL ESTUDIANTE --> ");
		scanf(" %[^\n]", &nomEstudiante);
		gotoxy(12,12); printf("AÑO DE NACIMIENTO DEL ESTUDIANTE --> ");
		scanf("%i", &annioNacimiento);
		gotoxy(12,14); printf("INGRESE LA CALIFICACION DE MATEMATICAS --> ");
		scanf("%f", &promedios[0]);
		gotoxy(12,16); printf("INGRESE LA CALIFICACION DE ESPAÑOL --> ");
		scanf("%f", &promedios[1]);
		gotoxy(12,18); printf("INGRESE LA CALIFICACION DE CIENCIAS --> ");
		scanf("%f", &promedios[2]);
		gotoxy(12,20); printf("INGRESE LA CALIFICACION DE ESTUDIOS SOCIALES --> ");
		scanf("%f", &promedios[3]);
		gotoxy(12,22); printf("CALIFICACION DEL EXAMEN DE ADMISIÓN DE LA UNIVERSIDAD --> ");
		scanf("%f", &notaExamenAdmision);
		
		system("cls");
		
		cuadro(10,7,95,24);
		cuadro(18,3,38,5);
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(20,04); printf("DATOS INGRESADOS");
		
		SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,8); printf("CEDULA: %i", cedEstudiante);
		gotoxy(12,9); printf("NOMBRE: %s", &nomEstudiante);
		gotoxy(12,10); printf("AÑO DE NACIMIENTO: %i", annioNacimiento);
		gotoxy(12,11); printf("EDAD: %i", calculoEdad());
		gotoxy(12,13); printf("CALIFICACION MATEMATICAS: %0.2f", promedios[0]);
		gotoxy(12,14); printf("CALIFICACION ESPAÑOL: %0.2f", promedios[1]);
		gotoxy(12,15); printf("CALIFICACION CIENCIAS: %0.2f", promedios[2]);
		gotoxy(12,16); printf("CALIFICACION ESTUDIOS SOCIALES: %0.2f", promedios[3]);
		gotoxy(12,17); printf("PROMEDIO COLEGIO: %0.2f", promedioColegio());
		gotoxy(12,19); printf("PORCENTAJE CRITERIO COLEGIO: %0.2f", porcentajeCriterioColegio());
		gotoxy(12,20); printf("PORCENTAJE EXAMEN ADMISION: %0.2f", porcentajeCriterioExamenAdmision());
		gotoxy(12,21); printf("PROMEDIO ADMISION: %0.2f", promedioAdmision());
		gotoxy(12,22); printf("ESTADO DE ADMISION: %s", estadoCalificacion().c_str());
		
		
		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(75,23);printf("Desea Continuar S/N");
			sigue=getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	}while (tolower(sigue)=='s');
	//tolower convierte a minuscula
	//toupper convierte a mayuscula
	
}
int calculoEdad(){
	
	int anioActual = obtenerAnnioActual();
	int edad;

	edad = anioActual - annioNacimiento;
	
	return edad;
	
}
float promedioColegio(){
	
	float sumaNotas;
	float promedio;
	
	for(int i=0; i<4; i++){
		sumaNotas += promedios[i];
	}
	
	promedio = sumaNotas/4;
	
	return promedio;
}
float porcentajeCriterioColegio(){
	
	return (promedioColegio()/100)*40;
	
}
float porcentajeCriterioExamenAdmision(){
	
	return (notaExamenAdmision/100)*60;
	
	
}
float promedioAdmision(){
	return porcentajeCriterioColegio() + porcentajeCriterioExamenAdmision();
}
string estadoCalificacion(){
	float promedio = promedioAdmision();
	
	if(promedio<75){
		
		estadoAdmision ="No admitido";
		cantNoAdmitidos+=1;
		acumuladoNoAdmitidos = acumuladoNoAdmitidos +  promedio;
		promNoAdmitidos = acumuladoNoAdmitidos/cantNoAdmitidos;
		
	}else if(promedio>=75 && promedio<85){
		
		estadoAdmision ="En Espera";
		cantEnEspera+=1;
		acumuladoEnEspera = acumuladoEnEspera + promedio;
		promEnEspera = acumuladoEnEspera/cantEnEspera;
		
	}else{
		
		estadoAdmision ="Admitido";
		cantAdmitidos+=1;
		acumuladoAdmitidos= acumuladoAdmitidos + promedio;
		promAdmitidos = acumuladoAdmitidos/cantAdmitidos;
		
	}
	
	return estadoAdmision;
}
void hacer_graficos(int a,int y){
	int i;int j=20;
	for (i=1; i<=a; i++){
		gotoxy (j,y); printf("%c",178);
		j++;
	}
}
void graficos(){  
  
	system("cls");
   	printf("\n*******Graficos segun la Condicion*******");
	
	gotoxy(2,3);	printf("Admitidos");
	hacer_graficos(cantAdmitidos,3);
	
	gotoxy(2,5);	printf("En Espera");
	hacer_graficos(cantEnEspera,5);
	
	gotoxy(2,7);	printf("No Admitidos");
	hacer_graficos(cantNoAdmitidos,7);


	gotoxy(1,9);	printf("<Pulse tecla para Abandonar> ");
	getch();
}
void estadisticas(){
	system ("cls");
	
	cuadro(10,7,70,24);
	cuadro(27,3,56,5);
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(31,04); printf("**** ESTADISTICAS ****");

	SetConsoleTextAttribute (hConsoleHandle, 3);          
	gotoxy(20,9);  printf("Cantidad Estudiantes Admitidos: %i", cantAdmitidos);
	gotoxy(20,10); printf("Sumatoria Estudiantes Admitidos:  %0.2f", acumuladoAdmitidos);
	gotoxy(20,11); printf("Promedio Estudiantes Admitidos: %0.2f ", promAdmitidos);
	       
	SetConsoleTextAttribute (hConsoleHandle, 6);
	gotoxy(20,13);  printf("Cantidad Estudiantes En Espera: %i", cantEnEspera);
	gotoxy(20,14); printf("Sumatoria Estudiantes En Espera:  %0.2f", acumuladoEnEspera);
	gotoxy(20,15); printf("Promedio Estudiantes En Espera: %0.2f ", promEnEspera);
	                  
	SetConsoleTextAttribute (hConsoleHandle, 12);
	gotoxy(20,17);  printf("Cantidad Estudiantes No Admitidos: %i", cantNoAdmitidos);
	gotoxy(20,18); printf("Sumatoria Estudiantes No Admitidos:  %0.2f", acumuladoNoAdmitidos);
	gotoxy(20,19); printf("Promedio Estudiantes No Admitidos: %0.2f ", promNoAdmitidos);
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(40,23); printf("<Pulse tecla para Abandonar>");
	getch();
}
void menu(){
	char opc,conti;
//HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
	
	do{
		

		system("cls");
		cuadro(16,2,65,6); //primer cuadro de arriba hacia abajo
		cuadro(8,8,72,22);//grande
		cuadro(8,23,72,25); //cuadro de abajo opcion es
		cuadro(56,19,68,21); //cuadro pequeño salir

		SetConsoleTextAttribute (hConsoleHandle, 10);
	    gotoxy(22,4);printf("***** MENU PRINCIPAL DEL PROGRAMA *****");
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);printf("[1]  INGRESAR DATOS");
		gotoxy(15,12);printf("[2]  ESTADISTICAS");
		gotoxy(15,14);printf("[3]  GRAFICOS");
		gotoxy(57,20);printf("<[4] SALIR>");
		
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,24);printf("Su opcion es: ");
		opc=getch();

		switch(opc)
		{
		case '1': ingresar_datos();break;
		case '2': estadisticas(); break;
		case '3': graficos(); break;
		
		case '4': 
				
			system("cls");
			gotoxy(20,10);printf("Estas seguro Que Deseas Salir del Sistema");
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,15);printf("Desea Continuar S/N");
			conti=getch();

			if (conti=='N' || conti=='n')
				menu();
			else if (conti=='S' || conti=='s')

		
				break; 
		
		}
			

		}while(opc!='4');
}

int main(int argc, char** argv) {
	
	menu();
	
	return 0;
}
