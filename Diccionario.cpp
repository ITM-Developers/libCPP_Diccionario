#include "Diccionario.h"

Diccionario::Diccionario()
{
    nombre_diccionario = "";
    qty_words_calculated = 0;
    limit_of_words = 0;
    word_lenght = 0;
    charset = nullptr;
    word = nullptr;
    nodeNumber = 1;
}

size_t Diccionario::findChar(const char& caracter)
{
    for (size_t i = 0; i < 20; i++) {
        if (caracter == charset[i]) {
            return i;
        }
    }
    return (size_t)-1;    // Un truco que hace que retorne #FFFFFF es decir el valor maximo que puede tener size_t en caso de error
}

void Diccionario::calculateInitialWord()
{

}

void Diccionario::calculateLimitOfWords() {
    // Numero Total de Combinaciones = (Longitud de Charset) ^ (Longitud del Password)
    numeroTotalDeCombinaciones = pow(charset_lenght, word_lenght);
    // Limite de combinaciones = (Numero Total de Combinaciones) / (Numero de Nodos)
    limit_of_words = numeroTotalDeCombinaciones / nodeNumber;

    cout << "Potencia: " << charset_lenght << " al " << word_lenght << endl;
    cout << "Numero de Combinaciones: " << numeroTotalDeCombinaciones << endl;
    cout << "Limite de Palabras: " << limit_of_words << endl;
}

// Getters
char* Diccionario::getCharset() { return charset; }
char* Diccionario::getInitialWord() { return word; }
unsigned long long Diccionario::getLimitOfWords() { return limit_of_words; }
unsigned short int Diccionario::getNodeNumber() { return nodeNumber; }
size_t Diccionario::getPasswordLenght() { return word_lenght; }

// Setters
void Diccionario::setPasswordLenght(size_t lenght) { (word_lenght == 0) ? lenght : word_lenght; }
void Diccionario::setNodeNumber(unsigned short int number) { (number == 0) ? 1 : this->nodeNumber = number; }
void Diccionario::setLimitOfWords(unsigned long long limit) { this->limit_of_words = limit; }

void Diccionario::setCharset(const string& charset) {
    this->charset_lenght = charset.size();                  // Definimos la longitud del charset
    this->charset = (char*)malloc(charset.size());      // Internamente se usa un array char
    strcpy(this->charset, charset.c_str());                // Copiamos los caracteres en nuestro array
}

bool Diccionario::setInitialWord(const string& word) {

    this->word = (char*)malloc(word.size());
    word_lenght = word.size();
    strcpy(this->word, word.c_str());
    this->Position = this->word_lenght - 1;
    size_t index;

    for (size_t i = 0; i < word_lenght; i++) {    // Recorremos la palabra para rellenar el array de posiciones
        index = findChar(word.at(i));           // Pedimos el indice del char en el array charset
        if (index == ((size_t)-1)) {             // Si no encuentra el caracter
            return false;
        }
        else {
            charsetPos[i] = index;
        }
    }
    return true;
}

int Diccionario::crearDiccionario()
{
    /*
    if (word_lenght == 0)
        return EXIT_FAILURE;

    if (word == nullptr)                                 // Si no se ha definido la palabra incial
        calculateInitialWord();                         // la calculamos en funcion del numero de nodo

    if (limit_of_words == 0)                             // Si no se ha definido el limite de palabras
        calculateLimitOfWords();                        // Calulamos el limite en funcion del numero de nodoq

    if (charset != nullptr) {
        //fichero.open(nombre_diccionario.c_str());

        for(size_t i = 0; i < word_lenght; i++){        //CharsetPos Indica el indice en el array de charset, apunta a un char
            charsetPos[i] = 0;
        }

        while (qty_words_calculated < limit_of_words) {

        anidado:    // Si el caracter apuntado no ha llegado al final del charset

            if (Position == ((size_t)-1))  //Si se alcanzo el limite de posibles passwords con la longitud actual se acaba el bucle
                break;

            ++charsetPos[Position];                                     //apuntamos al sig caracter del charset

            if (charsetPos[Position] < charset_lenght) {                //Si no se ha llegado al final de charset
                word[Position] = charset[charsetPos[Position]];     // se le asigna a word el caracter (es la nueva conbinacion de la palabra)
            }
            else {
                charsetPos[Position] = 0;                               // sino reiniciamos el contador para que apunte al primer char de nuevo
                word[Position] = charset[charsetPos[Position]];     // se le asigna a word el caracter (es la nueva conbinacion del password)
                --Position;                                             //Cambiamos la posicion del nivel de profundidad (apuntamos a un caracter mas atras)
                goto anidado;                                           //Hacemos lo mismo de manera recursiva
            }

            cout << word << endl;
            //fichero << word << endl;                                  //Se envian los datos al stream deseado

            --qty_words_calculated;                                     //contabilizamos la cantidad de passwords escritos para tener un limite exacto

            if (Position < word_lenght - 1)
                Position = word_lenght - 1;
        }
        //fichero.close();

    }
    */
    return EXIT_SUCCESS;
}

Diccionario::~Diccionario()
{
    delete this->charset;
    delete this->word;
}
