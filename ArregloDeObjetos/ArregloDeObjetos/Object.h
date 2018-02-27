#pragma once
#ifndef OBJECT_H
#define OBJECT_H
enum Tipo{T_char,T_String,T_Int};

class Object
{
public:
	virtual Tipo getTipo() = 0;
	virtual void imprimir() = 0;

};

#endif // !OBJECT_H
