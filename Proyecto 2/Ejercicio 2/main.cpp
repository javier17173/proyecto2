#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>


using namespace std;

/***********************************************************************************************/
/*Variables globales*/
//En la placa se puede ingresar solo números o 3 letra y 3 números
string placa = "", marca = "", modelo = "" , nombreTipoVehiculo = "", nombreTipoLavado = ""; 
int tipoLavado = 0, tipoVehiculo = 0;
float precioAPagar = 0.0;
int numFactura = 0; //Variables para el uso del número de factura autonumérico

/*Variables para las estadísticas*/
int cantVehiculoTipo1 = 0, cantVehiculoTipo2 = 0, cantVehiculoTipo3 = 0;
int cantLavado1 = 0, cantLavado2 = 0;
float dineroTotalVehiculo1 = 0.0, dineroTotalVehiculo2 = 0.0, dineroTotalVehiculo3 = 0.0;
float sumatoriaLavado1 = 0.0, sumatoriaLavado2 = 0.0;
float promedioLavado1 = 0.0, promedioLavado2 = 0.0;

/***********************************************************************************************/
//atributo para color de letra
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);

/***********************************************************************************************/
//prototipos de funciones y procedimientos
void menu();
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2);
void lineas();
void ingresarDatosVehiculo();
string asignarTipoVehiculo();
string asignarTipoLavado();
float calculoPrecioAPagar();
void factura();
void estadisticasTipoVehiculo();
void estadisticasTipoLavado();
void hacer_graficos(int a,int y);
void graficoLavadoTipoVehiculo();
void graficoLavadoTipoLavado();


