#pragma once
#include<mysql.h>
#include<iostream>
#include <time.h>
#include<string>
#include"ConexionBD.h"
using namespace std;

class Marcas {
	//atributos
private: string marca;
	   int id_marca;
	   //constructor
public:
	Marcas() {

	}
	Marcas(string marc, int id_marc) {
		marc = marca;
		id_marc = id_marca;
		
	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string t = to_string(id_marca);
			string insert = "INSERT INTO db_almacen.marcas(idmarcas,marca)VALUES('" + t + "','" + marca + "',)";
			const char* c = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {

				cout << "Ingrse Exitoso" << endl;
			}
			else
			{
				cout << "Error al ingresar los datos" << endl;
			}
		}
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "SELECT * FROM db_almacen.marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << endl;
				}
			}
			else
			{
				cout << "Error al consultar los datos" << endl;
			}
		}
		else {
			cout << "----Conexion fallida----";
		}
		cn.cerrar_conexion();
	}

};


