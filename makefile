# Variables
CC = gcc
CFLAGS = -Wall -Wextra -I.  # Inclure le répertoire actuel pour les fichiers .h
TARGET = bank_manager
SRCS = main.c account.c transactions.c utils.c

# Règle principale
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)
