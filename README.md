# Readme

## Server with Signal Handling and Forking

### Overview

This program is a server implemented in C that handles incoming connections, utilizes signal handling, and employs forked processes to handle multiple clients simultaneously. The server can switch between two modes: one where it calculates the global maximum value among connected clients and another where it calculates the maximum value locally for each client.

### Features

- **Signal Handling:** The server responds to two custom signals (`SIGUSR1` and `SIGUSR2`). `SIGUSR1` toggles between global and local maximum calculation modes, while `SIGUSR2` resets the global maximum value.

- **Forking:** Upon accepting a client connection, the server forks a new process to handle communication with the client, allowing multiple clients to be served concurrently.

- **Socket Communication:** The server communicates with clients over a TCP socket. Clients send pairs of integers, and the server responds with either the local maximum (in local mode) or the global maximum (in global mode).

### How to Compile and Run

Compile the code using a C compiler (e.g., `gcc`) by running:

```bash
gcc server.c -o server
```

Run the compiled executable:

```bash
./server
```

### Usage

- The server listens on port 8765 by default. Clients can connect to the server and send pairs of integers.

- The server responds with either the local maximum (when in local mode) or the global maximum (when in global mode).

- To toggle between global and local mode, send `SIGUSR1` to the server.

- To reset the global maximum value, send `SIGUSR2` to the server.

### Signal Handling

- **SIGUSR1 (`start` mode toggle):**
  - Description (EN): Toggles between global and local mode.
  - Descrizione (IT): Cambia tra modalità globale e locale.

- **SIGUSR2 (`val_max_glob` reset):**
  - Description (EN): Resets the global maximum value.
  - Descrizione (IT): Reimposta il valore massimo globale.

### Notes

- This server is a basic example and may need additional error handling and security measures for production use.

---

# Readme (Italiano)

## Server con Gestione dei Segnali e Forking

### Panoramica

Questo programma è un server implementato in C che gestisce le connessioni in arrivo, utilizza la gestione dei segnali e impiega processi biforcati per gestire contemporaneamente più client. Il server può passare tra due modalità: una in cui calcola il valore massimo globale tra i client connessi e un'altra in cui calcola il valore massimo localmente per ogni client.

### Funzionalità

- **Gestione dei Segnali:** Il server risponde a due segnali personalizzati (`SIGUSR1` e `SIGUSR2`). `SIGUSR1` alterna tra le modalità di calcolo del massimo globale e locale, mentre `SIGUSR2` resetta il valore massimo globale.

- **Biforcazione:** All'accettare una connessione client, il server biforca un nuovo processo per gestire la comunicazione con il client, consentendo il servizio simultaneo di più client.

- **Comunicazione Socket:** Il server comunica con i client su una socket TCP. I client inviano coppie di interi, e il server risponde con il massimo locale (in modalità locale) o il massimo globale (in modalità globale).

### Come Compilare ed Eseguire

Compila il codice utilizzando un compilatore C (ad esempio, `gcc`) eseguendo:

```bash
gcc server.c -o server
```

Esegui il file eseguibile compilato:

```bash
./server
```

### Utilizzo

- Il server ascolta sulla porta 8765 di default. I client possono connettersi al server e inviare coppie di interi.

- Il server risponde con il massimo locale (in modalità locale) o il massimo globale (in modalità globale).

- Per alternare tra le modalità globale e locale, inviare `SIGUSR1` al server.

- Per reimpostare il valore massimo globale, inviare `SIGUSR2` al server.

### Gestione dei Segnali

- **SIGUSR1 (cambio modalità `start`):**
  - Descrizione: Alterna tra modalità globale e locale.

- **SIGUSR2 (reset `val_max_glob`):**
  - Descrizione: Reimposta il valore massimo globale.

### Note

- Questo server è un esempio di base e potrebbe necessitare di ulteriore gestione degli errori e misure di sicurezza per un uso in produzione.
