#ifndef CLASE_GENERAR_REPORTE
#define CLASE_GENERAR_REPORTE

#include <string>
#include "clase_Estructura.h"

class GenerarReporte {
public:
    void GenerarResultado(const std::string& fichero_salida, const Estructura& estructura);
private:
    void EscribirSeccionPrograma(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionDescipcion(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionVariable(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionBucle(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionMain(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionComentarios(std::ofstream& FicheroEscritura, const Estructura& estructura);
};

#endif