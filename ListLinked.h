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
        
            Node<T>* aux = first->next; // 1. Situar un puntero aux que apunte al nodo first->next.
            while (aux != nullptr){
                delete first;           // 2. Liberar la memoria ocupada por el nodo al que apunta first.
                first->next = aux->next;    // 3. Actualizar first para que apunte a la mismo nodo que aux.
                aux = first->next;      // 4. Repetir los pasos 1-3 hasta que se alcance el final de la secuencia.
            }        
        }
    
        T operator[](int pos){  // Devuelve el elemento situado en la posición pos.
            if (pos < 0 || pos > size()-1)
                 throw std::out_of_range("Posición inválida");
                    
            Node<T>* aux = first;
            int i=0;
            while (aux != nullptr && i!=pos){   // Buscamos el elemento situado en la posición pos.
                i++;
                aux = aux->next;
            }
            
            return aux->data;  // Devuelve el elemento situado en la posición pos.
        }
        
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){  // Sobr ecarga global del operador << para imprimir una instancia de ListLinked<T> por pantalla.
            out << "List => [";

            if(0 < list.n){ // Comprobamos si existe algun elemento 
                out << endl;

                Node<T>* aux = list.first;
                while (aux != nullptr){
                    out << "  " << aux->data << endl;   // Imprimimos los elementos por pantalla
                    aux = aux->next;
                }
            } 

            out << "]";

            return out;
        }


        // Métodos heredados de la interfaz List<T>
	    void insert(int pos, T e) override{     // Inserta el elemento e en la posición pos.
            if (pos < 0 || pos > size())
                throw std::out_of_range("Posición inválida");

            n++;    // Incrementamos el número de elementos que contiene la lista.
            
            if(pos==0){ // Se Inserta el elemento al principio de la secuencia
                first = new Node(e, first);
            } else {    // Se Inserta el elemento en cualquier otra posición de la secuencia
                Node<T>* prev = nullptr;
                Node<T>* aux = first;

                int i = 0;
                while (aux != nullptr && i < pos){
                    prev = aux;
                    aux = aux->next;
                    i++;
                }
                
                prev->next = new Node(e, aux); // Se Inserta el elemento               
            } 
        }

	    void append(T e) override{  // Inserta el elemento e al final de la lista.
            n++;    // Incrementamos el número de elementos que contiene la lista.
            
            Node<T>* prev = nullptr;
            Node<T>* aux = first;

            int i = 0;
            while (aux != nullptr && i < size()){   // Buscamos la última posición 
                prev = aux;
                aux = aux->next;
                i++;
            }
                
            prev->next = new Node(e, aux); // Inserta el elemento
        }

	    void prepend(T e) override{  // Inserta el elemento e al principio de la lista.
            n++;    // Incrementamos el número de elementos que contiene la lista.
            
            first = new Node(e, first);  // Se Inserta el elemento al principio de la secuencia       
        }

        T remove(int pos) override{  // Elimina y devuelve el elemento situado en la posición pos.
    	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            n--;    // Decrementamos el número de elementos que contiene la lista.
            
            Node<T>* prev = nullptr;
            Node<T>*aux = first;
            int i=0;

            while (aux != nullptr && i != pos){ // Buscamos el nodo de la posición pos.
                prev = aux;
                aux = aux->next;
                i++;
            }

            int num = aux->data;    // Guardamos el elemento situado en la posición pos.

            if (aux != nullptr) { // éxito en la busqueda
                if (aux == first) { // caso a) primer elemento
                    first = aux->next; // (bypass)
                } else { // caso b) resto de elementos
                    prev->next = aux->next; // (bypass)
                }
            
                delete aux; // liberamos memoria
            }

            return num;
        }

        T get(int pos) override{     // Devuelve el elemento situado en la posición pos.
    	    if (pos < 0 || pos > size()-1)
                throw std::out_of_range("Posición inválida");

            Node<T>* aux = first;
            int i=0;
            while (aux != nullptr && i!=pos){   // Buscamos el elemento situado en la posición pos.
                i++;
                aux = aux->next;
            }
            
            return aux->data;  // Devuelve el elemento situado en la posición pos.
        }
        
        int search(T e) override{     // Devuelve la posición en la que se encuentra la primera ocurrencia del elemento e, o -1 si no se encuentra.
    	    Node<T>* aux = first;
            int i = 0;
            while (aux != nullptr && aux->data != e){  // Busqueda del elemento 
                aux = aux->next;
                i++;
            }
            
            if (aux != nullptr) {   // Exito en la busqueda 
                return i;
            } else {        // Busqueda fallida 
                return -1;
            }
        } 

        bool empty() override{      // Indica si la lista está vacía.
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
