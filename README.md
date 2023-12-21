# PROJET FORMULE SAE AFFICHAGE (UdeS)
Le projet SAE pour UdeS Affichage

![MicrosoftTeams-image](https://github.com/FelixAntoine0708/projet_Formule_SAE_A2023/assets/89605334/e4b2d43c-1281-4deb-957f-f0b4dd0a961f)


# ***ATTENTION*** 
Les bon codes sont dans le dossier "CODE_PROJET". Sinon les codes qui se trouvent sur le github peut être un code de test qui ne fonctionne pas.

# ÉTAPE À SUIVRE POUR LE CODE DU RASPBERRY PI  
* Aller sur le dossier "CODE_PROJET"
* Aller dans le dossier "CANESP32_PI
* Aller dans le dossier "RASPBERRY_PI"
* Aller dans le dossier "FONCTIONNELLE
* Le code final est "PI_CAN_V2_AFF_BTN_FINAL"

# ÉTAPE À SUIVRE POUR LE CODE DU ESP32  
* Aller sur le dossier "CODE_PROJET"
* Aller dans le dossier "CANESP32_PI
* Aller dans le dossier "ESP32"
* Aller dans le dossier "FONCTIONNELLE"
* Le bon dossier à ouvrir dans platformIO est "ESP32_C3_TWAI"

# CODE DE CONFIGURATION DU PI  

## Étape 1: Installation des dépendances
```
sudo apt update
sudo apt install can-utils python3-full python3-pip
pip3 install python-can
```
> [!WARNING]
> Si la ligne "pip3 install python-can" vous fait une erreur utiliser la ligne suivant.
> ```
> sudo apt install python-can
> ```

## Étape 2: Activation du support CAN dans le fichier de configuration
Ouvrez le fichier **'/boot/config.txt'**. 
```
sudo nano /boot/config.txt
```
Ajouter la ligne suivant à la fin du fichier
```
dtoverlay=mcp2515-can0,oscillator=8000000,interrupt=25
```
Sauvegarder le fichier et fermer le fichier.

## Étape 3: Configuration du réseau CAN
Créer le fichier **'/etc/network/interfaces.d/can0'**
```
sudo nano /etc/network/interfaces.d/can0
```
Ajouter les lignes suivantes
```
auto can0
iface can0 can static
  bitrate 500000
  up /sbin/ip link set $IFACE txqueuelen 1000
```
Sauvegarder le fichier

## Étape 4: Activer le SPI sur le Raspberry Pi
```
sudo raspi-config
```
* Sélectionner **Interfacing Options**
* Sélectionner **SPI**
* Sélectionner **Yes** quand le demande si vous voulez activer le SPI
* Sélectionner **Finish**

## Étape 5: Redémarrage
Redémarrez votre Raspberry Pi pour les modification
