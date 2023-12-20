





            Ici se trouvent les codes fonctionnels pour utiliser le module CAN avec le Raspberry Pi 3B.

            
            CAN_PI_V2.py est un programme qui lit le bus CAN avec l'aide du MCP2515. Le Pi affiche les informations (ID, DLC et DATA)
            du message CAN dans un terminal. Ces messages sont lus à chaque seconde.


            PI_CAN_V2_AFF.py fait la même chose que CAN_PI_V2.py, mais, en affichant les informations du message CAN dans
            une fenêtre fait avec la librairie Turtle. Message lu à chaque 100ms.




            PI_CAN_V2_AFF_BTN.py Ajout de la lecture du bouton. Quand le bouton est pressé (GPIO 17 est à un niveau bas), la couleur
            de fond de la fenêtre devient verte. Sinon, elle est rouge.



            PI_CAN_V2_AFF_BTN_V2.py n'a qu'une seule modification : la lecture du BTN et le changement de couleur de fond de la fenêtre
            sont mis avant le "try" qui sert à lire le CAN. Le but étant de régler un problème : quand le BTN est maintenu (GPIO 17 à un niveau bas),
            la couleur de fond variait du vert au rouge quand il devrait être vert jusqu'à ce que le BTN soit relâché. Spoiler : cette
            modification n'a rien changé parce que ce problème est causé par les interruptions envoyées par le module MCP2515/TJA1050.




            PI_CAN_V2_BTN_AFF_FINAL.py est le code final du prototype. Ce code contient quelques modifications et ajouts. Maintenant,
            seule la partie DATA de la trame CAN est affichée avec l'aide de la police "Arial" et sa taille est 32. Il y a comme ajout,
            un décodeur qui permet de convertir des données en code ASCII.
