#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <clocale> // La siguiente libreria permite ingresar tildes y caracteres especiales

using namespace std;

// DEFINICION DE LA CLASE ESTUDIANTE (USANDO PROGRAMACION ORIENTADA A OBJETOS)
class Estudiante {
private:
    // Atributos privados controlados por medio de Encapsulamiento
    string cedula;
    string nombre;
    string apellido;
    double nota1, nota2, nota3;
    double promedio;
    string estado;

public:
    // Constructor parametrizado de la clase que inicializa y procesa los datos
    Estudiante(string _cedula, string _nombre, string _apellido, double _n1, double _n2, double _n3) {
        cedula = _cedula;
        nombre = _nombre;
        apellido = _apellido;
        nota1 = _n1;
        nota2 = _n2;
        nota3 = _n3;
        calcularPromedio(); // Invoca automaticamente el metodo de calculo interno
        determinarEstado(); // Invoca automaticamente la asignacion de estado
    }

    // Metodos de logica del negocio
    void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3.0; // Aplica el divisor real para conservar precision
    }

    void determinarEstado() {
        // Condicion logica de aprobacion establecida en la escala academica de 7.00
        if (promedio >= 7.00) {
            estado = "Aprobado";
        } else {
            estado = "Reprobado";
        }
    }

    // Metodos de acceso publicos (Getters) para interactuar de forma externa de manera segura
    string getEstado() { return estado; }
    string getNombreCompleto() { return nombre + " " + apellido; }

    // Metodo encargado de renderizar y dar formato tabular estricto a las salidas en consola
    void mostrarInformacion() {
        cout << left << setw(15) << cedula
             << setw(25) << getNombreCompleto()
             << setw(8) << fixed << setprecision(2) << nota1
             << setw(8) << nota2
             << setw(8) << nota3
             << setw(10) << promedio
             << setw(10) << estado << endl;
    }
};

// ============================================================================
// FUNCION AUXILIAR PARA VALIDAR CEDULA DE 10 DIGITOS
// ============================================================================
string leerCedula() {
    string ced;
    while (true) {
        cout << "  Cedula (10 digitos): ";
        cin >> ced;

        // Verifica que la longitud de la cadena de entrada cumpla el estandar de identificacion
        if (ced.length() == 10) {
            return ced; // Retorna el valor rompiendo el bucle infinito solo si es valido
        }
        cout << "  [Error] La cedula debe tener exactamente 10 digitos. Intente de nuevo.\n";
    }
}

// FUNCION AUXILIAR PARA VALIDAR NOTAS EN EL RANGO CERRADO [0, 10]
double leerNota(string numeroNota) {
    double nota;
    while (true) {
        cout << "  Ingrese " << numeroNota << " (0 - 10): ";
        cin >> nota;
        // Evalua que la calificacion cargada este dentro de los limites esperados
        if (nota >= 0 && nota <= 10) {
            return nota; // Retorna la calificacion valida
        }
        cout << "  [Error] La nota debe estar entre 0 y 10. Intente de nuevo.\n";
    }
}
// PROGRAMA PRINCIPAL (MAIN)

int main() {
    // Configura la consola para mostrar tildes y enes del alfabeto espanol correctamente
    setlocale(LC_ALL, "spanish");

    vector<Estudiante> listaEstudiantes; // Contenedor dinamico de objetos tipo Estudiante
    int totalEstudiantes = 5; // Constante de iteracion para el numero minimo requerido

    cout << "==================================================\n";
    cout << " SISTEMA DE REGISTRO DE CALIFICACIONES (C++)     \n";
    cout << "==================================================\n";

    // Fase interactiva de registro de datos por teclado
    for (int i = 0; i < totalEstudiantes; i++) {
        string cedula, nombre, apellido;
        double n1, n2, n3;

        cout << "\n--- Registro del Estudiante " << (i + 1) << " ---\n";

        // Llamamos a la funcion encargada de encapsular la validacion de la cedula
        cedula = leerCedula();

        // Limpiamos el buffer residual del flujo de lectura de consola para prevenir saltos de linea inesperados
        cin.ignore();

        cout << "  Nombre: ";
        getline(cin, nombre);

        cout << "  Apellido: ";
        getline(cin, apellido);

        // Captura interactiva utilizando los filtros de consistencia numerica
        n1 = leerNota("Nota 1");
        n2 = leerNota("Nota 2");
        n3 = leerNota("Nota 3");

        // Instanciacion directa del objeto y almacenamiento seguro dentro del vector
        Estudiante est(cedula, nombre, apellido, n1, n2, n3);
        listaEstudiantes.push_back(est);
    }

    int aprobados = 0, reprobados = 0; // Variables acumuladoras de estadisticas finales

    // Construccion dinamica de la cabecera del listado de salida
    cout << "\n================================================================================\n";
    cout << "                         LISTADO COMPLETO DE ESTUDIANTES                        \n";
    cout << "================================================================================\n";
    cout << left << setw(15) << "Cedula" << setw(25) << "Estudiante" << setw(8) << "N1"
         << setw(8) << "N2" << setw(8) << "N3" << setw(10) << "Prom" << setw(10) << "Estado" << endl;
    cout << "--------------------------------------------------------------------------------\n";

    // Recorrido de los objetos agregados para renderizacion de datos y conteo matematico
    for (size_t i = 0; i < listaEstudiantes.size(); i++) {
        listaEstudiantes[i].mostrarInformacion();

        // Discriminacion de estados llamando a los getters publicos de la clase
        if (listaEstudiantes[i].getEstado() == "Aprobado") {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    // Impresion estructurada del Reporte Estadistico de Cierre de Ciclo
    cout << "--------------------------------------------------------------------------------\n";
    cout << " REPORTE ESTADISTICO:\n";
    cout << "   Estudiantes Aprobados : " << aprobados << "\n";
    cout << "   Estudiantes Reprobados: " << reprobados << "\n";
    cout << "================================================================================\n";

    return 0; // Finalizacion exitosa del programa principal
}
