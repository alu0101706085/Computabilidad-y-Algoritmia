# Variables
CC = g++
CFLAGS = -Wall -g -std=c++11 -I./include
TARGET = $(SRC_DIR)/p02_ejecutable

# Directorios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Archivos fuente
SRCS = $(SRC_DIR)/p02_ejecutable.cc \
       $(SRC_DIR)/clase_Alfabeto.cc \
       $(SRC_DIR)/clase_Cadena.cc \
       $(SRC_DIR)/clase_Lenguaje.cc \
       $(SRC_DIR)/clase_Simbolo.cc

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
	$(TARGET) $(SRC_DIR)/fichero_entrada.txt $(SRC_DIR)/fichero_salida.txt 6

# Ayuda
help:
	@echo "Opciones:"
	@echo "  make         Compila el programa principal."
	@echo "  make clean   Limpia los archivos generados."
	@echo "  make run     Ejecuta el programa principal."
	@echo "  make help    Muestra esta ayuda."
