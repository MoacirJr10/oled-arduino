# Projeto Arduino RFID + OLED

Este projeto usa um módulo RFID RC522 e um display OLED I2C para verificar tags RFID e mostrar no display se o acesso foi autorizado ou negado.

##Componentes
- Arduino UNO/Nano
- Módulo RFID RC522
- Display OLED 128x64 I2C
- Jumpers macho-fêmea

## Ligações

### OLED I2C
| OLED | Arduino UNO |
|------|-------------|
| VCC  | 5V          |
| GND  | GND         |
| SDA  | A4          |
| SCL  | A5          |

### RFID RC522
| RFID | Arduino UNO |
|------|-------------|
| VCC  | 3.3V        |
| GND  | GND         |
| RST  | D9          |
| SDA  | D10         |
| MOSI | D11         |
| MISO | D12         |
| SCK  | D13         |

## Código
O código está no arquivo `src/main.ino`.

## Bibliotecas Necessárias

Para rodar este projeto, você precisa instalar algumas bibliotecas no Arduino IDE:

- **Adafruit_SSD1306**
- **Adafruit_GFX**
- **MFRC522**

---

### Instalação da biblioteca MFRC522

A biblioteca MFRC522 **não está disponível diretamente no gerenciador de bibliotecas do Arduino**. Para instalá-la, siga estes passos:

1. Baixe o arquivo ZIP da biblioteca no repositório oficial no GitHub:  
   [https://github.com/miguelbalboa/rfid](https://github.com/miguelbalboa/rfid)

2. Extraia o conteúdo do arquivo ZIP.

3. Renomeie a pasta extraída para `MFRC522` (caso não esteja com este nome).

4. Imagem de Exemplo da pasta com o nome renomeado
   ![](example.png)

5. Copie essa pasta para a pasta de bibliotecas do Arduino:
    - No Windows, geralmente fica em:  
      `Documents/Arduino/libraries/`
    - No Linux/macOS, em:  
      `~/Arduino/libraries/`

6. Reinicie o Arduino IDE para que a biblioteca seja reconhecida.

---

### Outras bibliotecas usadas no projeto

As bibliotecas **Adafruit_SSD1306** e **Adafruit_GFX** podem ser instaladas diretamente pelo Gerenciador de Bibliotecas do Arduino IDE.

---

Pronto! Com isso, seu projeto poderá compilar e rodar corretamente.
