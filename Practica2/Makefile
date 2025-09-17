# Variables
CC = g++
CFLAGS = -Wall -g
TARGETS = main
OBJECTS = $(TARGETS:%=.o)

.PHONY: all clean run help

# Regla principal
all: $(TARGETS)

# Reglas para cada ejecutable
$(TARGETS): %: %.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(TARGETS) *.o

# Ejecutar
run: all
	./binary_to_decimal
	./leap_year
	./decimal_to_binary
	./suma_digitos
	./serie_de_Fibonacci

# Ayuda
help:
	@echo "Opciones:"
	@echo "  make         Compila todos los programas."
	@echo "  make clean   Limpia los archivos generados."
	@echo "  make run     Ejecuta los programas."
	@echo "  make help    Muestra esta ayuda."