/***********************************************************************************************/
//Funciones y Procedimientos
void gotoxy(int x ,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
void cuadro(int x1, int y1, int x2, int y2){
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}
string asignarTipoVehiculo(){
	if(tipoVehiculo==1){
		nombreTipoVehiculo = "Sencillo";
	}else if(tipoVehiculo==2){
		nombreTipoVehiculo = "4X4";
	}else if(tipoVehiculo==3){
		nombreTipoVehiculo = "Pasado";
	}
	
	return nombreTipoVehiculo;
}
string asignarTipoLavado(){
	if(tipoLavado == 1){
		nombreTipoLavado = "Sencillo";
	}else if(tipoLavado == 2){
		nombreTipoLavado = "Completo";
	}
	return nombreTipoLavado;
}
float calculoPrecioAPagar(){
	
	if(tipoVehiculo==1 && tipoLavado==1){
		precioAPagar = 3000.00;
		cantVehiculoTipo1 += 1;
		cantLavado1 += 1;
		dineroTotalVehiculo1 += precioAPagar;
		sumatoriaLavado1 += precioAPagar;
		
	}else if(tipoVehiculo== 1 && tipoLavado==2){
		precioAPagar = 5000.00;
		cantVehiculoTipo1 += 1;
		cantLavado2 += 1;
		dineroTotalVehiculo1 += precioAPagar;
		sumatoriaLavado2 += precioAPagar;
		
	}else if(tipoVehiculo== 2 && tipoLavado==1){
		precioAPagar = 5000.00;
		cantVehiculoTipo2 += 1;
		cantLavado1 += 1;
		dineroTotalVehiculo2 += precioAPagar;
		sumatoriaLavado1 += precioAPagar;
		
	}else if(tipoVehiculo==2 && tipoLavado==2){
		precioAPagar = 7000.00;
		cantVehiculoTipo2 += 1;
		cantLavado2 += 1;
		dineroTotalVehiculo2 += precioAPagar;
		sumatoriaLavado2 += precioAPagar;
		
	}else if(tipoVehiculo==3 && tipoLavado==1){
		precioAPagar = 7000.00;
		cantVehiculoTipo3 += 1;
		cantLavado1 += 1;
		dineroTotalVehiculo3 += precioAPagar;
		sumatoriaLavado1 += precioAPagar;
		
	}else if(tipoVehiculo == 3 && tipoLavado==2){
		precioAPagar = 12000.00;
		cantVehiculoTipo3 += 1;
		cantLavado2 += 1;
		dineroTotalVehiculo3 += precioAPagar;
		sumatoriaLavado2 += precioAPagar;
		
	}
	
	
	promedioLavado1 = sumatoriaLavado1 / cantLavado1;
	promedioLavado2 = sumatoriaLavado2 / cantLavado2;
	
	return precioAPagar;
	
}
void lineas(){
	for(int i=0; i<70; i++){
		gotoxy(i,4); printf("*");
	}
}
void factura(){
	numFactura +=1;
	system ("cls");
	lineas();
	SetConsoleTextAttribute (hConsoleHandle, 14);
	gotoxy(35,1); printf("***** FACTURA DIGITAL *****");
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(3,2); printf("No. Factura");
	gotoxy(3,5); printf("No. Placa");
	gotoxy(17,5); printf("Marca"); 
	gotoxy(27,5); printf("Modelo");
	gotoxy(37,5); printf("Tipo de Vehiculo");
	gotoxy(56,5); printf("Tipo de Lavado");
	gotoxy(73,5); printf("Precio a Pagar");
	
	gotoxy(17,2); printf("%i", numFactura);
	gotoxy(3,7); printf("%s", &placa);
	gotoxy(17,7); printf("%s", &marca);
	gotoxy(27,7); printf("%s", &modelo);
	gotoxy(37,7); printf("%s", nombreTipoVehiculo.c_str());
	gotoxy(56,7); printf("%s", nombreTipoLavado.c_str());
	gotoxy(73,7); printf("%0.2f", precioAPagar);
	
}
void ingresarDatosVehiculo(){
	char sigue;

	do{
		system("cls");
		
		cuadro(10,7,95,24);
		cuadro(18,3,38,5);
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(20,04); printf("INGRESANDO DATOS");

		SetConsoleTextAttribute (hConsoleHandle, 6);
		gotoxy(12,8); printf("PLACA--> ");
		scanf(" %[^\n]", &placa);
		gotoxy(12,10); printf("MARCA--> ");
		scanf(" %[^\n]", &marca);
		gotoxy(12,12); printf("MODELO--> ");
		scanf(" %[^\n]", &modelo);
		gotoxy(12,14); printf("TIPO DE VEHICULO--> ");
		gotoxy(12,15); printf("1) SENCILLO");
		gotoxy(12,16); printf("2) 4X4");
		gotoxy(12,17); printf("3) MICROBUS O CAMION");
		gotoxy(12,18);
		scanf("%i", &tipoVehiculo);
		gotoxy(12,20); printf("TIPO DE LAVADO--> ");
		gotoxy(12,21); printf("1) SENCILLO");
		gotoxy(12,22); printf("2) COMPLETO");
		gotoxy(12,23);scanf("%i", &tipoLavado);
		
		
		asignarTipoVehiculo();
		asignarTipoLavado();
		calculoPrecioAPagar();
		factura();
		
		
		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,18);printf("Desea Continuar S/N");
			sigue=getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	}while (tolower(sigue)=='s');
	//tolower convierte a minuscula
	//toupper convierte a mayuscula
	
}
void menu(){
	char opc,conti;
	
	do{
		

		system("cls");
		cuadro(16,2,65,6); //primer cuadro de arriba hacia abajo
		cuadro(8,8,80,26);//grande
		cuadro(10,23,72,25); //cuadro de abajo opcion es
		cuadro(60,20,72,22); //cuadro pequeño salir

		SetConsoleTextAttribute (hConsoleHandle, 10);
	    gotoxy(22,4);printf("***** MENU PRINCIPAL DEL PROGRAMA *****");
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(12,10);printf("[1]  INGRESAR DATOS");
		gotoxy(12,12);printf("[2]  ESTADISTICAS VEHICULOS LAVADOS SEGUN TIPO DE VEHICULO");
		gotoxy(12,14);printf("[3]  ESTADISTICAS VEHICULOS LAVADOS SEGUN TIPO DE LAVADO");
		gotoxy(12,16);printf("[4]  GRAFICO VEHICULOS LAVADOS POR TIPO DE VEHICULO");
		gotoxy(12,18);printf("[5]  VER GRAFICO VEHICULOS LAVADOS POR TIPO DE LAVADO");
		
		gotoxy(61,21);printf("<[6] SALIR>");
		
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,24);printf("Su opcion es: ");
		opc=getch();

		switch(opc){
			
		case '1': ingresarDatosVehiculo();break;
		case '2': estadisticasTipoVehiculo(); break;
		case '3': estadisticasTipoLavado(); break;
		case '4': graficoLavadoTipoVehiculo(); break;
		case '5': graficoLavadoTipoLavado(); break;
		
		case '6': 
				
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
			

		}while(opc!='6');

}
void estadisticasTipoVehiculo(){
	system ("cls");
	
	cuadro(10,7,85,24);
	cuadro(27,3,56,5);
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(31,04); printf("**** ESTADISTICAS ****");

	SetConsoleTextAttribute (hConsoleHandle, 3);          
	gotoxy(12,9);  printf("Cantidad de Vehiculos Tipo Sencillos: %i", cantVehiculoTipo1);
	gotoxy(12,10); printf("Dinero Recaudado por Vehiculos Tipo Sencillos:  %0.2f", dineroTotalVehiculo1);
	       
	SetConsoleTextAttribute (hConsoleHandle, 6);
	gotoxy(12,13); printf("Cantidad de Vehiculos Tipo 4x4: %i", cantVehiculoTipo2);
	gotoxy(12,14); printf("Dinero Recaudado por Vehiculos Tipo 4x4:  %0.2f", dineroTotalVehiculo2);
	                  
	SetConsoleTextAttribute (hConsoleHandle, 12);
	gotoxy(12,17); printf("Cantidad de Vehiculos Tipo Microbus o Camion: %i", cantVehiculoTipo3);
	gotoxy(12,18); printf("Dinero Recaudado por Vehiculos Tipo Microbus o Camion:  %0.2f", dineroTotalVehiculo3);
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(40,23); printf("<Pulse tecla para Abandonar>");
	getch();
}
void estadisticasTipoLavado(){
	system ("cls");
	
	cuadro(10,7,105,24);
	cuadro(27,3,56,5);
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(31,04); printf("**** ESTADISTICAS ****");

	SetConsoleTextAttribute (hConsoleHandle, 3);          
	gotoxy(12,9);  printf("Cantidad de Vehiculos con solo Lavado: %i", cantLavado1);
	gotoxy(12,10); printf("Dinero Recaudado por Vehiculos con solo Lavado:  %0.2f", sumatoriaLavado1);
	gotoxy(12,11); printf("Promedio Dinero Recaudado por Vehiculos con solo Lavado:  %0.2f", promedioLavado1);
	       
	SetConsoleTextAttribute (hConsoleHandle, 6);
	gotoxy(12,13); printf("Cantidad de Vehiculos con Lavado, Aspirado y Encerado: %i", cantLavado2);
	gotoxy(12,14); printf("Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado:  %0.2f", sumatoriaLavado2);
	gotoxy(12,15); printf("Promedio Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado:  %0.2f", promedioLavado2);       
	
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(40,23); printf("<Pulse tecla para Abandonar>");
	getch();
}
void hacer_graficos(int a,int y){
	int i;int j=20;
	for (i=1; i<=a; i++){
		gotoxy (j,y); printf("%c",178);
		j++;
	}
}
void graficoLavadoTipoVehiculo(){
	system("cls");
   	printf("\n*******  Graficos segun Tipo de Vehiculo  *******");
	
	gotoxy(2,3);	printf("Veh. Sencillo: ");
	hacer_graficos(cantVehiculoTipo1,3);
	
	gotoxy(2,5);	printf("Veh. 4X4: ");
	hacer_graficos(cantVehiculoTipo2,5);
	
	gotoxy(2,7);	printf("Veh. Pesados: ");
	hacer_graficos(cantVehiculoTipo3,7);

	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(1,9); printf("<Pulse tecla para Abandonar>");
	getch();
}
void graficoLavadoTipoLavado(){
	system("cls");
   	printf("\n*******  Graficos segun Tipo de Lavado  *******");
	
	gotoxy(2,3);	printf("Sencillo: ");
	hacer_graficos(cantLavado1,3);
	
	gotoxy(2,5);	printf("Completo: ");
	hacer_graficos(cantLavado2,5);

	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(1,9); printf("<Pulse tecla para Abandonar>");
	getch();
}


int main(int argc, char** argv) {
	
	menu();
	
	return 0;
}
