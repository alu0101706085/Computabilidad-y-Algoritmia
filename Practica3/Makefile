# Variables
CC = g++
CFLAGS = -Wall -g -std=c++11 -I./include
TARGET = $(SRC_DIR)/p03_ejecutable

# Directorios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Archivos fuente
SRCS = $(SRC_DIR)/p03_ejecutable.cc \
       $(SRC_DIR)/clase_Estructura.cc \
       $(SRC_DIR)/clase_Funcion.cc \
       $(SRC_DIR)/Clase_Generar_Reporte.cc \
       $(SRC_DIR)/clase_PatronesRegex.cc

# Archivos objeto
OBJS = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean run help

# Regla principal
all: $(TARGET)

# Regla para el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Regla para archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)

# Ejecutar
run: all
	$(TARGET) $(SRC_DIR)/fichero_entrada.txt $(SRC_DIR)/fichero_salida.txt

# Ayuda
help:
	@echo "Opciones:"
	@echo "  make         Compila el programa principal."
	@echo "  make clean   Limpia los archivos generados."
	@echo "  make run     Ejecuta el programa principal."
	@echo "  make help    Muestra esta ayuda."
