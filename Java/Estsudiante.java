/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.estsudiante;

/**
 *
 * @author GT ECUADOR
 */
public class Estsudiante {
   

    private String cedula;
    private String nombre;
    private String apellido;
    private double nota1, nota2, nota3;
    private double promedio;
    private String estado;

    public Estsudiante(String cedula, String nombre, String apellido, double n1, double n2, double n3) {
        this.cedula = cedula;
        this.nombre = nombre;
        this.apellido = apellido;
        this.nota1 = n1;
        this.nota2 = n2;
        this.nota3 = n3;
        calcularPromedio();
        determinarEstado();
    }

    private void calcularPromedio() {
        this.promedio = (this.nota1 + this.nota2 + this.nota3) / 3.0;
    }

    private void determinarEstado() {
        if (this.promedio >= 7.00) {
            this.estado = "Aprobado";
        } else {
            this.estado = "Reprobado";
        }
    }

    public String getEstado() {
        return this.estado;
    }

    public String getNombreCompleto() {
        return this.nombre + " " + this.apellido;
    }

    public void mostrarInformacion() {
        System.out.printf("%-15s %-25s %-8.2f %-8.2f %-8.2f %-10.2f %-10s%n",
            this.cedula, getNombreCompleto(), this.nota1, this.nota2, this.nota3, this.promedio, this.estado);
    }
}

