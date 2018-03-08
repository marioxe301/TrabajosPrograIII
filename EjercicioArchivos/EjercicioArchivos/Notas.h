#pragma once
#ifndef NOTAS_H
#define NOTAS_H


class Notas
{
public:
public:
	static void registrarAlumnos();
	static void consultarAlumnos();
	static void registrarMaterias();
	static void consultarMaterias();
	static void registrarNotas();
	static void consultarNotas();
	static int ObtenerCodigoAlumno(char *);
	static int obtenerCodigoMateria(char *);
	static char* obtenerNombreAlumno(const int);
	static char * obtenerNombreClase(const int);
	static void ObtenerPromedioAlumno(char *);
	static void ObtenerPromedioClases(char *);

};
#endif // !NOTAS_H