#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>


using namespace std;

struct tienda
{
	//declaracion de variable

	int idcontrato, numprod;
	string proveedor, videojuego, consola, genero;
	float subtotal, iva, total;
};


int main()
{
	tienda compras[3]; //se puede modificar la cantidad para que el programa se siga ejecutando
	int opcion, busqueda;

	do
	{
		printf("\t *** ------BlockBuster tienda en linea-------- *** \n");
		printf(" 1.-Alta de producto \n 2.-Lista \n 3.-Eliminar \n 4.-Limpiar \n 5.-Salir \n");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			for (int i = 0; i < 3; i++)
			{
				compras[i].idcontrato = 1 + i;
				printf("ID CONTRATO: %d \n", compras[i].idcontrato);
				int salida=1;
				do
				{
					printf("ingrese el numero del producto: \n");
					scanf("%d", &compras[i].numprod);
				} while (compras[i].numprod == compras[i - 1].numprod ||compras[i].numprod == compras[i - 2].numprod);
					
					
					//proveedor 
				printf("ingrese el proveedor:\t\t\t **Microsoft, sony o Nintendo** \n");   //referencia de provedores
				cin.ignore();
				getline(cin, compras[i].proveedor);
				printf("ingrese la consola del videojuego que desea adquirir: \n");
				cin.ignore();
				getline(cin, compras[i].consola);
				printf("ingrese el videojuego de dicha consola: \n");
				cin.ignore();
				getline(cin, compras[i].videojuego);
				printf("ingrese el subtotal \n");
				scanf("%f", &compras[i].subtotal);
				compras[i].iva = compras[i].subtotal * .16;
				compras[i].total = compras[i].subtotal + compras[i].iva;
				//compras[i].total =compras[i].subtotal*1.16;
			}
			break;

		case 2: //lista
			int opc2;
			printf("1.- Numero de producto \n 2.-Listas Vigentes \n");
			scanf("%d", &opc2);
			if (opc2 == 1)
			{
				printf("ingrese el Numero del producto:");
				scanf("%d", &busqueda);

				//imprimir los datos por posicion 
				for (int i = 0; i < 3; i++)
				{
					if (busqueda == compras[i].numprod)
					{
						printf("ID CONTRATO: %d \n", compras[i].idcontrato);
						printf("Numero del producto: %d \n", compras[i].numprod);
						//proveedor
						printf("proveedor: %s\n", compras[i].proveedor.c_str());
						printf("consola: %s\n", compras[i].consola.c_str());
						printf("videojuego: %s\n", compras[i].videojuego.c_str());
						printf("subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("total: %f \n", compras[i].total);
					}
				}
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					if (compras[i].numprod !=0)
					{
						printf("ID CONTRATO: %d \n", compras[i].idcontrato);
						printf("Numero del producto: %d \n", compras[i].numprod);
						//proveedor
						printf("proveedor: %s\n ", compras[i].proveedor.c_str());
						printf("consola: %s\n", compras[i].consola.c_str());
						printf("videojuego: %s\n", compras[i].videojuego.c_str());
						printf("subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("total: %f \n", compras[i].total);
					}
				}
			}
			break;

		case 3:// no hara nada
			printf("ingrese el numero del producto:");
			scanf("%d", &busqueda);

			//imprimir los datos por posicion 
			for (int i = 0; i < 3; i++)
			{
				if (busqueda == compras[i].numprod)
				{
					compras[i].numprod = 0;
				}
			}
			break;

		case 4:
			system("clear");
			break;
		case 5:
			printf("saliendo... \n");
			break;
		default:
			printf("intente denuevo... \n");
			break;
		}
	} while (opcion != 5);
	system("pause");
}