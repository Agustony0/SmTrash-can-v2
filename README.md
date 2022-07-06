# SmTrash-can-v2

Cuprins:<br>
  1.Ce este SmTrash-can-v2.<br>
  2.Date tehnice<br>
    2.1 Hardware<br>
  3.Inovatie<br>

1.Ce este SMTrash-can-v2
  
  Acest concept este o varianta avansată și de buget unui sistem de alarma tradițional, ținandu-te la curent cu orice ce se întâmplă în locuința ta indiferent unde te afli.
SmTrash-Can v2 este un coș de gunoi care are încorporat un senzor ultra-sonic, acesta deschizându-se automat la prezenta unei persoane. Acesta mai dispune de un "pachet de siguranță", rolul acestui pachet este de prevenirea cazurilor de inundați și incendiu. În cazul în care unul dintre senzori detectează valori corespunzătoare unui incident extrem, alarma încorporată este activată, panel-ul este update-at(site localhost) și deținătorul coșului este notificat prin Whatsapp printr-un mesaj.
  
  Features:
    -deschiderea cosului de gunoi la prezenta unei persoane
    -existenta unui panel pe reteaua locala pentru verificarea starii incintei locuintei(temperarura, umiditate)
    -sistem de prevenire in caz de incendiu si inundatie
    -notificare pe panel, WhatsApp in cazul unei anomali( incendiu si inundatie)
    -afisare temperatura
    
2.Date tehnice<br>
  2.1 Hardware<br>
    Automatizarea proiectului este făcută pe două plăci de dezvoltare, Arduino UNO și NodeMcu ESP8266. Pe arduino se colectează și calculează toate datele senzorilor și afișarea datelor pe baza input-urilor(dht11, higrometru, ultrasonic). Pe Esp8266 se afișează datele colectate de Arduino pe localhost-ul rețelei, și trimiterea de notificări prin WhatsApp, acest lucru fiind posibil folosind un api(ThingESP) de trimitere de mesaje. Senzori folosiți sunt în proximitatea cerinței utile de voltaj ai plăci de dezvoltare, însă pentru funcționarea motorului servo(cel care deschide trapa coșului de gunoi) la o capacitate optimă, am folosit un condensator electrolitic de 470 uF 16v acest rezultând funcționarea servo-ului. Inițial am folosit o sursă externă de alimentare (cum este recomandat pentru un servo) baterie de 9v, conectată la un regulator de voltaj(7805) cu două condensatoare electrolitice de 10 uf și un condensator ceramic de 22 uf pentru noise, deși circuitul este practic pentru acest caz, din cauza neexistenți de tensiune mare am renunțat la această idee și am mutat alimentarea servo-ului pe arduino.



Tehnologi folosite: <br>
-Senzori:<br>
  -dht11(senzor de umiditate si temperatura)<br>
  -higrometru(Modul senzor umiditate sol, folosit in acest proiect pentru detectarea apei)<br>
  -senzor ultra-sonic<br>
-Periferice:<br>
  -key-pad 4 buttons (input)<br>
  -LCD 16x2 (output)<br>
  -servo sg90 mini(output)<br>
  -buzzer(output)<br>
-Placi de dezvoltare<br>
  -Aduino uno<br>
  -NodeMcu ESP8266 v1<br>
  <br>
-Limbaje folosite:<br>
  -C++<br>
  -HTML/CSS<br>
  
