# TAREFA SOBRE PWM : Controle de servo motor por PWM

Esta tarefa foi proposta para consolidar os conceitos visto na aula síncrona sobre **PWM**

## 📋DESCRIÇÃO

Nesta tarefa deve ser implementado um sistema para simular o controle do ângulo de um servomotor, com o emprego do **módulo PWM** presente no microcontrolador **RP2040** e utilizando a ferramenta **Pico SDK**.
Para condução dessa prática, será necessário utilizar os componentes listados abaixo:

 - Microcontrolador Raspberry Pi Pico W.
 - Servomotor - motor micro servo padrão.

## OBJETIVOS

 - Compreender o funcionamento e aplicações de sinais PWM
 - Aplicar os conhecimentos adquiridos nas aulas síncronas sobre PWM na prática;
 - Controlar motores por sinais PWM

 ## ✨ FUNCIONALIDADES

1. Considerando a GPIO 22, difinir sua frequência de PWM para 50Hz.

2. Em seguida, definir o ciclo ativo do modulo PWM para 2.400µs – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto
ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus. Aguarde 05 segundos nesta posição.

3. Definir o ciclo ativo do módulo PWM para 1.470µs – Ciclo de Trabalho (Duty Cycle) de 0,0735%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus. Aguarde 05 segundos nesta posição.

4. Definir o ciclo ativo do módulo PWM para 500µs – Ciclo de Trabalho (Duty Cycle) de 0,025%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus. Aguarde 05 segundos nesta posição.

5. Após esse ciclo anterior, criar uma rotinapara movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.

## USO SO PROGRAMA
    - Necessário ter o vscode configurado para raspberry pi pico w e wokwi corretamente.
    - Ter os componentes necessários para executar o projeto.
    - Clonar o repositório ou baixar os arquivos do repositório.
    - Abrir o vscode e importar o projeto que foi clonado ou baixado.
    - Compilar.
    - Executar.


## 🎥 VIDEO DE DEMONSTRAÇÃO

Confira o funcionamento do projeto no link abaixo

[📹 Ver vídeo de demonstração](https://drive.google.com/file/d/1esB228-cevEaFmxPCWTQJe9RYxTKQdF6/view?usp=sharing)