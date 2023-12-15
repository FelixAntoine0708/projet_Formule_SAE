# PROJET FORMULE SAE
Le projet SAE pour UdeS Affichage

![MicrosoftTeams-image](https://github.com/FelixAntoine0708/projet_Formule_SAE_A2023/assets/89605334/e4b2d43c-1281-4deb-957f-f0b4dd0a961f)


# ***Attention*** 
Tout code qui se trouve dedans peut être un code de test qui ne fonctionne pas toujours. Liser bien la description

# ÉTAPE À SUIVRE POUR LE CODE
1- Aller sur le dossier "CODE_PROJET"
2-

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
