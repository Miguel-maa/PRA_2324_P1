#include <ostream>

using namespace std;

template <typename T> 
class Node {
    public:
        
        T data;     // El elemento almacenado, de tipo genérico T.
        Node<T>* next;  // Puntero al siguiente nodo de la secuencia.
        
        Node(T data, Node<T>* next=nullptr){    // Método constructor.
            // cout << data;
            
            this-> data = data;
            this-> next = next;
        }
        
        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){    // Sobrecarga global del operador << para imprimir una instancia de Node<T> por pantalla.

            out << " " << node.data;
                
            return out;
        }
};
