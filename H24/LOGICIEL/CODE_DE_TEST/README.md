#CODE_DE_TEST

## Ce qu'il contient

* CODE_CAN_RECIVER : Contient le code pour qu'un ESP32-S3 puisse recevoir des trames CAN.  (*Fonctionnel*)

* CODE_PICASO_CORRIGER_TEST_AFFICHAGE : Contient le code de test de l'affichage uLCD-32PT ( cet affichage n'est pas celui du projet, mais un pour explorer "4D Workshop 4 IDE" ). (*Désuet*)

* TEST_CAN_AFF : Contient le code pour l'affichage de l'écran qui reçoit la trame CAN. (*Fonctionnel*) 

* TEST_GFX_CAN : Contient le code pour utiliser les fonctions pour recevoir les trames CAN et les afficher sur l'écran. (*Désuet*)

* TEST_MCP_CAN_LIB: Contient le code pour utiliser le MCP2515 avec l'écran (*Désuet*) 
  
* TEST_PLUSIEUR_FICHIERS : Contient un code test pour voir s'il est possible de séparer les fonctions d'affichages dans plusieurs fichiers (EX. les mettre dans FCT_AFF.cpp et FCT_AFF.h). SPOILER : 4D Workshop n'aime pas cela... (*Désuet*)

* TEST_FPS : Contiens un code pour observer la fluidité de l'écran.

* TEST_NEW_CODE_CAN : Teste d'une nouvelle façon de traiter les trames CAN.

* TEST_MULTI_PAGE_CAN : Teste d'une facons de mettre a jour des widgets qui sont sur des pages differentes. Une meme trame CAN devrait pouvoir mettre a jour les deux widgets.

> [!CAUTION]
> Dans le Dossier `TEST_CAN_AFF`, il n'y a pas les fichiers de la carte SD. Il dépasse la limite de 100MB de Github
> 
