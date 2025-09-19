# Variables
CC = g++
CFLAGS = -Wall -g -std=c++11
TARGET = p02_ejecutable
SRCS = p02_ejecutable.cc clase_Alfabeto.cc clase_Cadena.cc clase_Lenguaje.cc clase_Simbolo.cc
OBJS = $(SRCS:.cc=.o)

.PHONY: all clean run help

# Regla principal
all: $(TARGET)

# Regla para el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Regla para archivos objeto
%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(TARGET) *.o

# Ejecutar
run: all
	./$(TARGET) fichero_entrada.txt fichero_salida.txt 4

# Ayuda
help:
	@echo "Opciones:"
	@echo "  make         Compila el programa principal."
	@echo "  make clean   Limpia los archivos generados."
	@echo "  make run     Ejecuta el programa principal."
	@echo "  make help    Muestra esta ayuda."