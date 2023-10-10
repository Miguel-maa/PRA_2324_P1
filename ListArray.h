#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados

        T* arr;     // Puntero al inicio del array que almacenará los elementos de la lista de forma contigua.
        int max;    // Tamaño actual del array.
        int n;      // Número de elementos que contiene la lista.
        static const int MINSIZE;   // Tamaño mínimo del array.
        
        void resize(int new_size){  // Método que se encargará de redimensionar el array al tamaño especificado.
            T aux = new int[new_size];  // Crear un nuevo array dinámico de new_size elementos

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
            MINSIZE = 2;
            max = MINSIZE;
            arr = new int[MINSIZE];
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
        
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);   // Sobrecarga global del operador << para imprimir una instancia de ListArray<T> por pantalla.




        // Métodos heredados de la interfaz List<T>
	    void insert(int pos, T e) override{     // Inserta el elemento e en la posición pos.
            if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            if(arr[pos] == 0)
                n++;

            arr[pos] = e;
        }

	    void append(T e) override{  // Inserta el elemento e al final de la lista.
            if(arr[max-1] == 0)
                n++;

            arr[max-1] = e;
        }

	    void prepend(T e) override{  // Inserta el elemento e al principio de la lista.
            if(arr[0] == 0)
                n++;

            arr[0] = e;
        }

        T remove(int pos) override{  // Elimina y devuelve el elemento situado en la posición pos.
    	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            if(arr[pos] != 0)
                n--;

            T aux = arr[pos];  // Devuelve el elemento situado en la posición pos.
            arr[pos] = 0;   // Elimina el elemento situado en la posición pos.

            return aux;
        }

        T get(int pos) override{     // Devuelve el elemento situado en la posición pos.
    	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            return arr[pos];  // Devuelve el elemento situado en la posición pos.
        }
        
        int search(T e) override{     // Devuelve la posición en la que se encuentra la primera ocurrencia del elemento e, o -1 si no se encuentra.
    	    int pos;

            for(pos=0; pos < size(); pos++){ 
                if(arr[pos]==e){
                    return pos;
                } 
            } 

            return -1;
        } 

        bool empty() override{        // Indica si la lista está vacía.
            if(n > 0){
                return true;
            } else {
                return false;
            } 
        } 

        int size() override{         // Devuelve el número de elementos de la lista.
            return max;
        } 
};


