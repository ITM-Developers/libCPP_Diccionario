#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

class Diccionario
{
private:
    fstream fichero;
    string nombre_diccionario;

    //Posiciones
    size_t Position;                                //Posicion del caracter que esta siendo modificado en la cadena word
    size_t charsetPos[20];

    char* charset;                                 // Cadena con los caracteres a usar para crear palabras
    char* word;                                    // Palabra inicial del diccionario
    unsigned short int nodeNumber;                  // Para funciones en RED

    //Longitudes
    size_t word_lenght;
    size_t charset_lenght;

    //Contadores
    unsigned long long qty_words_calculated;        // Cantidad de Passwords que han sido calculados por la instancia
    unsigned long long numeroTotalDeCombinaciones;
    unsigned long long limit_of_words;              // Limite de paalabras a calcular

public:
    Diccionario();

    int crearDiccionario();
    // Setters                                              // Getters
    void setCharset(const string& charset);               char* getCharset();
    void setPasswordLenght(size_t wordLenght);              size_t getPasswordLenght();
    bool setInitialWord(const string& word);              char* getInitialWord();
    void setLimitOfWords(unsigned long long limit);        unsigned long long getLimitOfWords();
    void setNodeNumber(unsigned short int number);        unsigned short int getNodeNumber();

    //Funciones Para trabajar en Red Con otros nodos

    // Funcion encargada de establecer el numero de nodo
    // funcion encargada de calcular el rango de palabras
    // funcion encargada de calcular el numero de palaras
    ~Diccionario();
private:
    size_t findChar(const char& caracter);
    void calculateInitialWord();
    void calculateLimitOfWords();
};

#endif // DICCIONARIO_H
