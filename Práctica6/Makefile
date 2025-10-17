# Variables
CC = g++
CFLAGS = -Wall -g -std=c++11 -I./include
TARGET = $(SRC_DIR)/p06_ejecutable

# Directorios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Archivos fuente
SRCS = $(SRC_DIR)/p06_ejecutable.cc \
       $(SRC_DIR)/automata.cc \
       $(SRC_DIR)/simulador.cc \
	   $(SRC_DIR)/estado.cc \

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
	$(TARGET) $(SRC_DIR)/input.fa $(SRC_DIR)/input.txt

# Ayuda
help:
	@echo "Opciones:"
	@echo "  make         Compila el programa principal."
	@echo "  make clean   Limpia los archivos generados."
	@echo "  make run     Ejecuta el programa principal."
	@echo "  make help    Muestra esta ayuda."
