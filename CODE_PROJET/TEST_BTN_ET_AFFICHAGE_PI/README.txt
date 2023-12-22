




        Ici se retrouvent les codes BOUTTON.py et Turtle.py.

        Turtle.py est le programme d'exploration de la librairie Turtle. Il consiste à créer une fenêtre avec un fond rouge.
        Le programme écrit "Hello there!" puis bloque pendant 5 secondes. Le fond devient alors vert et il est écrit "BOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBO".
        Une flèche d'une longueur de cent pixels se dessine en dessous du message. Ne fait plus rien jusqu'à se que l'utilisateur clic dans la fenêtre
        pour fermer le programme.



        BOUTTON.py est le programme test pour lire un bouton avec le Pi et il utilise la librairie Turtle pour l'affichage.
        Le bouton, qui est sur le GPIO 17, est lu à chaque 100 ms. Si le GPIO est à un niveau bas (le bouton est pressé),
        le fond devient vert et il est écrit "BTN_ENFONCÉ!!!!!". Sinon, le fond est rouge et il est écrit "BTN_PAS_ENFONCÉ!!!!!"
        avant de bloquer pendant une seconde dans les deux cas. Il y a un compteur pour que le programme se ferme automatiquement.
        Ce compteur compte jusqu'à cent. Ce qui donne dix secondes.
