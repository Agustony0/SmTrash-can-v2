# SmTrash-can-v2

Cuprins:
  1.Ce este SmTrash-can-v2.<br>
  2.Date tehnice<br>
    2.1 Hardware<br>
    2.2 Software<br>
  3.Inovatie<br>

1.Ce este SMTrash-can-v2
  
  SMTrash-can-v2 este un cos de gunoi care are incorporat un senzor ultra-sonic, acesta deschindanduse autoamt la prezenta unei persoane. Acesta mai dispune de un "pachet de siguranta", rolul acestui pachet este de prevenire in cazurile de inuntati si incendiu. In cazul in care unul dintre senzori detecteaza valori corespunzatore unui incident exterm, alarma incorporata este activata, panel-ul este updatat, si detinatorul cosului de gunoi este notificat prin WhatsApp.
  
  Features:
    -deschiderea cosului de gunoi la prezenta unei persoane
    -existenta unui panel pe reteaua locala pentru verificarea starii incintei locuintei(temperarura, umiditate)
    -sistem de prevenire in caz de incendiu si inundatie
    -notificare pe panel, WhatsApp in cazul unei anomali( incendiu si inundatie)
    
2.Date tehnice
  2.1 Hardware
    Automatizarea proiectului este facuta pe doua placi de dezvoltare, Arduino UNO si NodeMcu ESP8266. Pe arduino se colecteaza si calculeaza toate datele senzorilor si afisarea datelor pe baza inputurilor(dht11, higrometru, ultrasonic). Pe Esp8266 se afiseaza datele colectate de Arduino pe localhostul retelei, si trimiterea de notificari prin WhatsApp, acest lucru fiind posibil folosind un api(ThingESP) de trimitere de mesaje. Senzori folositi sunt in proximitatea cerintei utile de voltaj ai placi de dezoltare, insa pentru functionarea motirului servo(cel care deschide trapa cosului de gunoi) la o capacitate optima, am folosit un capacitor electrolitic de 470 uF 16v acest rezultand functionarea servo-ului. Initial am folosit o sursa externa de alimentae (cum este recomandat pentru un servo) baterie de 9v, conectata la un regulator de voltaj(7805) cu doua condensatoare eclecrtolitice de 10 uf si un condensator ceramic de 22 uf pentru noise, desi circuitul este practic pentru acest caz, din cauza neexistenti de tensine mare am renuntat la aceasta idee si am mutat alimentaea servoului pe arduino.
 2.2 SoftWare
   Algoritmica din spatele acstui proiect este predominant de decizionalele.
      
  

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
  
