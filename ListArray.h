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
       
        ListArray();    // Método constructor sin argumentos.
        ~ListArray();   // Método destructor.
        T operator[](int pos);  // Devuelve el elemento situado en la posición pos. Lanza una excepción std::out_of_range si la posición no es válida
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);   // Sobrecarga global del operador << para imprimir una instancia de ListArray<T> por pantalla.
    
};
