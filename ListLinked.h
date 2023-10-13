#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
    
        Node<T>* first; // Puntero al primer nodo de la secuencia enlazada que almacena los datos de la lista (de tipo T genérico).
        int n;      // Número de elementos que contiene la lista.
    
    
    public:
    
        ListLinked(){   // Método constructor sin argumentos.
            this-> first = nullptr;
            this-> n = 0;
        }
    
        ~ListLinked(){  // Método destructor.
        
            Node<int>* aux = first;
            while (aux != nullptr){
                aux = first->next;
                delete first;
                first->next = aux->next;
            
                aux = aux->next;
            }        
        }
    
        T operator[](int pos){  // Devuelve el elemento situado en la posición pos.
            if (pos < 0 || pos > List<T>::size()-1)
                 throw std::out_of_range("Posición inválida");
            
            int i=0;
            
            Node<int>* aux = first;
            while (aux != nullptr && i!=pos){
                i++;
                aux = aux->next;
            }
            
            return aux->data;  // Devuelve el elemento situado en la posición pos.
        }
        
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){  // Sobr ecarga global del operador << para imprimir una instancia de ListLinked<T> por pantalla.
            return out;
        }
        
};
