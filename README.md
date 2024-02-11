**Italian README (README_IT.md):** 🇮🇹

```markdown
# Sistema di Controllo Massimo Globale

Questo progetto è un semplice sistema di controllo per il massimo globale tra due numeri. Il server accetta connessioni dai client, riceve due numeri interi e restituisce il massimo tra i due. Inoltre, il server può essere avviato o fermato attraverso i segnali `SIGUSR1` e `SIGUSR2`.

## Caratteristiche

- **Massimo Globale Attivato/Disattivato**: Il server può essere avviato o fermato attraverso i segnali `SIGUSR1` e `SIGUSR2`.
  
- **Calcolo del Massimo**: Se il massimo globale è attivato, il server calcolerà il massimo tra i due numeri e terrà traccia del massimo globale. In caso contrario, calcolerà semplicemente il massimo tra i due numeri.

## Utilizzo

1. **Compila il Codice:**
   ```bash
   gcc massimo_globale.c -o massimo_globale
   ```

2. **Avvia il Server:**
   ```bash
   ./massimo_globale
   ```

3. **Connetti i Client:**
   Utilizza un programma client per connetterti al server e inviare due numeri.

   Esempio:
   ```bash
   ./client 10 20   # Invia i numeri 10 e 20 al server
   ```

   I risultati verranno visualizzati sul terminale del server.

4. **Controlla il Massimo Globale:**
   Puoi attivare o disattivare il calcolo del massimo globale inviando i segnali `SIGUSR1` e `SIGUSR2` al server.

## Contributi

Senti libero di contribuire a questo progetto inviando segnalazioni di bug o richieste di nuove funzionalità.

## Licenza

Questo progetto è concesso in licenza secondo i termini della [Licenza MIT](LICENSE).

---
```

**English README (README.md):** 🇬🇧 🇺🇸

```markdown
# Global Maximum Control System

This project is a simple control system for the global maximum between two numbers. The server accepts connections from clients, receives two integers, and returns the maximum of the two. Additionally, the server can be started or stopped through `SIGUSR1` and `SIGUSR2` signals.

## Features

- **Global Maximum On/Off**: The server can be started or stopped through `SIGUSR1` and `SIGUSR2` signals.
  
- **Maximum Calculation**: If the global maximum is on, the server will calculate the maximum between two numbers and keep track of the global maximum. Otherwise, it will simply calculate the maximum between the two numbers.

## Usage

1. **Compile the Code:**
   ```bash
   gcc massimo_globale.c -o massimo_globale
   ```

2. **Run the Server:**
   ```bash
   ./massimo_globale
   ```

3. **Connect Clients:**
   Use a client program to connect to the server and send two numbers.

   Example:
   ```bash
   ./client 10 20   # Send numbers 10 and 20 to the server
   ```

   Results will be displayed on the server terminal.

4. **Control Global Maximum:**
   You can turn on or off the global maximum calculation by sending `SIGUSR1` and `SIGUSR2` signals to the server.

## Contributing

Feel free to contribute to this project by submitting bug reports or feature requests.

## License

This project is licensed under the [MIT License](LICENSE).

---
