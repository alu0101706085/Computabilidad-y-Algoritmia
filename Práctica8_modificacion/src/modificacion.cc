#include "../include/modificacion.h"

const Simbolo kCADENA_VACIA("&", true);

bool Modificacion::VerificarFNC(const Gramatica& gramatica) {
  for (const auto& produccion : gramatica.GetProducciones()) {
    const auto& secuencia = produccion.GetSecuencia();
    // Caso 1: Producción vacía
    if (secuencia.size() == 1 && secuencia[0] == kCADENA_VACIA) {
      if (produccion.GetSimbolo() != gramatica.GetEstadoArranque()) {
        return false;
      }
    }
    // Caso 2: Producción con un terminal (A -> a)
    if (secuencia.size() == 1 && !secuencia[0].GetEsTerminal()) {
      return false; 
    }
    // Caso 3: Producción binaria (A -> BC)
    if (secuencia.size() == 4) {
      if (secuencia[0].GetEsTerminal() || secuencia[2].GetEsTerminal()) {
        return false;
      }
    }
  }
  return true;
}
