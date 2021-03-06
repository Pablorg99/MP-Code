/*----------------------------------------------------------------------------------
Practice 2 Class Persona
persona.h
This is the header file for the class 'Persona' which is going to have some inherited
classes (Crupier, Jugador)
----------------------------------------------------------------------------------*/

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using std::string;


class Persona {
  private:
    string dni_;
    string name_;
    string surnames_;
    int age_;
    string address_;
    string locality_;
    string province_;
    string country_;
  public:
    //Constructor
    //DNI necessary for declaration of a 'Persona' object
    Persona (const string &dni, const string &name = "", const string &surnames = "",
    const int age = 0, const string &address = "", const string &locality = "",
    const string &province = "", const string &country = "");
    //Getter methods
    string getDNI() const {return dni_;}
    string getNombre() const {return name_;}
    string getApellidos() const {return surnames_;}
    int getEdad() const {return age_;}
    string getDireccion() const {return address_ ;}
    string getLocalidad() const {return locality_;}
    string getProvincia() const {return province_;}
    string getPais() const {return country_;}
    //concatenates name and surnames with format "surnames, name"
    string getApellidosyNombre() const {return getApellidos() + ", " + getNombre();}
    //Setter methods
    void setDNI(const string &dni) {dni_ = dni;}
    void setNombre(const string &name) {name_ = name;}
    void setApellidos(const string &surnames) {surnames_ = surnames;}
    //returns true and set value fo 'age_' if 'age' is between 0 and 140
    bool setEdad(const int age);
    void setDireccion(const string &address) {address_ = address;}
    void setLocalidad(const string &locality) {locality_ = locality;}
    void setProvincia(const string &province) {province_ = province;}
    void setPais(const string &country) {country_ = country;}
    //Other methods
    //returns true if object persona is over 18 years old, otherwise returns false
    bool mayor() const;
};

#endif
