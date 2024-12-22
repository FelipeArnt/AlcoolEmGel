[README.TXT](https://github.com/FelipeArnt/HandSanitizerProject/README.md)
<h1 align="center"> HandSanitizer Project Arduino UNO</h1>

![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge)


Dispenser de alcool em gel por sensor de proximidade com Arduino UNO;

Quando o sensor detectar uma distância menor que 10 centímetros, o servo motor é ativado para "empurrar" a tampa do alcool em gel, de acordo com a potência selecionada. Existem 3 opções disponíveis que são selecionadas pelo botão na placa UNO.

## :hammer: Funcionalidades do projeto

- `Funcionalidade 1`: Ativação do motor em velocidade inicial (100,80)
- `Funcionalidade 2`: Ativação do motor em velocidade média   (100,70)
- `Funcionalidade 3`: Ativação do motor em velocidade final   (100,60)

## 📁 Acesso ao projeto

Você pode [acessar o código fonte do projeto nesse link!](https://github.com/FelipeArnt/HandSanitizerProject.git) ou [Baixá-lo](https://github.com/FelipeArnt/HandSanitizerProject/archive/refs/heads/main.zip)


## 🛠️ Abrir e rodar o projeto
- Se você estiver usando linux, pode simplesmente utilizar o comando git clone 
- Caso você tenha baixado o arquivo zip, não esqueça de extraí-lo antes de rodar o projeto!
- É necessário que você tenha instalado a versão 8 do java.
- É recomendado que seja utilizado o Visual Studio Code para rodar o projeto.
- Para achar o projeto, clique em  "Open folder" ou "Ctrl + K Ctrl + O" e procure o local onde o projeto foi instalado e extraído.


##  💻 Iniciar o projeto via Linux Terminal
- Instale as dependências necessárias --> Git, JDE & JDK :
- sudo apt install default-jre default-jdk git
- sudo pacman -Syu default-jre default-jdk git
- git clone https://github.com/FelipeArnt/HandSanitizerProject.git
- cd Diretorio
- javac *.java
- java 
