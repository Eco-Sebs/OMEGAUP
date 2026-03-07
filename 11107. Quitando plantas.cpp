/*

Direccion del problema:https://omegaup.com/arena/problem/Quitando-plantas/#problems

FUNCIONES UTILIZADAS

QUEUE (cola) - #include <queue>

push(x)   -> Inserta un elemento al final de la cola.
pop()     -> Elimina el primer elemento de la cola (el más viejo).
front()   -> Devuelve el primer elemento de la cola.
size()    -> Devuelve el número de elementos en la cola.


SET (conjunto) - #include <set>

insert(x) -> Agrega un elemento al conjunto.
erase(x)  -> Elimina un elemento del conjunto.
count(x)  -> Verifica si el elemento existe en el conjunto.
             Devuelve 1 si existe y 0 si no existe.


IDEA DEL PROGRAMA

- La cola (queue) guarda las plantas en el orden en que fueron plantadas.
  Esto permite saber cuál es la planta más vieja.

- El set guarda los tipos de plantas que ya están en el huerto,
  para poder saber rápidamente si una planta ya existe.

PROCESO

Para cada planta que llega:
1. Si ya existe en el huerto ? no se hace nada.
2. Si no existe:
   - Si el huerto está lleno ? se elimina la planta más vieja.
   - Se agrega la nueva planta.
3. Se cuenta cada planta nueva que se coloca.
*/

#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;  // n = número de días, k = tamaño del huerto

    queue<int> huerto;   // cola que guarda el orden de las plantas
    set<int> plantas;    // conjunto para saber qué plantas existen

    int contador = 0;    // cuenta cuántas plantas se plantaron

    for(int i = 0; i < n; i++) {

        int x;
        cin >> x;  // tipo de planta que llega ese día

        // Si la planta ya existe en el huerto
        if(plantas.count(x)) {
            continue;  // no se planta nada
        }

        // Si el huerto está lleno
        if(huerto.size() == k) {

            int vieja = huerto.front(); // obtener la planta más vieja
            huerto.pop();               // quitar la planta más vieja
            plantas.erase(vieja);       // eliminarla del conjunto
        }

        // Plantar la nueva planta
        huerto.push(x);       // agregar a la cola
        plantas.insert(x);    // agregar al conjunto

        contador++;           // contar la nueva planta
    }

    // mostrar cuántas plantas se plantaron
    cout << contador << endl;

    return 0;
}
