#include <ostream>
#include "List.h"
#include <iostream>

using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados

        T* arr;     // Puntero al inicio del array que almacenará los elementos de la lista de forma contigua.
        int max;    // Tamaño actual del array.
        int n;      // Número de elementos que contiene la lista.
        static const int MINSIZE=2;   // Tamaño mínimo del array.
        
        void resize(int new_size){  // Método que se encargará de redimensionar el array al tamaño especificado.
            T* aux = new int[new_size];  // Crear un nuevo array dinámico de new_size elementos

            for(int i=0; i < size(); i++){  // Copiar el contenido del arr (el array actual) en el nuevo array.
                aux[i] = arr[i];
            } 

            delete[] arr;  // Liberar los recursos de memoria que ocupa arr

            arr = aux;  // Actualizar el puntero arr para que apunte a la dirección de memoria en la que se encuentra el nuevo array.

            max = new_size; // Actualizar max.
        }


    public:
        // miembros públicos, incluidos los heredados de List<T>
       
        ListArray(){    // Método constructor sin argumentos.
            max = 0;
            arr = new int[0];
            n = 0;
        }

        ~ListArray(){   // Método destructor.
            delete arr;
        } 

        T operator[](int pos){  // Devuelve el elemento situado en la posición pos. Lanza una excepción std::out_of_range si la posición no es válida
     	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            return arr[pos];  // Devuelve el elemento situado en la posición pos.
        }            
        
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){   // Sobrecarga global del operador << para imprimir una instancia de ListArray<T> por pantalla.
            out << "List => [";

            if(0 < list.max)    // Comprobamos si existe algun elemento 
                out << endl;

            for(int i=0; i < list.max; i++){
                out << "  " << list.arr[i] << endl; // Imprimimos los elementos por pantalla
            } 

            out << "]";

            return out;
        }



        // Métodos heredados de la interfaz List<T>
	    void insert(int pos, T e) override{     // Inserta el elemento e en la posición pos.
            if (pos < 0 || pos > size())
                throw std::out_of_range("Posición inválida");

            n++;    // Incrementamos el número de elementos que contiene la lista.
            resize(n);  //  Redimensionar el array

            if(pos < n){   // Desplazamos los elemnetos de array que seán necesarios
                for(int i=0; i < n-pos; i++){
                    arr[n - i] = arr[n - 1 - i];
                }
            } 

            arr[pos] = e;   // Inserta el elemento e en la posición pos.
        }

	    void append(T e) override{  // Inserta el elemento e al final de la lista.
            n++;    // Incrementamos el número de elementos que contiene la lista.
            
            resize(n);  //  Redimensionar el array

            arr[size()-1] = e;
        }

	    void prepend(T e) override{  // Inserta el elemento e al principio de la lista.
            n++;    // Incrementamos el número de elementos que contiene la lista.
            
            resize(n);  //  Redimensionar el array
            
            for(int i=0; i < size(); i++){  // Desplazamos los elemnetos de array que seán necesarios
                arr[size() - 1 - i] = arr[size() - 2 - i];
            }
            
            arr[0] = e;
        }

        T remove(int pos) override{  // Elimina y devuelve el elemento situado en la posición pos.
    	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            int aux = arr[pos];  // Guardamos el elemento situado en la posición pos.

            if(pos < n){   // Desplazamos los elemnetos de array que seán necesarios
                for(int i=pos; i < n; i++){
                    arr[i] = arr[i + 1];
                }
            }

            n--;    // Decrementamos el número de elementos que contiene la lista.
            resize(n);  //  Redimensionar el array

            return aux;
        }

        T get(int pos) override{     // Devuelve el elemento situado en la posición pos.
    	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            return arr[pos];  // Devuelve el elemento situado en la posición pos.
        }
        
        int search(T e) override{     // Devuelve la posición en la que se encuentra la primera ocurrencia del elemento e, o -1 si no se encuentra.
    	    int pos;

            for(pos=0; pos < size(); pos++){ // Busqueda del elemento 
                if(arr[pos]==e){
                    return pos;
                } 
            } 

            return -1;
        } 

        bool empty() override{        // Indica si la lista está vacía.
            if(n > 0){
                return false;
            } else {
                return true;
            } 
        } 

        int size() override{         // Devuelve el número de elementos de la lista.
            return n;
        } 
};


