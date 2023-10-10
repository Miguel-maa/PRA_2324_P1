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
        void resize(int new_size);  // Método que se encargará de redimensionar el array al tamaño especificado.

    public:
        // miembros públicos, incluidos los heredados de List<T>
       
        ListArray(){    // Método constructor sin argumentos.
            arr = new int[max];
            n = -1;
        }

        ~ListArray();   // Método destructor.
        T operator[](int pos);  // Devuelve el elemento situado en la posición pos. Lanza una excepción std::out_of_range si la posición no es válida
        // friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);   // Sobrecarga global del operador << para imprimir una instancia de ListArray<T> por pantalla.




        // Métodos heredados de la interfaz List<T>
	    void insert(int pos, T e) override{     // Inserta el elemento e en la posición pos.
            if (pos < 0 || pos > size())
                throw std::out_of_range("Posición inválida");

            arr[pos] = e;
            n++;
        }

	    void append(T e) override;{  // Inserta el elemento e al final de la lista.
            arr[pos] = e;
            n++;
        }

	    void prepend(T e) override;  // Inserta el elemento e al principio de la lista.
	    T remove(int pos) override;  // Elimina y devuelve el elemento situado en la posición pos.
    	T get(int pos) override;     // Devuelve el elemento situado en la posición pos.
    	int search(T e) override;    // Devuelve la posición en la que se encuentra la primera ocurrencia del elemento e, o -1 si no se encuentra.
    	bool empty() override;       // Indica si la lista está vacía.
	    int size() override;         // Devuelve el número de elementos de la lista.
};


