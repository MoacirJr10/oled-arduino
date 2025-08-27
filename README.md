# Projeto Arduino RFID + OLED

Este projeto usa um módulo RFID RC522 e um display OLED I2C para verificar tags RFID e mostrar no display se o acesso foi autorizado ou negado.

# 🔧 Projeto RFID + OLED Display

## 📦 Componentes Necessários

- 🔌 Arduino UNO/Nano
- 📡 Módulo RFID RC522
- 📺 Display OLED 128x64 I2C
- 🔗 Jumpers macho-fêmea

---

## 🔌 Diagrama de Conexões

```mermaid
graph TB
    subgraph "Arduino UNO"
        A_5V[5V]
        A_3V3[3.3V]
        A_GND[GND]
        A_A4[A4 - SDA]
        A_A5[A5 - SCL]
        A_D9[D9]
        A_D10[D10]
        A_D11[D11]
        A_D12[D12]
        A_D13[D13]
    end
    
    subgraph "OLED 128x64 I2C"
        O_VCC[VCC]
        O_GND[GND]
        O_SDA[SDA]
        O_SCL[SCL]
    end
    
    subgraph "RFID RC522"
        R_VCC[VCC]
        R_GND[GND]
        R_RST[RST]
        R_SDA[SDA]
        R_MOSI[MOSI]
        R_MISO[MISO]
        R_SCK[SCK]
    end
    
    %% Conexões OLED
    A_5V --> O_VCC
    A_GND --> O_GND
    A_A4 --> O_SDA
    A_A5 --> O_SCL
    
    %% Conexões RFID
    A_3V3 --> R_VCC
    A_GND --> R_GND
    A_D9 --> R_RST
    A_D10 --> R_SDA
    A_D11 --> R_MOSI
    A_D12 --> R_MISO
    A_D13 --> R_SCK
    
    classDef oled fill:#4CAF50,stroke:#2E7D32,color:#fff
    classDef rfid fill:#2196F3,stroke:#1565C0,color:#fff
    classDef arduino fill:#FF9800,stroke:#F57C00,color:#fff
    
    class O_VCC,O_GND,O_SDA,O_SCL oled
    class R_VCC,R_GND,R_RST,R_SDA,R_MOSI,R_MISO,R_SCK rfid
    class A_5V,A_3V3,A_GND,A_A4,A_A5,A_D9,A_D10,A_D11,A_D12,A_D13 arduino
```

---

## 📺 Display OLED 128x64 I2C

### 📋 Tabela de Conexões - OLED

| Pino OLED | Arduino UNO | Função | Status |
|-----------|-------------|---------|---------|
| VCC | 5V | Alimentação | ✅ Conectado |
| GND | GND | Terra | ✅ Conectado |
| SDA | A4 | Dados I2C | ✅ Conectado |
| SCL | A5 | Clock I2C | ✅ Conectado |

### 🔄 Diagrama OLED I2C

```mermaid
graph LR
    subgraph "OLED I2C"
        OLED_VCC[VCC]
        OLED_GND[GND]
        OLED_SDA[SDA]
        OLED_SCL[SCL]
    end
    
    subgraph "Arduino"
        ARD_5V[5V]
        ARD_GND[GND]
        ARD_A4[A4]
        ARD_A5[A5]
    end
    
    OLED_VCC --> ARD_5V
    OLED_GND --> ARD_GND
    OLED_SDA --> ARD_A4
    OLED_SCL --> ARD_A5
    
    classDef power fill:#FF5722,stroke:#D84315,color:#fff
    classDef signal fill:#4CAF50,stroke:#2E7D32,color:#fff
    
    class OLED_VCC,ARD_5V,OLED_GND,ARD_GND power
    class OLED_SDA,ARD_A4,OLED_SCL,ARD_A5 signal
```

---

## 📡 Módulo RFID RC522

### 📋 Tabela de Conexões - RFID

| Pino RFID | Arduino UNO | Protocolo | Função | Status |
|-----------|-------------|-----------|---------|---------|
| VCC | 3.3V | Alimentação | Tensão | ✅ Conectado |
| GND | GND | Alimentação | Terra | ✅ Conectado |
| RST | D9 | Digital | Reset | ✅ Conectado |
| SDA | D10 | SPI | Chip Select | ✅ Conectado |
| MOSI | D11 | SPI | Master Out Slave In | ✅ Conectado |
| MISO | D12 | SPI | Master In Slave Out | ✅ Conectado |
| SCK | D13 | SPI | Serial Clock | ✅ Conectado |

### 🔄 Diagrama RFID SPI

```mermaid
graph LR
    subgraph "RFID RC522"
        RFID_VCC[VCC]
        RFID_GND[GND]
        RFID_RST[RST]
        RFID_SDA[SDA/SS]
        RFID_MOSI[MOSI]
        RFID_MISO[MISO]
        RFID_SCK[SCK]
    end
    
    subgraph "Arduino"
        ARD_3V3[3.3V]
        ARD_GND2[GND]
        ARD_D9[D9]
        ARD_D10[D10]
        ARD_D11[D11]
        ARD_D12[D12]
        ARD_D13[D13]
    end
    
    RFID_VCC --> ARD_3V3
    RFID_GND --> ARD_GND2
    RFID_RST --> ARD_D9
    RFID_SDA --> ARD_D10
    RFID_MOSI --> ARD_D11
    RFID_MISO --> ARD_D12
    RFID_SCK --> ARD_D13
    
    classDef power fill:#FF5722,stroke:#D84315,color:#fff
    classDef spi fill:#2196F3,stroke:#1565C0,color:#fff
    classDef control fill:#9C27B0,stroke:#7B1FA2,color:#fff
    
    class RFID_VCC,ARD_3V3,RFID_GND,ARD_GND2 power
    class RFID_MOSI,ARD_D11,RFID_MISO,ARD_D12,RFID_SCK,ARD_D13,RFID_SDA,ARD_D10 spi
    class RFID_RST,ARD_D9 control
```

---

## ⚡ Resumo das Conexões por Protocolo

### 🔌 Alimentação
| Tensão | Destino | Pinos |
|--------|---------|--------|
| **5V** | OLED Display | VCC |
| **3.3V** | RFID RC522 | VCC |
| **GND** | Ambos | GND |

### 📶 Protocolos de Comunicação

#### I2C (OLED)
| Função | Arduino | OLED |
|--------|---------|------|
| **SDA** | A4 | SDA |
| **SCL** | A5 | SCL |

#### SPI (RFID)
| Função | Arduino | RFID | Descrição |
|--------|---------|------|-----------|
| **SS** | D10 | SDA | Chip Select |
| **MOSI** | D11 | MOSI | Master → Slave |
| **MISO** | D12 | MISO | Slave → Master |
| **SCK** | D13 | SCK | Clock |
| **RST** | D9 | RST | Reset |

---

## ⚠️ Observações Importantes

> **💡 Tensão de Alimentação:**
> - OLED: 5V (compatível com lógica 5V)
> - RFID: 3.3V (importante para não danificar o módulo)

> **🔧 Protocolos:**
> - OLED usa comunicação I2C (2 fios)
> - RFID usa comunicação SPI (4 fios + reset)

> **📱 Endereço I2C padrão do OLED:** 0x3C ou 0x3D

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
