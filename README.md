# LCDTest
# LCD introduzione 
Il display a cristalli liquidi (l’acronimo LCD, dall'inglese Liquid Crystal Display) permettono ai circuiti elettronici di visualizzare informazioni e messaggi.
Molto spesso abbiamo bisogno di poter leggere i dati in uscita direttamente da un display LCD, l’integrazione di quest'ultimo favorisce notevolmente l’interattività del nostro progetto, permettendo all’utilizzatore di poter leggere direttamente dei parametri in uscita. Questi valori possono essere un semplice testo come dei valori numerici letti da sensori, come la temperatura o la pressione, o persino il numero di cicli che il nostro Arduino sta eseguendo.
Il principio di funzionamento di uno schermo LCD è basato sulle proprietà ottiche di particolari sostanze chiamate cristalli liquidi. In uno schermo LCD i cristalli liquidi sono racchiusi fra due superfici vetrose provviste di numerosissimi contatti elettrici con i quali poter applicare un campo elettrico. Ogni contatto elettrico comanda una piccola porzione del pannello identificabile come un pixel.

![LCD](https://lastminuteengineers.b-cdn.net/wp-content/uploads/featuredimages/Arduino-Tutorial-for-Interfacing-I2C-LCD.webp)

# Funzionamento della task 
Questa task si occupa di stampare sul display LCD  il numero di pacchi bianchi e neri rilevati sul rullo. Dopo aver controllato il flag relativo al colore degli oggetti incrementerà solo la variabile di quel colore e le stamperà entrambe sul display.
# Descrizione del codice


	
