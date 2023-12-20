



        Ici se trouvent les codes SLAVE_PI_V2.py, SPI_PI_SLAVE.py, SPI_PI_MASTER.py ainsi que MASTER_PI_V2.py. Les deux premiers codes sont des tentatives pour communiquer en SPI avec le ESP32.
        Ils doivent afficher les trames reçues dans un terminal. Ils sont non fonctionnels parce que le Raspberry Pi ne peut pas être un slave.

        MASTER_PI_V2.py et SPI_PI_MASTER.py sont les tentatives de mettre le Pi en master.
        
        SPI_PI_MASTER.py devait transmettre 0xAA au ESP32-C3 dans l'espoir que celui-ci les reçoive et les affiche dans un terminal.

        MASTER_PI_V2.py fait la même chose à l'exception que l'utilisateur entre les données à envoyer (entre 0 et 255).

        SPI_PI_SLAVE.py devait mettre le Pi en slave pour la communication en SPI. Nous avons découvert que le Pi ne peut être qu'un master.


        SPI_PI.py et SPI_PY_AFF.py sont les tentatives de communication en SPI. Le premier doit afficher les données reçues dans un terminal.
        Le deuxième doit afficher les données reçues avec la librairie Turtle.
