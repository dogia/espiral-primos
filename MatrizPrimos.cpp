#include <iostream>
#include <locale.h>

/*
	Ejercicio: Crear una matriz de n*n y llenarla en forma de espiral, luego,
	determinar cuales son los n�meros primos dentro de ella y sumar todos los n�meros primos.	
*/

using namespace std;

/*
*	Funci�n que me permite verificar si un n�mero es primo o no
*/
bool esPrimo(int numero)
{
	int divisor = 2;
		
	/*
		No hace falta buscar en cada divisor, todos los primos
		mayores que 3 est�n al lado de un m�ltiplo de 6 as� optimizamos
		mucho en la b�squeda y solo tenemos que buscar en 1/3 de los casos y como es modulo 6
		s�lo tendremos que contar hasta 1/5 de los n�meros puesto que 6 es m�ltiplo de 2 y de 3
	*/
	
	if (numero > 3){
		if (((numero % 6) != 5) && ((numero % 6) != 1)){
			return false;
		}
	}
	
	// El n�mero 1 no es primo
	if (numero == 1){
		return false;
	}
	
	// Determinamos si es primo
	for (int i = 0; i < (numero/5); i++){ 
		if ((numero % divisor) == 0 && numero > 2){ 
			// Si la divisi�n es exacta no es primo
			return false;
		}
		divisor++;
	}
	
	// Si no tiene divisores es primo
	return true;
}

int main()
{
	// Establecemos la locaci�n para poder escribir caracteres especiales en la consola
	setlocale (LC_ALL,"");
	
	// Punto de entrada, solicitud del tama�o de la matr�z
	int n = 0; // tama�o de la matr�z
	cout<<"Por favor determine el tama�o de la matr�z a llenar: ";
	cin>>n; // Guardamos el tama�o de la matr�z
	
	int matriz[n][n]; // Creamos nuestra matriz con la dimensi�n dada.
	int sumatoria_primos = 0;
	
	int numero = 1; // Contiene el n�mero que se guardara en la posici�n i j en la matr�z
	
	// Variables para la direccionalidad dentro de la matriz
	bool arriba = false;
	bool abajo = false;
	bool izquierda = false;
	bool derecha = true;
	
	// Variables dimensionales para el cambio de direcci�n (nos dicen cuanto hemos rellenado)
	int top = 1;
	int bottom = n - 1;
	int left = 0;
	int right = n - 1;
	
	char c;
	
	// Llenamos la matris
	for (int i = 0; i < n; NULL){
		for (int j = 0; j < n; NULL){
			// Llenamos la matriz primeramente con ceros
			matriz[i][j] = numero;
			if (esPrimo(numero)){
				// Si es primo lo sumamos
				sumatoria_primos += numero;
			}
			
			numero++; // Incrementamos n�mero
			
			// Tomamos una decisi�n sobre qu� campo rellenar
			if(derecha){
				j++;
				// �Cambiamos de direcci�n?
				if (j >= right){
					derecha = false; // Anulamos el movimiento a la derecha
					abajo = true; // Y comenzamos a bajar
					right--;
				}
			}else if(izquierda){
				j--;
				if (j == left){// Llegamos al borde izquierdo
					izquierda = false; // Anulamos el movimiento a la izquierda
					arriba = true; // Y comenzamos a movernos hacia arriba
					left++;
				}
			}else if(abajo){
				i++;
				// �Cambiamos de direcci�n?
				if (i >= bottom){
					abajo = false; // Anulamos el movimiento hacia abajo
					izquierda = true; // Y comenzamos a movernos a la izqueirda
					bottom--;
				}
			}else if(arriba){
				i--;
				// �Cambiamos de direcci�n?
				if (i == top){
					arriba = false; // Anulamos el movimiento hacia arriba
					derecha = true; // Y comenzamos a movernos a la derecha de nuevo
					top++;
				}
			}
			
			// Hemos llenado la criba
			if(numero >= ((n*n)+1)){
				break;
			}
		}
		
		// Hemos llenado la criba
		if(numero >= ((n*n)+1)){
			break;
		}
	}
	
	
	// Hacemos espacio a la figura de la matr�z
	cout<<endl;
	//Imprimimos la matriz
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if(esPrimo(matriz[i][j])){
				cout<<matriz[i][j]<<"*\t";
			}else{
				cout<<matriz[i][j]<<"\t";
			}
		}
		cout<<endl<<endl;
	}
	
	cout<<endl<<"La sumatoria de los n�meros primos dentro de la matr�z es: "<<sumatoria_primos;
	return 0;
}

