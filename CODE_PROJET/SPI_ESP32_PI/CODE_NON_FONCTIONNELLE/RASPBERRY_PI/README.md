# Contenu
* SLAVE_PI_V2.py
  tentatives pour communiquer en SPI avec le ESP32. Ils doivent afficher les trames reçues dans un terminal. Ils sont non fonctionnels parce que le Raspberry Pi ne peut pas être un slave.
* SPI_PI_SLAVE.py
  tentatives pour communiquer en SPI avec le ESP32. Ils doivent afficher les trames reçues dans un terminal. Ils sont non fonctionnels parce que le Raspberry Pi ne peut pas être un slave. mettre le Pi en slave pour la communication en SPI. Nous avons découvert que le Pi ne peut être qu'un master.
* SPI_PI_MASTER.py
  tentatives de mettre le Pi en master. transmettre 0xAA au ESP32-C3 dans l'espoir que celui-ci les reçoive et les affiche dans un terminal.
* MASTER_PI_V2.py
  tentatives de mettre le Pi en master. fait la même chose à l'exception que l'utilisateur entre les données à envoyer (entre 0 et 255).
