#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definição dos pinos e variáveis
#define servo_pin 22
#define freq_pwm 50
#define wrap_pwm 65535      // Máximo valor do contador PWM 

// Função para configurar o PWM
void setup_pwm(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM); // Define GPIO como PWM
    uint slice_num = pwm_gpio_to_slice_num(gpio); // Obtém o número do slice PWM

    // Configura o PWM com clock divisor para obter 50Hz
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 38.147); // Ajuste para frequência correta
    pwm_config_set_wrap(&config, wrap_pwm);
    pwm_init(slice_num, &config, true); // Inicia o PWM
}

// Função para definir o pulso do motor servo em us
void set_servo_pulse(uint gpio, uint pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    
    // Converte o tempo de pulso para nível PWM baseado no wrap de 65535
    uint level = (pulse_width_us * wrap_pwm) / 20000;
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), level);
}

// Função para primeira rotina a ser execultada
void routine(){
    // Virando para 180 graus
    printf("Posição: 180 graus\n");
    set_servo_pulse(servo_pin, 2400);   // 2400 us
    sleep_ms(5000);     // delay de 5 segundos

    // virando para 90 graus
    printf("Posição: 90 graus\n");
    set_servo_pulse(servo_pin, 1470);   // 1470 us
    sleep_ms(5000);

    // virando para 0 graus
    printf("Posição: 0 graus\n");
    set_servo_pulse(servo_pin, 500);   // 500 us
    sleep_ms(5000);
}

int main() {
    stdio_init_all();

    // Inicializando a porta pwm
    setup_pwm(servo_pin);
    
    // chamando a primeira rotina
    routine();

    while (true) {

        // Movimento suave entre 180 e 0
        printf("Movendo de 0 para 180\n");
        for(uint pulse = 500; pulse <= 2400; pulse += 5){
            set_servo_pulse(servo_pin, pulse);
            sleep_ms(10);
        }

        printf("Movendo de 180 para 0\n");
        for(uint pulse = 2400; pulse >= 500; pulse -= 5){
            set_servo_pulse(servo_pin, pulse);
            sleep_ms(10);
        }
    }
}
