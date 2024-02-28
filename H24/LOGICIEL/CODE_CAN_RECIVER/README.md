Ici se trouve le dossier "CAN_RECIVER_ESP32" qui contient le code pour qu'un ESP32-S3 puisse recevoir des trames de donnée CAN.

Ce programme permet à un ESP32-S3 de recevoir des trames CAN provenant, dans ce cas si, d'un autre ESP32-S3.
SE PROGRAMME FONCTIONNE SEULEMENT AVEC LE TJA1050!!!!! Donc, le ESP32 lit le port série à chaque seconde.
Quand il reçoit une trame CAN, il fait passer l’ID dans un Switch/case qui va, ensuite, appeler la bonne fonction d'affichage
selon le capteur. Une vérification de la trame est faite puis on affiche la partie "data" de la trame.


* Les codes se trouvent dans le dossier "src".

* Le dossier "src" contient trois fichiers : "main.cpp", "CAN_FCT.h" et "ID_CAPT.h".

* main.cpp : Contiens la fonction "setup" et la fonction "main".

* CAN_FCT.cpp : Contiens toutes les fonctions qui seront utiles au projet (lecture de la trame CAN, vérification de la trame CAN, affichage des informations, etc.)

* CAN_FCT.h : Ce fichier d'entête contient toutes les prototype de fonctions qui seront utiles au projet (lecture de la trame CAN, vérification de la trame CAN, affichage des informations, etc.)

* ID_CAPT.h : Contiens tous les ID (qui sont temporaires dans l'immédiat) des capteurs.

* platformio.ini : Ce fichier est l'initialisation de débogueur du PlatformIO.
