DartHackaton
============


Criamos um sistema de Quiz para o DartHackaton realizado em São Paulo, na Globalcode.

Participaram desse projeto:
* Júlio Saito
* Luis Leão
* Marcio Camurati
* Rafael Brito


Demo: http://youtu.be/M5wDBLSGOlE


Criamos 4 aplicativos, sendo:
* firmware arduino e proxy serial em Processing [https://github.com/luisleao/DartHackaton]
* backend em Dart (server mode) [https://github.com/saitodisse/dartDuino2012]
* frontend em Dart (web mode) [https://github.com/saitodisse/dartDuinoClient2012]


Funcionamento:
* backend controla as perguntas e respostas, armazena a pergunta atual, conecta no proxy serial e libera uma porta para servir um arquivo json.
* frontend conecta no backend e consome um arquivo json periodicamente, exibindo a pergunta atual ou a tela de fim.
* no arduino, quando um dos três botões é pressionado, ele envia um verbete para a serial. Ele também recebe do servidor comandos para acender os leds e tocar o sino.



Veja a apresentação em:
https://docs.google.com/presentation/d/1ZQ_j91lW0FWugcmvHpicE6DiS0-_6pEebie-d_e2YhU/edit


