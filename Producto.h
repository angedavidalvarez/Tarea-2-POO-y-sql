#pragma once
#include<mysql.h>
#include<iostream>
#include <time.h>
#include<string>
#include"ConexionBD.h"
using namespace std;

class Producto {
	//atributos
private: string producto, descripcion, fecha_ingreso, precio_venta, precio_costo;
	     int existencia;
		 int id_marca;
		 //constructor
public:
	Producto() {

	}
	Producto(string produc, string des, string fi, string precioventa, string preciocompra, int exis, int id_marc) {
		produc = producto ;
	    id_marc = id_marca;
		des = descripcion;
		fi = fecha_ingreso;
		precioventa = precio_venta;
		preciocompra = precio_costo;
		exis = existencia;
	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string t = to_string(id_marca);
			string e = to_string(existencia);
			string insert = "INSERT INTO db_almacen.productos(producto, idMarca,Descripcion, precio_costo,precio_venta,Existencia,Fecha_ingreso)VALUES('" + producto + "','" + t + "','" + descripcion + "','" + precio_costo + "','" + precio_venta + "','" + e + "','" + fecha_ingreso + "',)";
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
			string consulta = "SELECT * FROM db_almacen.productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << endl;
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


